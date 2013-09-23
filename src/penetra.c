/*
 * The libpenetra is a library that could be used to access all PE
 * (Portable Executable) information. It was developed to provide 
 * a safe way to analyze malwares in PE binaries.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

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

static _u32 _penetra_set_arch32(Penetra *pen) 
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	pen->nt.unt.nt32 = (PenetraNT32*) (pen->mem + pen->dos->lfanew);
	pen->arch = PE_ARCH32;
	pen->nt.arch = PE_ARCH32;

	return PENETRA_SUCCESS;
}

static _u32 _penetra_set_arch64(Penetra *pen) 
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	pen->nt.unt.nt64 = (PenetraNT64*) (pen->mem + pen->dos->lfanew);
	pen->arch = PE_ARCH64;
	pen->nt.arch = PE_ARCH64;

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
	
	_penetra_set_arch32(pen);

    if (PE_ARCH64 == pen->nt.unt.nt32->opt.magic) {
		_penetra_set_arch64(pen);
	}

	return PENETRA_SUCCESS;
}

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
	pen->dos = NULL;
	pen->nt.unt.nt32 = NULL;
	pen->nt.unt.nt64 = NULL;

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
	_u16 sig = 0;
	_u16 mz = 0;

	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == pen->mem) {
		return PENETRA_EFAULT;
	}

	/* First two bytes are "MZ" or 0x5a4d  */
	penetra_dos_get_signature(pen->dos, &mz);
	if (MZ_SIGNATURE != mz) {
		return PENETRA_ENOT_PE;
	}

	/* Checking NT signature PE00 0x4550 */
	penetra_nt_get_signature(&pen->nt, &sig);
	if (NT_SIGNATURE != sig) {
		return PENETRA_ENOT_PE;
	}

	return PENETRA_SUCCESS;
}

_u32 penetra_get_dos(Penetra *pen, PenetraDos *dos)
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	*dos = *pen->dos;

	return PENETRA_SUCCESS;
}

_u32 penetra_get_nt(Penetra *pen, PenetraNT *nt)
{
	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == nt) {
		return PENETRA_EINVAL;
	}

	switch (pen->arch) {
		case PE_ARCH32:
			*nt = pen->nt;
			break;
		case PE_ARCH64:
			*nt = pen->nt;
			break;
		default: 
			return PENETRA_EINVALID_ARCH;
	}

	return PENETRA_SUCCESS;
}

_u32 penetra_get_arch(Penetra *pen, _u16 *arch)
{

	if (NULL == pen) {
		return PENETRA_EINVAL;
	}

	if (NULL == pen->mem) {
		return PENETRA_EFAULT;
	}

	*arch = pen->arch;	

	return PENETRA_SUCCESS;
}



