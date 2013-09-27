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

#include <string.h>

#include <penetra/error.h>
#include <penetra/types.h>
#include <penetra/section.h>


_u32 penetra_section_get_relocations(PenetraSection *section,
                                     _u32 *relocations,
                                     _u32 index)
{
    PenetraSection *_sec;

    if (NULL == section) {
        return PENETRA_EINVAL;  
    }
    
    if (NULL == relocations) {
        return PENETRA_EINVAL;
    }

    _sec = section + index;
    *relocations = _sec->relocations;

    return PENETRA_SUCCESS;
}

_u32 penetra_section_get_vsize(PenetraSection *section, 
                               _u32 *vsize,
                               _u32 index)
{
    PenetraSection *_sec;

    if (NULL == section) {
        return PENETRA_EINVAL;  
    }
    
    if (NULL == vsize) {
        return PENETRA_EINVAL;
    }

    _sec = section + index;
    *vsize = _sec->misc.vsize;

    return PENETRA_SUCCESS;
}

_u32 penetra_section_get_paddress(PenetraSection *section,
                                  _u32 *paddress,
                                  _u32 index)
{
    PenetraSection *_sec;

    if (NULL == section) {
        return PENETRA_EINVAL;  
    }
    
    if (NULL == paddress) {
        return PENETRA_EINVAL;
    }

    _sec = section + index;
    *paddress = _sec->misc.paddress;

    return PENETRA_SUCCESS;
}

_u32 penetra_section_get_name(PenetraSection *section,
                              _u8 *name,
                              _u32 index)
{
    PenetraSection *_sec;

    if (NULL == section) {
        return PENETRA_EINVAL;  
    }
    
    if (NULL == name) {
        return PENETRA_EINVAL;
    }

    _sec = section + index;
    memcpy(name, _sec->name, IMAGE_SIZEOF_SHORT_NAME);

    return PENETRA_SUCCESS;
}

_u32 penetra_section_get_vaddress(PenetraSection *section,
                                  _u32 *vaddress,
                                  _u32 index)
{
    PenetraSection *_sec;

    if (NULL == section) {
        return PENETRA_EINVAL;  
    }
    
    if (NULL == vaddress) {
        return PENETRA_EINVAL;
    }

    _sec = section + index;
    *vaddress = _sec->vaddress;

    return PENETRA_SUCCESS;
}

_u32 penetra_section_get_raw_data_size(PenetraSection *section,
                                       _u32 *size,
                                       _u32 index)
{
    PenetraSection *_sec;

    if (NULL == section) {
        return PENETRA_EINVAL;  
    }
    
    if (NULL == size) {
        return PENETRA_EINVAL;
    }

    _sec = section + index;
    *size = _sec->raw_data_size;

    return PENETRA_SUCCESS;
}

_u32 penetra_section_get_raw_data_pointer(PenetraSection *section,
                                          _u32 *pointer,
                                          _u32 index)
{
    PenetraSection *_sec;

    if (NULL == section) {
        return PENETRA_EINVAL;  
    }
    
    if (NULL == pointer) {
        return PENETRA_EINVAL;
    }

    _sec = section + index;
    *pointer = _sec->raw_data_pointer;

    return PENETRA_SUCCESS;
}

_u32 penetra_section_get_nrelocations(PenetraSection *section,
                                      _u16 *nrelocations,
                                      _u32 index)
{
    PenetraSection *_sec;

    if (NULL == section) {
        return PENETRA_EINVAL;  
    }
    
    if (NULL == nrelocations) {
        return PENETRA_EINVAL;
    }

    _sec = section + index;
    *nrelocations = _sec->nrelocations;

    return PENETRA_SUCCESS;
}

_u32 penetra_section_get_line_numbers_pointer(PenetraSection *section,
                                              _u32 *pointer,
                                              _u32 index)
{
    PenetraSection *_sec;

    if (NULL == section) {
        return PENETRA_EINVAL;  
    }
    
    if (NULL == pointer) {
        return PENETRA_EINVAL;
    }

    _sec = section + index;
    *pointer = _sec->line_numbers_pointer;

    return PENETRA_SUCCESS;
}

_u32 penetra_section_get_nline(PenetraSection *section,
                               _u16 *nline,
                               _u32 index)
{
    PenetraSection *_sec;

    if (NULL == section) {
        return PENETRA_EINVAL;  
    }
    
    if (NULL == nline) {
        return PENETRA_EINVAL;
    }

    _sec = section + index;
    *nline = _sec->nline;

    return PENETRA_SUCCESS;

}

_u32 penetra_section_get_characteristics(PenetraSection *section,
                                         _u32 *characteristics,
                                         _u32 index)
{
    PenetraSection *_sec;

    if (NULL == section) {
        return PENETRA_EINVAL;  
    }
    
    if (NULL == characteristics) {
        return PENETRA_EINVAL;
    }

    _sec = section + index;
    *characteristics = _sec->characteristics;

    return PENETRA_SUCCESS;

}

