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

#ifndef _PENETRA_COFF_H_
#define _PENETRA_COFF_H_

#include "types.h"


PENETRA_BEGIN_DECLS


/*!
 * \file coff.h
 * \struct PenetraCoff
 * \brief Stores all information about PE file Header.
 *   
 * The PE File Header (Coff Header) structure is used to store all information about
 * PE File Header, like: Machine, Number of Sections, Time Date Stamp and others.
 * The Coff object provides methods to access the attributes, and all
 * attributes should only be accessed via the following functions (getters and
 * setters).
 *
 */
typedef struct {
	_u16 machine;			/*!< Machine */
	_u16 nsections;			/*!< Number of Sections */
	_u32 tstamp;			/*!< Time Date Stamp */
	_u32 symbol_table;		/*!< Pointer To Symbol Table */
	_u32 nsymbols;			/*!< Number of Symbols */
	_u16 size_opt_header;	/*!< Size of Optional Header */
	_u16 characteristics;	/*!< Characteristics */
} PenetraCoff;


/*!
 * \file coff.h
 * \struct MachineTable
 * \brief Stores information about Machine type. Meaning: Intel i860 and
 *		  type: 0x14d.
 *   
 */
typedef struct {
	char *meaning;	/*!< Meaning. Example: "Intel i860". */
	_u32 value;		/*!< Value. Example: 0x14d. */
} MachineTable;


/*! Get the machine architeture.
 *
 * @param coff A valid Coff object.
 * @param machine The machine saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_coff_get_machine(PenetraCoff *coff, _u16 *machine);


/*! Get the number of sections.
 *
 *
 * @param coff A valid Coff object.
 * @param nsections The number of sections saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_coff_get_nsections(PenetraCoff *coff, _u16 *nsections);


/*! Get the time date state
 *
 *
 * @param coff A valid Coff object.
 * @param nsections The time date stamp saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_coff_get_tstamp(PenetraCoff *coff, _u16 *tstamp);


/*! Get file offset of the COFF symbol table
 *
 * @param coff A valid Coff object.
 * @param symbol_table The offset symbol table saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_coff_get_symbol_table(PenetraCoff *coff, _u16 *symbol_table);


/*! Get the number of symbols.
 *
 * @param coff A valid Coff object.
 * @param nsymbols The number of symbols saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_coff_get_nsymbols(PenetraCoff *coff, _u16 *nsymbols);


/*! Get the size of optional header.
 *
 * @param coff A valid Coff object.
 * @param size The size of Optional Header saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_coff_get_size_opt_header(PenetraCoff *coff, _u16 *size);


/*! Get flags with information about the file.
 *
 * @param coff A valid Coff object.
 * @param characteristics The Characteristics saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_coff_get_characteristics(PenetraCoff *coff, 
											 _u16 *characteristics);



PENETRA_END_DECLS


#endif /* _PENETRA_COFF_H_ */
