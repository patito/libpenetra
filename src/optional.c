#include <string.h>
#include <stdio.h>

#include <penetra/error.h>
#include <penetra/types.h>
#include <penetra/optional.h>

_u32 penetra_optional_get_magic(PenetraOptional *opt, _u16 *magic)
{
	if (NULL == opt) {
		return PENETRA_EINVAL;
	}

	if (NULL == magic) {
		return PENETRA_EINVAL;
	}

	switch(opt->arch) {
		case PE_ARCH32:
			*magic = opt->uopt.opt32.magic;
			break;
		case PE_ARCH64:
			*magic = opt->uopt.opt64.magic;
			break;
		default:
			return PENETRA_EINVALID_ARCH;
	}

	return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_major_linker(PenetraOptional *opt, _u16 *major)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == major) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *major = opt->uopt.opt32.major_linker;
            break;
        case PE_ARCH64:
            *major = opt->uopt.opt64.major_linker;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}


_u32 penetra_optional_get_minor_linker(PenetraOptional *opt, _u16 *minor)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == minor) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *minor = opt->uopt.opt32.minor_linker;
            break;
        case PE_ARCH64:
            *minor = opt->uopt.opt64.minor_linker;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}


_u32 penetra_optional_get_code_size(PenetraOptional *opt, _u32 *csize)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == csize) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *csize = opt->uopt.opt32.code_size;
            break;
        case PE_ARCH64:
            *csize = opt->uopt.opt64.code_size;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}


_u32 penetra_optional_get_size_init_data(PenetraOptional *opt, _u32 *size)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == size) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *size = opt->uopt.opt32.size_init_data;
            break;
        case PE_ARCH64:
            *size = opt->uopt.opt64.size_init_data;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_size_uninit_data(PenetraOptional *opt, _u32 *size)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == size) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *size = opt->uopt.opt32.size_uninit_data;
            break;
        case PE_ARCH64:
            *size = opt->uopt.opt64.size_uninit_data;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_entry_point(PenetraOptional *opt, _u32 *addr)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == addr) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *addr = opt->uopt.opt32.entry_point;
            break;
        case PE_ARCH64:
            *addr = opt->uopt.opt64.entry_point;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_base_code(PenetraOptional *opt, _u32 *code)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == code) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *code = opt->uopt.opt32.base_code;
            break;
        case PE_ARCH64:
            *code = opt->uopt.opt64.base_code;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;

}


// Only PE_ARCH32
_u32 penetra_optional_get_base_data(PenetraOptional *opt, _u32 *data)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == data) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *data = opt->uopt.opt32.base_data;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}


_u32 penetra_optional_get_image_base(PenetraOptional *opt, _u32 *image)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == image) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *image = opt->uopt.opt32.image_base;
            break;
        case PE_ARCH64:
            *image = opt->uopt.opt64.image_base;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;

}

_u32 penetra_optional_get_section_alignment(PenetraOptional *opt, _u32 *section)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == section) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *section = opt->uopt.opt32.section_alignment;
            break;
        case PE_ARCH64:
            *section = opt->uopt.opt64.section_alignment;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;

}

_u32 penetra_optional_get_file_alignment(PenetraOptional *opt, _u32 *file)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == file) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *file = opt->uopt.opt32.file_alignment;
            break;
        case PE_ARCH64:
            *file = opt->uopt.opt64.file_alignment;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;

}

_u32 penetra_optional_get_major_os(PenetraOptional *opt, _u16 *os)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == os) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *os = opt->uopt.opt32.major_os;
            break;
        case PE_ARCH64:
            *os = opt->uopt.opt64.major_os;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;

}

_u32 penetra_optional_get_minor_os(PenetraOptional *opt, _u16 *os)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == os) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *os = opt->uopt.opt32.minor_os;
            break;
        case PE_ARCH64:
            *os = opt->uopt.opt64.minor_os;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;

}

_u32 penetra_optional_get_major_image(PenetraOptional *opt, _u16 *image)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == image) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *image = opt->uopt.opt32.major_image;
            break;
        case PE_ARCH64:
            *image = opt->uopt.opt64.major_image;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;

}

