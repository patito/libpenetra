#include <stdio.h>
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

static _u32 _penetra_load_dos(Penetra *pen)
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == pen->mem) {
		return PENETRA_EFAULT;
	}
	pen->dos = (PenetraDos *) pen->mem;
	
	return PENETRA_SUCCESS;
}


static _u32 _penetra_load_nt(Penetra *pen)
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == pen->mem) {
		return PENETRA_EFAULT;
	}

	if (NULL == pen->dos) {
		return PENETRA_EFAULT;
	}

	pen->nt = (PenetraNT *) (pen->mem + pen->dos->e_lfanew);
	
	return PENETRA_SUCCESS;
}

/*
static _u32 _penetra_load_coff(Penetra *pen)
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == pen->mem) {
		return PENETRA_EFAULT;
	}

	if (NULL == pen->dos) {
		return PENETRA_EFAULT;
	}

	pen->coff = (PenetraCoff *) (pen->mem +  
								 pen->dos->e_lfanew + 
								 SIZEOF_NT_SIGNATURE);
	
	return PENETRA_SUCCESS;
}

static _u32 _penetra_load_optional(Penetra *pen)
{
	_u16 arch;

	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == pen->mem) {
		return PENETRA_EFAULT;
	}

	if (NULL == pen->dos) {
		return PENETRA_EFAULT;
	}

	//arch = (pen->mem + pen->dos->e_lfanew + 0x18);


	memcpy(&arch, (pen->mem + pen->dos->e_lfanew + 0x18), 2);
	
	printf("%#x\n",  arch);
	
	return PENETRA_SUCCESS;
}



static _u32 _penetra_get_nt_signature(Penetra *pen, _u8 **sig)
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == pen->mem) {
		return PENETRA_EFAULT;
	}

	if (NULL == pen->dos) {
		return PENETRA_EFAULT;
	}

	*sig = (pen->mem + pen->dos->e_lfanew);
	
	return PENETRA_SUCCESS;
}*/

static _u32 _penetra_dealloc(Penetra *pen)
{
	_i32 error = PENETRA_SUCCESS;

	if (NULL == pen) {
		return PENETRA_EINVAL;
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
		return PENETRA_EINVAL;
	}

	if (NULL == fname) {
		return PENETRA_EINVAL;
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
		pen->fname = NULL;
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
		return PENETRA_EINVAL;
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
	_i16 n = 0;
	_u32 i = 0;

	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	pen->mem = malloc(pen->size * sizeof(_u8));
	if (NULL == pen->mem) {
		return PENETRA_EALLOC;
	}

	while ((n = read(pen->fd, pen->mem + i, 1)) > 0 && ++i);

	if (-1 == n) {
		_i32 error = errno;
		return error;
	}

	return PENETRA_SUCCESS;
}

static _u32 _penetra_load(Penetra *pen)
{
	_i32 error = PENETRA_SUCCESS;

	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (PENETRA_ALLOC_MMAP == pen->alloc_type) {
		error = _penetra_load_mmap(pen);
		if (PENETRA_SUCCESS != error) {
			return error;
		}
	} else if (PENETRA_ALLOC_MALLOC == pen->alloc_type) {
		error = _penetra_load_malloc(pen);
		if (PENETRA_SUCCESS != error) {
			return error;
		}
	}

	if (PENETRA_SUCCESS != error) {
		return error;
	}
	
	error = _penetra_load_dos(pen);
	if (PENETRA_SUCCESS != error) {
		return error;
	}

	error = _penetra_load_nt(pen);
	if (PENETRA_SUCCESS != error) {
		return error;
	}

/*	error = _penetra_load_coff(pen);
	if (PENETRA_SUCCESS != error) {
		return error;
	}

	error = _penetra_load_optional(pen);
	if (PENETRA_SUCCESS != error) {
		return error;
	}
*/
	return error;
}


/* Public Methods */

_u32 penetra_init(Penetra *pen)
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
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

	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == fname) {
		return PENETRA_EINVAL;
	}
	
	status = penetra_set_alloc_type(pen, PENETRA_ALLOC_MMAP);
	if (PENETRA_SUCCESS != status) {
		return status;
	} 
	
	status = penetra_open(pen, fname);
	if (PENETRA_SUCCESS != status) {
		return status;
	} 

	return PENETRA_SUCCESS;
}

