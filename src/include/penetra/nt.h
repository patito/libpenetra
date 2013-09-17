/* IMAGE_NT_HEADER
 *
 * 
 */

#ifndef _PENETRA_NT_H_
#define _PENETRA_NT_H_

#include "types.h"
#include "coff.h"
#include "optional.h"


PENETRA_BEGIN_DECLS


typedef struct {
	_u32 signature;
	PenetraCoff coff;
	PenetraOptional32 opt;	
} PenetraNT32;

typedef struct {
	_u32 signature;
	PenetraCoff coff;
	PenetraOptional64 opt;	
} PenetraNT64;

typedef struct {
	union {
		PenetraNT32 *nt32;
		PenetraNT64 *nt64;
	} unt;
	_u16 arch;
} PenetraNT;


/* Get the NT signature "PE00".
 *
 *
 */
extern _u32 penetra_nt_get_signature(PenetraNT nt, _u16 *signature);


/* Get optional header.
 *
 *
 */
extern _u32 penetra_nt_get_optional(PenetraNT nt, PenetraOptional *opt);


/* Get coff header.
 *
 *
 */
extern _u32 penetra_nt_get_coff(PenetraNT nt, PenetraCoff *coff);


PENETRA_END_DECLS


#endif /* _PENETRA_NT_H_ */