_u32 penetra_optional_get_minor_image(PenetraOptional *opt, _u16 *image)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == image) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *image = opt->uopt.opt32.minor_image;
            break;
        case PE_ARCH64:
            *image = opt->uopt.opt64.minor_image;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_major_subsystem(PenetraOptional *opt, _u16 *subsystem)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == subsystem) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *subsystem = opt->uopt.opt32.major_subsystem;
            break;
        case PE_ARCH64:
            *subsystem = opt->uopt.opt64.major_subsystem;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_minor_subsystem(PenetraOptional *opt, _u16 *subsystem)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == subsystem) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *subsystem = opt->uopt.opt32.minor_subsystem;
            break;
        case PE_ARCH64:
            *subsystem = opt->uopt.opt64.minor_subsystem;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_reserved(PenetraOptional *opt, _u32 *reserved)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == reserved) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *reserved = opt->uopt.opt32.reserved;
            break;
        case PE_ARCH64:
            *reserved = opt->uopt.opt64.reserved;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_size_image(PenetraOptional *opt, _u32 *size)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == size) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *size = opt->uopt.opt32.size_image;
            break;
        case PE_ARCH64:
            *size = opt->uopt.opt64.size_image;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_size_headers(PenetraOptional *opt, _u32 *size)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == size) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *size = opt->uopt.opt32.size_headers;
            break;
        case PE_ARCH64:
            *size = opt->uopt.opt64.size_headers;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_checksum(PenetraOptional *opt, _u32 *checksum)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == checksum) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *checksum = opt->uopt.opt32.checksum;
            break;
        case PE_ARCH64:
            *checksum = opt->uopt.opt64.checksum;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_subsystem(PenetraOptional *opt, _u16 *subsystem)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == subsystem) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *subsystem = opt->uopt.opt32.subsystem;
            break;
        case PE_ARCH64:
            *subsystem = opt->uopt.opt64.subsystem;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_characteristics(PenetraOptional *opt, _u16 *chcrts)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == chcrts) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *chcrts = opt->uopt.opt32.dll_characteristics;
            break;
        case PE_ARCH64:
            *chcrts = opt->uopt.opt64.dll_characteristics;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}


_u32 penetra_optional_get_size_stack_reserve(PenetraOptional *opt, _u64 *size)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == size) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *size = opt->uopt.opt32.size_stack_reserve;
            break;
        case PE_ARCH64:
            *size = opt->uopt.opt64.size_stack_reserve;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_size_stack_commit(PenetraOptional *opt, _u64 *size)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == size) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *size = opt->uopt.opt32.size_stack_commit;
            break;
        case PE_ARCH64:
            *size = opt->uopt.opt64.size_stack_commit;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_size_heap_reserve(PenetraOptional *opt, _u64 *size)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == size) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *size = opt->uopt.opt32.size_heap_reserve;
            break;
        case PE_ARCH64:
            *size = opt->uopt.opt64.size_heap_reserve;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_size_heap_commit(PenetraOptional *opt, _u64 *size)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == size) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *size = opt->uopt.opt32.size_heap_commit;
            break;
        case PE_ARCH64:
            *size = opt->uopt.opt64.size_heap_commit;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_loader_flags(PenetraOptional *opt, _u32 *flags)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == flags) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *flags = opt->uopt.opt32.loader_flags;
            break;
        case PE_ARCH64:
            *flags = opt->uopt.opt64.loader_flags;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

_u32 penetra_optional_get_rva(PenetraOptional *opt, _u32 *rva)
{
    if (NULL == opt) {
        return PENETRA_EINVAL;
    }

    if (NULL == rva) {
        return PENETRA_EINVAL;
    }

    switch(opt->arch) {
        case PE_ARCH32:
            *rva = opt->uopt.opt32.nrva;
            break;
        case PE_ARCH64:
            *rva = opt->uopt.opt64.nrva;
            break;
        default:
            return PENETRA_EINVALID_ARCH;
    }

    return PENETRA_SUCCESS;
}

