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


/*! Get the file address.
 * 
 * @param section A valid PenetraSection object.
 * @param paddress The physical address saved.
 * @param index The index of section.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_section_get_paddress(PenetraSection *section,
                                         _u32 *paddress,
                                         _u32 index);


/*! Get the virtual size.
 * 
 * @param section A valid PenetraSection object.
 * @param vsize The virtual size saved.
 * @param index The index of section.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_section_get_vsize(PenetraSection *section, 
                                      _u32 *vsize,
                                      _u32 index);


/*! Get the virtual address.
 * 
 * @param section A valid PenetraSection object.
 * @param vaddress The virtual address saved.
 * @param index The index of section.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_section_get_vaddress(PenetraSection *section, 
                                         _u32 *vaddress,
                                         _u32 index);

/*! Get the size of the initialized data on disk, in bytes.
 * 
 * @param section A valid PenetraSection object.
 * @param size The raw data size saved.
 * @param index The index of section.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_section_get_raw_data_size(PenetraSection *section,
                                              _u32 *size,
                                              _u32 index);

/*! Get a file pointer to the first page within the COFF file.
 * 
 * @param section A valid PenetraSection object.
 * @param pointer The raw data pointer saved.
 * @param index The index of section.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_section_get_raw_data_pointer(PenetraSection *section, 
                                                 _u32 *pointer,
                                                 _u32 index);

/*! Get a file pointer to the beginning of the relocation entries
 *  for the section.
 * 
 * @param section A valid PenetraSection object.
 * @param relocations The relocations saved.
 * @param index The index of section.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_section_get_relocations(PenetraSection *section,
                                            _u32 *relocations,
                                            _u32 index);

/*! Get a file pointer to the beginning of the line-number entries 
 *  for the section..
 * 
 * @param section A valid PenetraSection object.
 * @param pointer The line numbers pointer saved.
 * @param index The index of section.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_section_get_line_numbers_pointer(PenetraSection *section,
                                                     _u32 *pointer,
                                                     _u32 index);

/*! Get the number of relocation entries for the section.
 * 
 * @param section A valid PenetraSection object.
 * @param nrelocations The number of relocations saved.
 * @param index The index of section.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_section_get_nrelocations(PenetraSection *section, 
                                             _u16 *nrelocations,
                                             _u32 index);

/*! Get the number of line-number entries for the section..
 * 
 * @param section A valid PenetraSection object.
 * @param nline The number of line-number saved.
 * @param index The index of section.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_section_get_nline(PenetraSection *section, 
                                      _u16 *nline,
                                      _u32 index);

/*! Get the characteristics of the image.
 * 
 * @param section A valid PenetraSection object.
 * @param characteristics The characteristics saved.
 * @param index The index of section.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_section_get_characteristics(PenetraSection *section, 
                                                _u32 *characteristics,
                                                _u32 index);


PENETRA_END_DECLS

#endif /* _PENETRA_SECTION_H_ */
