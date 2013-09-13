#ifndef _PENETRA_DEFINES_H_
#define _PENETRA_DEFINES_H_

#ifdef __cplusplus
# define PENETRA_BEGIN_DECLS extern "C" {
# define PENETRA_END_DECLS }
#else
# define PENETRA_BEGIN_DECLS /*  empty */
# define PENETRA_END_DECLS /*  empty */
#endif


/*  Unused variables */
#define UNUSED(x) (void)x


/* Alloc Type */
#define PENETRA_ALLOC_NONE 	0
#define PENETRA_ALLOC_MMAP 	1
#define PENETRA_ALLOC_MALLOC 2


/* MZ - The first 2 Bytes of PE */
#define IMAGE_DOS_SIGNATURE "MZ"

/* NT SIGNATURE "PE00" */
#define SIZEOF_NT_SIGNATURE 4

#endif /* _PENETRA_DEFINES_H_ */
