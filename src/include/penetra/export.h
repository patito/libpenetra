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

#ifndef _PENETRA_EXPORT_H_
#define _PENETRA_EXPORT_H_

#include "types.h"


PENETRA_BEGIN_DECLS

/*!
 * \file export.h
 * \brief The PenetraExport object stores all info about Image Export header.
 */

/*! \struct PenetraExport
 *  \brief Stores information about Image Export Header. Provides the 
 *         PenetraExport object and all methods to access the attributes.
 */
typedef struct {
	_u32 characteristics;
	_u32 tdstamp;
	_u16 major_version;
	_u16 minor_version;
	_u32 name;
	_u32 base;
	_u32 nfunctions;
	_u32 nnames;
	_u32 func_address;
	_u32 name_address;
	_u32 ordinal_names_address;
} PenetraExport;


PENETRA_END_DECLS


#endif /* _PENETRA_EXPORT_H_ */
