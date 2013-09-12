/* IMAGE_DOS_HEADER
 *
 * 
 */

#ifndef _PENETRA_DOS_H_
#define _PENETRA_DOS_H_

#include "types.h"

PENETRA_BEGIN_DECLS

typedef struct {
	_u16 e_magic;		/* IMAGE_DOS_SIGNATURE "MZ" */
	_u16 e_cblp;
	_u16 e_cp;
	_u16 e_crlc;
	_u16 e_cparhdr;
	_u16 e_minalloc;
	_u16 e_maxalloc;
	_u16 e_ss;
	_u16 e_sp;
	_u16 e_csum;
	_u16 e_ip;
	_u16 e_cs;
	_u16 e_lfarlc;
	_u16 e_ovno;
	_u16 e_res[4];
	_u16 e_oemid;
	_u16 e_oeminfo;
	_u16 e_res2[10];
	_i32 e_lfanew;		/* offset of the PE header */
} PenetraDos;


/* Get Image dos Signature, MZ.
 *
 * @param dos A valid PenetraDos object.
 * @param buffer The allocated buffer to store the signature
 * @param len Number of bytes to be copied.
 * 
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_signature(PenetraDos *dos, char *buffer, _u32 len);


/* Get Image dos Signature, MZ.
 *
 * @param dos A valid PenetraDos object.
 * @param buffer The allocated buffer to store the signature
 * @param len Number of bytes to be copied.
 * 
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_e_magic(PenetraDos *dos, char *buffer, _u32 len);


/* Get field e_elfnew, the PE Header offset.
 *
 * @param dos A valid PenetraDos object.
 * @param offset Stored PE Header offset.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_e_lfanew(PenetraDos *dos, _i32 *offset);


PENETRA_END_DECLS


#endif /* _PENETRA_DOS_H_ */
