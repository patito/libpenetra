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

/*!
 * \file nt.h
 * \brief The NT object stores all info about NT header.
 */

/*! \struct PenetraNT32
 *  \brief Stores information about NT header (32 bits).
 */
typedef struct {
    _u32 signature;
    PenetraCoff coff;
    PenetraOptional32 opt;  
} PenetraNT32;

/*! \struct PenetraNT64
 *  \brief Stores information about NT header (32 bits).
 */
typedef struct {
    _u32 signature;
    PenetraCoff coff;
    PenetraOptional64 opt;  
} PenetraNT64;

/*! \struct PenetraNT
 *  \brief Stores information about NT header.
 */
typedef struct {
    /*! \union unt
     *  \brief The Union NT (unt) is a union to store two kind of structures,
     *         PenetraNT32 and PenetraNT64, structure that will be used will 
     *         depend on the architecture of binary file.
     */
    union {
        PenetraNT32 *nt32; /*!< A pointer to NT header (Optional 32 bits). */
        PenetraNT64 *nt64; /*!< A pointer to NT header (Optional 64 bits). */
    } unt;
    _u16 arch; /*!< Stores the architeture: 32 or 64 bits. */
} PenetraNT;


/*! Get the NT signature "PE00".
 *
 * @param nt A valid PenetraNT object.
 * @param signature The signature saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_nt_get_signature(PenetraNT *nt, _u16 *signature);


/*! Get optional header.
 *
 * @param nt A valid PenetraNT object.
 * @param opt The PenetraOptional saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_nt_get_optional(PenetraNT *nt, PenetraOptional *opt);


/*! Get coff header.
 *
 * @param nt A valid PenetraNT object.
 * @param coff The PenetraCoff saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_nt_get_coff(PenetraNT *nt, PenetraCoff *coff);


PENETRA_END_DECLS


#endif /* _PENETRA_NT_H_ */
