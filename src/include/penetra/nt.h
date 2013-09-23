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
extern _u32 penetra_nt_get_signature(PenetraNT *nt, _u16 *signature);


/* Get optional header.
 *
 *
 */
extern _u32 penetra_nt_get_optional(PenetraNT *nt, PenetraOptional *opt);


/* Get coff header.
 *
 *
 */
extern _u32 penetra_nt_get_coff(PenetraNT *nt, PenetraCoff *coff);


PENETRA_END_DECLS


#endif /* _PENETRA_NT_H_ */
