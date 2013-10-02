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
#include <stdio.h>

#include <penetra/error.h>
#include <penetra/types.h>
#include <penetra/defines.h>
#include <penetra/nt.h>



_u32 penetra_directory_get_rva(PenetraDirectory *dir, _u32 *rva)
{
    if (NULL == dir) {
        return PENETRA_EINVAL;
    }

    if (NULL == rva) {
        return PENETRA_EINVAL;
    }

    *rva = dir->rva;

    return PENETRA_SUCCESS;
}


_u32 penetra_directory_get_size(PenetraDirectory *dir, _u32 *size)
{
    if (NULL == dir) {
        return PENETRA_EINVAL;
    }

    if (NULL == size) {
        return PENETRA_EINVAL;
    }

    *size = dir->size;

    return PENETRA_SUCCESS;
}

