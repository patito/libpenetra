/* IMAGE_OPTIONAL_HEADER
 *
 * 
 */

#ifndef _PENETRA_OPTIONAL_H_
#define _PENETRA_OPTIONAL_H_

#include "types.h"


PENETRA_BEGIN_DECLS


typedef struct {
	_u16 Magic;
	_u8 MajorLinkerVersion;
	_u8 MinorLinkerVersion;
	_u32 SizeOfCode;
	_u32 SizeOfInitializedData;
	_u32 SizeOfUninitializedData;
	_u32 AddressOfEntryPoint;
	_u32 BaseOfCode;
	_u32 BaseOfData;
	_u32 ImageBase;
	_u32 SectionAlignment;
	_u32 FileAlignment;
	_u16 MajorOperatingSystemVersion;
	_u16 MinorOperatingSystemVersion;
	_u16 MajorImageVersion;
	_u16 MinorImageVersion;
	_u16 MajorSubsystemVersion;
	_u16 MinorSubsystemVersion;
	_u32 Reserved1;
	_u32 SizeOfImage;
	_u32 SizeOfHeaders;
	_u32 CheckSum;
	_u16 Subsystem;
	_u16 DllCharacteristics;
	_u32 SizeOfStackReserve;
	_u32 SizeOfStackCommit;
	_u32 SizeOfHeapReserve;
	_u32 SizeOfHeapCommit;
	_u32 LoaderFlags;
	_u32 NumberOfRvaAndSizes;
} PenetraOptional32;


typedef struct {
	_u16 Magic;
	_u8 MajorLinkerVersion;
	_u8 MinorLinkerVersion;
	_u32 SizeOfCode;
	_u32 SizeOfInitializedData;
	_u32 SizeOfUninitializedData;
	_u32 AddressOfEntryPoint;
	_u32 BaseOfCode;
	_u64 ImageBase;
	_u32 SectionAlignment;
	_u32 FileAlignment;
	_u16 MajorOperatingSystemVersion;
	_u16 MinorOperatingSystemVersion;
	_u16 MajorImageVersion;
	_u16 MinorImageVersion;
	_u16 MajorSubsystemVersion;
	_u16 MinorSubsystemVersion;
	_u32 Reserved1;
	_u32 SizeOfImage;
	_u32 SizeOfHeaders;
	_u32 CheckSum;
	_u16 Subsystem;
	_u16 DllCharacteristics;
	_u64 SizeOfStackReserve;
	_u64 SizeOfStackCommit;
	_u64 SizeOfHeapReserve;
	_u64 SizeOfHeapCommit;
	_u32 LoaderFlags;
	_u32 NumberOfRvaAndSizes;
} PenetraOptional64;

typedef union {
	PenetraOptional32 *opt32;
	PenetraOptional64 *opt64;
} PenetraOptional;

/* Get the machine architeture.
 *
 *
 */
extern _u32 penetra_optional_get_arch(PenetraOptional32 *opt, _u16 *arch);



PENETRA_END_DECLS


#endif /* _PENETRA_OPTIONAL_H_ */
