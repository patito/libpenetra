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

#ifndef _PENETRA_ERROR_H_
#define _PENETRA_ERROR_H_

#include "defines.h"

PENETRA_BEGIN_DECLS

#define MAX_MSG_ERROR 255

typedef enum {
	PENETRA_SUCCESS		= 0,
	PENETRA_EPERM		= 1,	/*  Operation not permitted */
	PENETRA_ENOENT		= 2,	/*  No such file or directory */
	PENETRA_ESRCH		= 3,	/*  No such process */
	PENETRA_EINTR		= 4,	/*  Interrupted system call */
	PENETRA_EIO			= 5,	/*  I/O error */
	PENETRA_ENXIO		= 6,	/*  No such device or address */
	PENETRA_E2BIG		= 7,	/*  Argument list too long */
	PENETRA_ENOEXEC		= 8,	/*  Exec format error */
	PENETRA_EBADF		= 9,	/*  Bad file number */
	PENETRA_ECHILD		= 10,	/*  No child processes */
	PENETRA_EAGAIN		= 11,	/*  Try again */
	PENETRA_ENOMEM		= 12,	/*  Out of memory */
	PENETRA_EACCES		= 13,	/*  Permission denied */
	PENETRA_EFAULT		= 14,	/*  Bad address */
	PENETRA_ENOTBLK		= 15,	/*  Block device required */
	PENETRA_EBUSY		= 16,	/*  Device or resource busy */
	PENETRA_EEXIST		= 17,	/*  File exists */
	PENETRA_EXDEV		= 18,	/*  Cross-device link */
	PENETRA_ENODEV		= 19,	/*  No such device */
	PENETRA_ENOTDIR		= 20,	/*  Not a directory */
	PENETRA_EISDIR		= 21,	/*  Is a directory */
	PENETRA_EINVAL		= 22,	/*  Invalid argument */
	PENETRA_ENFILE		= 23,	/*  File table overflow */
	PENETRA_EMFILE		= 24,	/*  Too many open files */
	PENETRA_ENOTTY		= 25,	/*  Not a typewriter */
	PENETRA_ETXTBSY		= 26,	/*  Text file busy */
	PENETRA_EFBIG		= 27,	/*  File too large */
	PENETRA_ENOSPC		= 28,	/*  No space left on device */
	PENETRA_ESPIPE		= 29,	/*  Illegal seek */
	PENETRA_EROFS		= 30,	/*  Read-only file system */
	PENETRA_EMLINK		= 31,	/*  Too many links */
	PENETRA_EPIPE		= 32,	/*  Broken pipe */
	PENETRA_EDOM		= 33,	/*  Math argument out of domain of func */
	PENETRA_ERANGE		= 34,	/*  Math result not representable */
	PENETRA_LAST_ERRNO	= 35,
	PENETRA_ERROR		= 40,
	PENETRA_ECLOSED		= 41,
	PENETRA_EALLOC		= 42,
	PENETRA_ENOT_PE		= 43,
	PENETRA_ECORRUPTED	= 44,
	PENETRA_ESUSPECT_SECTIONS		= 45,
	PENETRA_EMISSING_MAGIC_BYTES	= 46,
	PENETRA_EINV_OFFSET_ENTRY		= 47,
	PENETRA_EDISAS					= 48,
	PENETRA_EEMPTY_FILE				= 49,
	PENETRA_EEHDR_OVERFLOW			= 50,
	PENETRA_EINVALID_CLASS			= 51,
	PENETRA_EUNKNOWN_ALLOC_TYPE		= 52,
	PENETRA_EFILE_EXISTS			= 53,
	PENETRA_ETEXT_SEG_NOT_FOUND		= 54,
	PENETRA_ENOT_ALLOC_MALLOC		= 55,
	PENETRA_ESHSTRNDX_CORRUPTED		= 56,
	PENETRA_ESHSTRTAB_OFFSET_OUT_OF_RANGE = 57,
	PENETRA_ESECTION_NOT_FOUND		= 58,
	PENETRA_LAST_ERROR				= 59,
    PENETRA_EINVALID_ARCH			= 60
} PenetraStatus;


PENETRA_BEGIN_DECLS

#endif
