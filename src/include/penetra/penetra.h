#ifndef _PENETRA_H_
#define _PENETRA_H_

#include <stdbool.h>

#include "defines.h"
#include "error.h"
#include "types.h"
#include "dos.h"


PENETRA_BEGIN_DECLS


typedef struct {
	_i32 fd;			/* Binary file descriptor */
	_u32 size;			/* The binary size */
	char *fname;		/* binary file name */
	_u8 alloc_type;		/* Alloc type: mmap or malloc */
	_u8 *mem;			/* Loaded binary */
	PenetraDos *dos; 	/* IMAGE_DOS_HEADER */
} Penetra;


/* Initialize PE object (struct Penetra) 
 *
 * @param pen A valid Penetra object.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_init(Penetra *pen);


/* Open the file name and load the PE binary to memory. To load
 * binary file to the memory mmap functions is used by default,
 * but you can change using penetra_set_alloc_type() or 
 * penetra_open_malloc(). The libpenetra provides two ways of
 * load: PENETRA_ALLOC_MMAP and PENETRA_ALLOC_MALLOC.
 *
 * @param pen A valid Penetra object.
 * @param fname A valid binary filename. Example: /tmp/putty.exe
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_open(Penetra *pen, const char *fname);


/* Open and load binary file using mmap() function.
 *
 * @param pen A valid Penetra object.
 * @param fname A valid binary filename. Example: /tmp/putty.exe
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_open_mmap(Penetra *pen, const char *fname);


/* Open and load binary file using malloc() function.
 *
 * @param pen A valid Penetra object.
 * @param fname A valid binary filename. Example: /tmp/putty.exe
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_open_malloc(Penetra *pen, const char *fname);


/* Release PE object (struct Penetra) 
 *
 * @param pen A valid Penetra object.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_finish(Penetra *pen);


/* Verify if the binary file is a Portable Executable (PE).
 *
 * @param pen A valid Penetra object.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_is_pe(Penetra *pen);


/****************************************************************************** 
 ********************************** GETTERS *********************************** 
 *****************************************************************************/ 


/* Get the alloc type.
 *
 * @param pen A valid Penetra object.
 * @param alloc_type Saved alloc type.
 * 
 *  { ... } 
 *  _u8 atype;
 *  Penetra pen;
 *  penetra_get_alloc_type(&pen, &atype);
 *  { ... }
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_get_alloc_type(Penetra *pen, _u8 *alloc_type);


/* Get IMAGE_DOS_HEADER address.
 *
 * @param pen A valid Penetra object.
 * @param dos A valid PenetraDos object.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_get_dos(Penetra *pen, PenetraDos **dos);


/****************************************************************************** 
 ********************************** SETTERS *********************************** 
 *****************************************************************************/ 


/* Set the alloc type.
 *
 * @param pen A valid Penetra object.
 * @param alloc_type The allocation type to be used.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_set_alloc_type(Penetra *pen, _u8 alloc_type);


PENETRA_END_DECLS

#endif /* _PENETRA_H_ */
