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

#ifndef _TYPES_H_
#define _TYPES_H_

#include <stdint.h>
#include <sys/types.h>

#include "defines.h"

PENETRA_BEGIN_DECLS

/*! \typedef _u8 uint8_t
 */
typedef uint8_t   _u8;

/*! \typedef _u16 uint16_t
 */
typedef uint16_t  _u16;

/*! \typedef _u32 uint32_t
 */
typedef uint32_t  _u32;

/*! \typedef _i8 int8_t
 */
typedef int8_t    _i8;

/*! \typedef _i16 int16_t
 */
typedef int16_t   _i16;

/*! \typedef _i32 int32_t
 */
typedef int32_t   _i32;

/*! \typedef _u64 uint64_t
 */
typedef uint64_t  _u64;

PENETRA_END_DECLS

#endif /* _TYPES_H_ */