_u32 penetra_open_malloc(Penetra *pen, const char *fname)
{
	_u32 status = PENETRA_ERROR;

	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == fname) {
		return PENETRA_EINVAL;
	}
	
	status = penetra_set_alloc_type(pen, PENETRA_ALLOC_MALLOC);
	if (PENETRA_SUCCESS != status) {
		return status;
	} 

	status = penetra_open(pen, fname);
	if (PENETRA_SUCCESS != status) {
		return status;
	}

	return PENETRA_SUCCESS; 
}

_u32 penetra_open(Penetra *pen, const char *fname)
{
	_i32 error;

	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == fname) {
		return PENETRA_EINVAL;
	}

	error = _penetra_open_file(pen, fname);
	if (PENETRA_SUCCESS != error) {
		return error;
	}

	if ((PENETRA_ALLOC_MMAP != pen->alloc_type) &&
		(PENETRA_ALLOC_MALLOC != pen->alloc_type)) {
		return PENETRA_EINVAL;
	} 
	
	return _penetra_load(pen);		
}

_u32 penetra_finish(Penetra *pen)
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	return _penetra_dealloc(pen);
}

_u32 penetra_set_alloc_type(Penetra *pen, _u8 alloc_type)
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if ((PENETRA_ALLOC_MMAP != alloc_type) &&
        (PENETRA_ALLOC_MALLOC != alloc_type)) {
		return PENETRA_EINVAL;
    }

	pen->alloc_type = alloc_type;	

	return PENETRA_SUCCESS;
}

_u32 penetra_get_alloc_type(Penetra *pen, _u8 *alloc_type)
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	*alloc_type = pen->alloc_type;

	return PENETRA_SUCCESS;
}

_u32 penetra_is_pe(Penetra *pen)
{
	_i32 error;

	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == pen->mem) {
		return PENETRA_EFAULT;
	}

	/* First two bytes are "MZ" or 0x5a4d  */
	error =	memcmp(IMAGE_DOS_SIGNATURE, pen->mem, 2);
	if (-1 == error) {
		return PENETRA_ENOT_PE;
	}

	/* Checking NT signature PE00 */
	/*_u8 *sig = NULL;
	_penetra_get_nt_signature(pen, &sig);
	if (NULL == sig) {
		return PENETRA_EFAULT;
	}

	if (0 != strncmp((char*)sig, "PE", 2)) {
		return PENETRA_ENOT_PE;
	}*/

	return PENETRA_SUCCESS;
}

_u32 penetra_get_dos(Penetra *pen, PenetraDos **dos)
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	*dos = pen->dos;

	return PENETRA_SUCCESS;
}

/*_u32 penetra_get_coff(Penetra *pen, PenetraCoff **coff)
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == coff) {
		return PENETRA_EINVAL;
	}

	*coff = pen->coff;

	return PENETRA_SUCCESS;
}

static _u32 _penetra_get_optional32(Penetra *pen, PenetraOptional32 **opt)
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == opt) {
		return PENETRA_EINVAL;
	}

	*opt = pen->opt->opt32;

	return PENETRA_SUCCESS;
}

static _u32 _penetra_get_optional64(Penetra *pen, PenetraOptional64 **opt)
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == opt) {
		return PENETRA_EINVAL;
	}

	*opt = pen->opt->opt64;

	return PENETRA_SUCCESS;
}*/

_u32 penetra_get_arch(Penetra *pen, _u8 **arch)
{

	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == pen->mem) {
		return PENETRA_EFAULT;
	}

	if (NULL == pen->dos) {
		return PENETRA_EFAULT;
	}

	*arch = (pen->mem + pen->dos->e_lfanew + 0x18);

	//memcpy(arch, (pen->mem + pen->dos->e_lfanew + 0x18), 2);

	//printf("%");

	return PENETRA_SUCCESS;
}



