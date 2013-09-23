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


_u32 penetra_nt_get_optional(PenetraNT *nt, PenetraOptional *opt)
{
	if (NULL == nt) {
		return PENETRA_EINVAL;
	}

	if (NULL == opt) {
		return PENETRA_EINVAL;
	}

	switch(nt->arch) {
		case PE_ARCH32:
			opt->uopt.opt32 = nt->unt.nt32->opt;
			opt->arch = PE_ARCH32;
			break;
		case PE_ARCH64:
			opt->uopt.opt32 = nt->unt.nt32->opt;
			opt->arch = PE_ARCH64;
			break;
		default:
			return PENETRA_EINVALID_ARCH;
	}

	return PENETRA_SUCCESS;
}

_u32 penetra_nt_get_coff(PenetraNT *nt, PenetraCoff *coff)
{
	if (NULL == nt) {
		return PENETRA_EINVAL;
	}

	if (NULL == coff) {
		return PENETRA_EINVAL;
	}

	switch(nt->arch) {
		case PE_ARCH32:
			*coff = nt->unt.nt32->coff;
			break;
		case PE_ARCH64:
			*coff = nt->unt.nt64->coff;
			break;
		default:
			return PENETRA_EINVALID_ARCH;
	}

	return PENETRA_SUCCESS;
}

_u32 penetra_nt_get_signature(PenetraNT *nt, _u16 *signature)
{
	if (NULL == nt) {
		return PENETRA_EINVAL;
	}

	if (NULL == signature) {
		return PENETRA_EINVAL;
	}

	switch(nt->arch) {
		case PE_ARCH32:
			*signature = nt->unt.nt32->signature;
			break;
		case PE_ARCH64:
			*signature = nt->unt.nt64->signature;
			break;
		default:
			return PENETRA_EINVALID_ARCH;
	}

	return PENETRA_SUCCESS;
}

