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
 * @param signature Saved signature address.
 * 
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_signature(PenetraDos *dos, char **signature);


/* Get Image dos Signature, MZ.
 *
 * @param dos A valid PenetraDos object.
 * @param signature Saved signature address.
 * 
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_magic(PenetraDos *dos, char **signature);


/* Get field e_elfnew, the PE Header offset.
 *
 * @param dos A valid PenetraDos object.
 * @param offset Stored PE Header offset.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_lfanew(PenetraDos *dos, _i32 *offset);


/* Get field e_cblp, that stores the number of bytes on last page of file.
 *
 * @param dos A valid PenetraDos object.
 * @param cblp Saved the number of bytes on last page of file.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_cblp(PenetraDos *dos, _u16 *cblp);


/* Get field e_cp, that stores the number of 512 byte pages in the file
 *
 * @param dos A valid PenetraDos object.
 * @param cp Saved the number of pages in file.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_cp(PenetraDos *dos, _u16 *cp);


/* Get field e_crlc, relocations.
 *
 * @param dos A valid PenetraDos object.
 * @param crlc Saved relocations.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_crlc(PenetraDos *dos, _u16 *crlc);


/* Get field e_
 *
 * @param dos A valid PenetraDos object.
 * @param 
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_cparhdr(PenetraDos *dos, _u16 *cparhdr);


/* Get field e_
 *
 * @param dos A valid PenetraDos object.
 * @param 
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_minalloc(PenetraDos *dos, _u16 *minalloc);


/* Get field e_
 *
 * @param dos A valid PenetraDos object.
 * @param 
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_maxalloc(PenetraDos *dos, _u16 *maxalloc);


/* Get field e_
 *
 * @param dos A valid PenetraDos object.
 * @param 
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_ss(PenetraDos *dos, _u16 *ss);


/* Get field e_
 *
 * @param dos A valid PenetraDos object.
 * @param 
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_sp(PenetraDos *dos, _u16 *sp);


/* Get field e_
 *
 * @param dos A valid PenetraDos object.
 * @param 
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_csum(PenetraDos *dos, _u16 *csum);


/* Get field e_
 *
 * @param dos A valid PenetraDos object.
 * @param 
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_ip(PenetraDos *dos, _u16 *ip);


/* Get field e_
 *
 * @param dos A valid PenetraDos object.
 * @param 
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_cs(PenetraDos *dos, _u16 *cs);


/* Get field e_
 *
 * @param dos A valid PenetraDos object.
 * @param 
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_lfarlc(PenetraDos *dos, _u16 *lfarlc);


/* Get field e_
 *
 * @param dos A valid PenetraDos object.
 * @param 
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_ovno(PenetraDos *dos, _u16 *ovno);


/* Get field e_
 *
 * @param dos A valid PenetraDos object.
 * @param 
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_oemid(PenetraDos *dos, _u16 *oemid);


/* Get field e_
 *
 * @param dos A valid PenetraDos object.
 * @param 
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_oeminfo(PenetraDos *dos, _u16 *oeminfo);


PENETRA_END_DECLS


#endif /* _PENETRA_DOS_H_ */
