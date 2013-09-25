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

#include <penetra/dos.h>
#include <penetra/error.h>

_u32 penetra_dos_get_signature(PenetraDos *dos, _u16 *signature)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;  
    }
    
    if (NULL == signature) {
        return PENETRA_EINVAL;
    }

    *signature = dos->magic;

    return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_magic(PenetraDos *dos, _u16 *signature)
{
    return penetra_dos_get_signature(dos, signature);
}

_u32 penetra_dos_get_lfanew(PenetraDos *dos, _i32 *offset)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;  
    }
    
    if (NULL == offset) {
        return PENETRA_EINVAL;
    }

    *offset = dos->lfanew;
        
    return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_cblp(PenetraDos *dos, _u16 *cblp)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == cblp) {
        return PENETRA_EINVAL;
    }

    *cblp = dos->cblp;
    
    return PENETRA_SUCCESS;
}


_u32 penetra_dos_get_cp(PenetraDos *dos, _u16 *cp)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == cp) {
        return PENETRA_EINVAL;
    }

    *cp = dos->cp;
    
    return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_crlc(PenetraDos *dos, _u16 *crlc)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == crlc) {
        return PENETRA_EINVAL;
    }

    *crlc = dos->crlc;
    
    return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_cparhdr(PenetraDos *dos, _u16 *cparhdr)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == cparhdr) {
        return PENETRA_EINVAL;
    }

    *cparhdr = dos->cparhdr;
    
    return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_minalloc(PenetraDos *dos, _u16 *minalloc)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == minalloc) {
        return PENETRA_EINVAL;
    }

    *minalloc = dos->minalloc;
    
    return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_maxalloc(PenetraDos *dos, _u16 *maxalloc)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == maxalloc) {
        return PENETRA_EINVAL;
    }

    *maxalloc = dos->maxalloc;
    
    return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_ss(PenetraDos *dos, _u16 *ss)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == ss) {
        return PENETRA_EINVAL;
    }

    *ss = dos->ss;
    
    return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_sp(PenetraDos *dos, _u16 *sp)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == sp) {
        return PENETRA_EINVAL;
    }

    *sp = dos->sp;
    
    return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_csum(PenetraDos *dos, _u16 *csum)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == csum) {
        return PENETRA_EINVAL;
    }

    *csum = dos->csum;
    
    return PENETRA_SUCCESS;
}


_u32 penetra_dos_get_ip(PenetraDos *dos, _u16 *ip)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == ip) {
        return PENETRA_EINVAL;
    }

    *ip = dos->ip;
    
    return PENETRA_SUCCESS;
}


_u32 penetra_dos_get_cs(PenetraDos *dos, _u16 *cs)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == cs) {
        return PENETRA_EINVAL;
    }

    *cs = dos->cs;
    
    return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_lfarlc(PenetraDos *dos, _u16 *lfarlc)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == lfarlc) {
        return PENETRA_EINVAL;
    }

    *lfarlc = dos->lfarlc;
    
    return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_ovno(PenetraDos *dos, _u16 *ovno)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == ovno) {
        return PENETRA_EINVAL;
    }

    *ovno = dos->ovno;
    
    return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_oemid(PenetraDos *dos, _u16 *oemid)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == oemid) {
        return PENETRA_EINVAL;
    }

    *oemid = dos->oemid;
    
    return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_oeminfo(PenetraDos *dos, _u16 *oeminfo)
{
    if (NULL == dos) {
        return PENETRA_EINVAL;
    }

    if (NULL == oeminfo) {
        return PENETRA_EINVAL;
    }

    *oeminfo = dos->oeminfo;
    
    return PENETRA_SUCCESS;
}

