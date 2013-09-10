#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

/* libpenetra */
#include <penetra/penetra.h>

/* Private Methods _ */

static _u32 _penetra_dealloc(Penetra *pen)
{
	_i32 error = PENETRA_SUCCESS;

	if (NULL == pen) {
		return PENETRA_ERROR;
	}

	if (-1 != pen->fd) {
		close(pen->fd);
	}
	
	if (NULL != pen->fname) {
		free(pen->fname);
	}

	if (PENETRA_ALLOC_MALLOC == pen->alloc_type) {
		if (NULL != pen->mem) {
			free(pen->mem);
		}
	} else if (PENETRA_ALLOC_MMAP == pen->alloc_type) {
		if (-1 == munmap(pen->mem, pen->size)) {
			error = errno;
		}
    }

	return error;
}

static _i32 _penetra_open_file(Penetra *pen, const char *fname)
{
	_i32 error;
	struct stat st_info;

	if (NULL == pen) {
		return PENETRA_ERROR;
	}

	if (NULL == fname) {
		return PENETRA_ERROR;
	}

	pen->fname = strdup(fname);
	if (NULL == pen->fname) {
		error = errno;
		goto _fail;
	}

	pen->fd = open(fname, O_RDONLY);
	if (-1 == pen->fd) {
		error = errno;
		goto _fail;
	}

	if (-1 == fstat(pen->fd, &st_info)) {
		error = errno;
		goto _fail;
	}

	if (0 == st_info.st_size) {
		error = PENETRA_EEMPTY_FILE;
	}

	pen->size = st_info.st_size;

	return PENETRA_SUCCESS;

_fail:
	if (NULL != pen->fname) {
		free(pen->fname);
	}

	if (-1 != pen->fd) {
		close(pen->fd);
	}
	
	return error;
}

static _u32 _penetra_load_mmap(Penetra *pen)
{
	_i32 error;

	if (NULL == pen) {
		return PENETRA_ERROR;
	}

	pen->mem = mmap(0, pen->size, PROT_READ|PROT_WRITE, MAP_PRIVATE, pen->fd, 0);
	if (MAP_FAILED == pen->mem) {
    	error = errno;
		return error;
	}

	return PENETRA_SUCCESS;
}

static _u32 _penetra_load_malloc(Penetra *pen)
{
	if (NULL == pen) {
		return PENETRA_ERROR;
	}
	return PENETRA_ERROR;
}

static _u32 _penetra_load(Penetra *pen)
{
	_i32 error;

	if (NULL == pen) {
		return PENETRA_ERROR;
	}

	if (PENETRA_ALLOC_MMAP == pen->alloc_type) {
		error = _penetra_load_mmap(pen);
	} else if (PENETRA_ALLOC_MALLOC == pen->alloc_type) {
		error = _penetra_load_malloc(pen);
	}

	return error;
}


/* Public Methods */

_u32 penetra_init(Penetra *pen)
{
	if (NULL == pen) {
		return PENETRA_ERROR;
	}

	pen->fd = -1;
	pen->alloc_type = PENETRA_ALLOC_MMAP;
	pen->size = 0;
	pen->mem = NULL;
	pen->fname = NULL;

	return PENETRA_SUCCESS;
}


_u32 penetra_open_mmap(Penetra *pen, const char *fname)
{
	_u32 status = PENETRA_ERROR;
	
	status = penetra_set_alloc_type(pen, PENETRA_ALLOC_MMAP);
	if (status != PENETRA_SUCCESS) {
		return status;
	} 
	
	status = penetra_open(pen, fname);
	if (status != PENETRA_SUCCESS) {
		return status;
	} 

	return PENETRA_SUCCESS;
}

_u32 penetra_open_malloc(Penetra *pen, const char *fname)
{
	_u32 status = PENETRA_ERROR;

	status = penetra_set_alloc_type(pen, PENETRA_ALLOC_MALLOC);
	if (status != PENETRA_SUCCESS) {
		return status;
	} 

	status = penetra_open(pen, fname);
	if (status != PENETRA_SUCCESS) {
		return status;
	}

	return PENETRA_SUCCESS; 
}

_u32 penetra_open(Penetra *pen, const char *fname)
{
	_i32 error;

	if (NULL == pen) {
		return PENETRA_ERROR;
	}

	if (NULL == fname) {
		return PENETRA_ERROR;
	}

	error = _penetra_open_file(pen, fname);
	if (PENETRA_SUCCESS != error) {
		return error;
	}

	if ((PENETRA_ALLOC_MMAP != pen->alloc_type) &&
		(PENETRA_ALLOC_MALLOC != pen->alloc_type)) {
		return PENETRA_ERROR;
	} 
	
	return _penetra_load(pen);		
}

_u32 penetra_finish(Penetra *pen)
{
	if (NULL == pen) {
		return PENETRA_ERROR;
	}

	return _penetra_dealloc(pen);
}

_u32 penetra_set_alloc_type(Penetra *pen, _u8 alloc_type)
{
	if (NULL == pen) {
		return PENETRA_ERROR;
	}

	if ((PENETRA_ALLOC_MMAP != alloc_type) ||
        (PENETRA_ALLOC_MALLOC != alloc_type)) {
			return PENETRA_ERROR;
    }

	pen->alloc_type = alloc_type;	

	return PENETRA_SUCCESS;
}

_u32 penetra_get_alloc_type(Penetra *pen, _u8 *alloc_type)
{
	if (NULL == pen) {
		return PENETRA_ERROR;
	}

	*alloc_type = pen->alloc_type;

	return PENETRA_SUCCESS;
}



