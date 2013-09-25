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

#ifndef _PENETRA_DOS_H_
#define _PENETRA_DOS_H_

#include "types.h"

PENETRA_BEGIN_DECLS


/*! \file dos.h
 *  \brief Stores all info about DOS header.
 */

/*! \struct PenetraDos
 *  \brief Provides PenetraDos object and methods getters 
 *         to access all attributes.
 */
typedef struct {
    _u16 magic;     /*!< DOS Signature "MZ". */
    _u16 cblp;      /*!< Number of bytes on the last page of the file. */
    _u16 cp;        /*!< Number of pages in file. */
    _u16 crlc;      /*!< Relocations. */
    _u16 cparhdr;   /*!< Size of the header in paragraphs. */
    _u16 minalloc;  /*!< Minimum paragraphs to allocate. */
    _u16 maxalloc;  /*!< Maximum paragraphs to allocate. */
    _u16 ss;        /*!< Initial (relative) SS value. */
    _u16 sp;        /*!< Initial SP value. */
    _u16 csum;      /*!< Checksum. */
    _u16 ip;        /*!< Initial IP value. */
    _u16 cs;        /*!< Initial (relative) CS value. */
    _u16 lfarlc;    /*!< File address of relocation table. */
    _u16 ovno;      /*!< Overlay number. */
    _u16 res[4];    /*!< Reserved. */
    _u16 oemid;     /*!< OEM identifier (for e_oeminfo). */
    _u16 oeminfo;   /*!< OEM information; e_oemid specific. */
    _u16 res2[10];  /*!< Reserved. */
    _i32 lfanew;    /*!< Offset of the PE header. */
} PenetraDos;


/*! Get Image Dos Signature, MZ.
 *
 * @param dos A valid PenetraDos object.
 * @param signature The signature saved.
 * 
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_signature(PenetraDos *dos, _u16 *signature);


/*! Get the magic field on DOS header, "MZ" signature.
 *
 * @param dos A valid PenetraDos object.
 * @param magic The magic field saved.
 * 
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_magic(PenetraDos *dos, _u16 *magic);


/*! Get field e_elfnew, the PE File Header offset.
 *
 * @param dos A valid PenetraDos object.
 * @param offset The PE File Header offset saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_lfanew(PenetraDos *dos, _i32 *offset);


/*! Get field e_cblp, that stores the number of bytes on last page of file.
 *
 * @param dos A valid PenetraDos object.
 * @param cblp The number of bytes on last page of file saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_cblp(PenetraDos *dos, _u16 *cblp);


/*! Get field e_cp, that stores the number of 512 byte pages in the file.
 *
 * @param dos A valid PenetraDos object.
 * @param cp The number of pages in file saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_cp(PenetraDos *dos, _u16 *cp);


/*! Get field e_crlc, relocations.
 *
 * @param dos A valid PenetraDos object.
 * @param crlc The relocations saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_crlc(PenetraDos *dos, _u16 *crlc);


/*! Get field e_cparhdr, the size of header in paragraphs.
 *
 * @param dos A valid PenetraDos object.
 * @param cparhdr The size of header saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_cparhdr(PenetraDos *dos, _u16 *cparhdr);


/*! Get field e_minalloc. Minimum extra paragraphs needed.
 *
 * @param dos A valid PenetraDos object.
 * @param minalloc The minimum extra paragraphs saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_minalloc(PenetraDos *dos, _u16 *minalloc);


/*! Get field e_maxalloc. Maximum extra paragraphs needed.
 *
 * @param dos A valid PenetraDos object.
 * @param maxalloc The maximum extra paragraphs saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_maxalloc(PenetraDos *dos, _u16 *maxalloc);


/*! Get field e_ss. Initial (relative) SS value.
 *
 * @param dos A valid PenetraDos object.
 * @param ss The SS value saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_ss(PenetraDos *dos, _u16 *ss);


/*! Get field e_sp. Initial SP value.
 *
 * @param dos A valid PenetraDos object.
 * @param sp The SP value saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_sp(PenetraDos *dos, _u16 *sp);


/*! Get field e_csum. The checksum.
 *
 * @param dos A valid PenetraDos object.
 * @param csum The checksum saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_csum(PenetraDos *dos, _u16 *csum);


/*! Get field e_ip. Initial IP value.
 *
 * @param dos A valid PenetraDos object.
 * @param ip The IP value saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_ip(PenetraDos *dos, _u16 *ip);


/*! Get field e_cs. Initial (relative) CS value.
 *
 * @param dos A valid PenetraDos object.
 * @param cs The cs value saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_cs(PenetraDos *dos, _u16 *cs);


/*! Get field e_lfarlc. File address of relocation table.
 *
 * @param dos A valid PenetraDos object.
 * @param lfarlc The file address of relocation table saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_lfarlc(PenetraDos *dos, _u16 *lfarlc);


/*! Get field e_ovno. Overlay number.
 *
 * @param dos A valid PenetraDos object.
 * @param ovno The overlay number saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_ovno(PenetraDos *dos, _u16 *ovno);


/*! Get field e_oemid. OEM identifier.
 *
 * @param dos A valid PenetraDos object.
 * @param oemid The OEM identifier saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_oemid(PenetraDos *dos, _u16 *oemid);


/*! Get field e_oeminfo. OEM information.
 *
 * @param dos A valid PenetraDos object.
 * @param oeminfo The OEM information saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_dos_get_oeminfo(PenetraDos *dos, _u16 *oeminfo);


PENETRA_END_DECLS


#endif /* _PENETRA_DOS_H_ */
