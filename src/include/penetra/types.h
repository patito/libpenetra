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

typedef uint8_t   _u8;
typedef uint16_t  _u16;
typedef uint32_t  _u32;
typedef int8_t    _i8;
typedef int16_t   _i16;
typedef int32_t   _i32;
typedef uint64_t  _u64;

PENETRA_END_DECLS

#endif /* _TYPES_H_ */
