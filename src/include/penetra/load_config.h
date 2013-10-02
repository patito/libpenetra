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

#ifndef _PENETRA_LOAD_CONFIG_H_
#define _PENETRA_LOAD_CONFIG_H_

#include "types.h"


PENETRA_BEGIN_DECLS

/*! \file
 *  \brief 
 */

/*! \struct
 *  \brief
 */
typedef struct {
    _u32   size;
    _u32   tdstamp;
    _u16   major_version;
    _u16   minor_version;
    _u32   global_flags_clear;
    _u32   global_flags_set;
    _u32   critical_section_default_timeout;
    _u32   decommit_free_block_threshold;
    _u32   decommit_total_free_threshold;
    _u32   lock_prefix_table;
    _u32   maximum_allocation_size;
    _u32   vmemory_threshold;
    _u32   heap_flags;
    _u32   affinity_mask;
    _u16   csd_version;
    _u16   reserved1;
    _u32   edit_list;
    _u32   security_cookie;
    _u32   handler_table;
    _u32   handler_count;
} PenetraLoadConfig32;


PENETRA_END_DECLS


#endif /* _PENETRA_LOAD_CONFIG_H_ */
