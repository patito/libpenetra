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

#ifndef _PENETRA_SECTION_H_
#define _PENETRA_SECTION_H_

#include "types.h"


PENETRA_BEGIN_DECLS

#define IMAGE_SIZEOF_SHORT_NAME 8

/*!
 * \file section.h
 * \brief The PenetraSection object stores all info about Image Section Header.
 */

/*! \struct PenetraSection
 *  \brief Stores information about Image Section Header. Provides the 
 *         PenetraSection object and all methods to access the attributes.
 */
typedef struct {
    _u8 name[IMAGE_SIZEOF_SHORT_NAME]; /*!< An 8-byte, null-padded UTF-8 string. */
    /*! \union misc
     *  \brief  Stores file address and total size of section.
     */
    union {
        _u32 paddress;          /*!< The file address. */
        _u32 vsize;             /*!< The total size of the section when loaded into memory,
                                     in bytes */
    } misc;
    _u32 vaddress;              /*!< The address of the first byte of the section when
                                     loaded into memory, relative to the image base.*/
    _u32 raw_data_size;         /*!< The size of the initialized data on disk, in bytes. */
    _u32 raw_data_pointer;      /*!< A file pointer to the first page within the COFF file. */
    _u32 relocations;           /*!< A file pointer to the beginning of the relocation
                                     entries for the section. */
    _u32 line_numbers_pointer;  /*!< (DEPRECATED) A file pointer to the beginning of
                                     the line-number entries for the section. */
    _u16 nrelocations;          /*!< The number of relocation entries for the section. */
    _u16 nline;                 /*!< (DEPRECATED) The number of line-number entries for
                                     the section. */
    _u32 characteristics;       /*!< The characteristics of the image. */
} PenetraSection;


/*! Get the name.
 * 
 * @param section A valid PenetraSection object.
 * @param name The name saved.
 * @param index The index of section.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_section_get_name(PenetraSection *section, 
                                     _u8 *name, 
                                     _u32 index);


/*! Get
 * 
 * @param section A valid PenetraSection object.
 * @param 
 * @param index The index of section.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_section_get_paddress(PenetraSection *section,
                                         _u32 *paddress,
                                         _u32 index);


/*! Get
 * 
 * @param section A valid PenetraSection object.
 * @param 
 * @param index The index of section.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_section_get_vsize(PenetraSection *section, 
                                      _u32 *vsize,
                                      _u32 index);


PENETRA_END_DECLS

#endif /* _PENETRA_SECTION_H_ */
