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

#ifndef _PENETRA_DIRECTORY_H_
#define _PENETRA_DIRECTORY_H_

#include "types.h"


PENETRA_BEGIN_DECLS

/*! \file directory.h
 *  \brief Contains data directory information. 
 */

/*! \struct PenetraDirectory
 *  \brief Contains data directory information.
 */
typedef struct {
    _u32 vaddress;      /*!< The relative virtual address of the table. */
    _u32 size;          /*!< The size of the table, in bytes. */
} PenetraDirectory;


PENETRA_END_DECLS


#endif /* _PENETRA_DIRECTORY_H_ */
