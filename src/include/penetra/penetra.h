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

#ifndef _PENETRA_H_
#define _PENETRA_H_

#include <stdbool.h>

#include "defines.h"
#include "error.h"
#include "types.h"
#include "dos.h"
#include "nt.h"
#include "coff.h"
#include "optional.h"
#include "section.h"


PENETRA_BEGIN_DECLS

/*! \file penetra.h
 *  \brief Stores all info about PE binary.  
 */

/*! \struct Penetra
 *  \brief Stores all information about binary file.
 *   
 *  \details The Penetra structure is used to store all information about PE binary.
 * The Penetra object provides methods to access the attributes, and all
 * attributes should only be accessed via the following functions (getters and
 * setters).
 *
 */
typedef struct {
    _i32 fd;                /*!< Binary file descriptor. */
    _u32 size;              /*!< The binary file size. */
    char *fname;            /*!< Binary file name. */
    _u8 alloc_type;         /*!< Alloc type: using mmap or malloc. */
    _u8 *mem;               /*!< Loaded binary file. */
    PenetraDos *dos;        /*!< DOS header address. */
    PenetraNT nt;           /*!< NT Header. */
    PenetraSection *section;    /*!< Section Header. */
    _u16 arch;              /*!< Architeture: 32 or 64. */
} Penetra;


/*! Initialize PE object (struct Penetra).
 *
 * @param pen A valid Penetra object.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_init(Penetra *pen);


/*! Open the binary file and load the PE binary to memory. To load
 * binary file to the memory, mmap functions is used by default,
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


/*! Open and load binary file using mmap() function.
 *
 * @param pen A valid Penetra object.
 * @param fname A valid binary filename. Example: /tmp/putty.exe
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_open_mmap(Penetra *pen, const char *fname);


/*! Open and load binary file using malloc() function.
 *
 * @param pen A valid Penetra object.
 * @param fname A valid binary filename. Example: /tmp/putty.exe
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_open_malloc(Penetra *pen, const char *fname);


/*! Release PE object (struct Penetra).
 *
 * @param pen A valid Penetra object.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_finish(Penetra *pen);


/*! Verify if the binary file is a Portable Executable (PE).
 *
 * @param pen A valid Penetra object.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_is_pe(Penetra *pen);

/*! Convert Relative Virtual Address to Offset.
 *
 * @param pen A valid Penetra object.
 * @param rva The relative virtual address.
 * @param offset The offset saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_rva2ofs(Penetra *pen, _u32 rva, _u32 *offset);

/****************************************************************************** 
 ********************************** GETTERS *********************************** 
 *****************************************************************************/ 


/*! Get the alloc type.
 *
 * @param pen A valid Penetra object.
 * @param alloc_type Saved alloc type.
 * 
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_get_alloc_type(Penetra *pen, _u8 *alloc_type);


/*! Get DOS header address.
 *
 * @param pen A valid Penetra object.
 * @param dos A valid PenetraDos object.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_get_dos(Penetra *pen, PenetraDos *dos);


/*! Get Section header address.
 *
 * @param pen A valid Penetra object.
 * @param section A valid PenetraSection object.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_get_section(Penetra *pen, PenetraSection **section);


/*! Get PE File Header address.
 *
 * @param pen A valid Penetra object.
 * @param dos A valid PenetraCoff object.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_get_coff(Penetra *pen, PenetraCoff *coff);


/*! Get Optional Header address.
 *
 * @param pen A valid Penetra object.
 * @param dos A valid PenetraOptional object.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_get_optional(Penetra *pen, PenetraOptional *opt);


/*! Get NT Header address.
 *
 * @param pen A valid Penetra object.
 * @param dos A valid PenetraNT object.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_get_nt(Penetra *pen, PenetraNT *nt);


/*! Get PE architeture.
 *
 * @param pen A valid Penetra object.
 * @param arch The architeture saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_get_arch(Penetra *pen, _u16 *arch);


/****************************************************************************** 
 ********************************** SETTERS *********************************** 
 *****************************************************************************/ 


/*! Set the alloc type.
 *
 * @param pen A valid Penetra object.
 * @param alloc_type The allocation type to be used.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_set_alloc_type(Penetra *pen, _u8 alloc_type);


PENETRA_END_DECLS

#endif /* _PENETRA_H_ */
