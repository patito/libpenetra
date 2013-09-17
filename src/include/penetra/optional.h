/* IMAGE_OPTIONAL_HEADER
 *
 * 
 */

#ifndef _PENETRA_OPTIONAL_H_
#define _PENETRA_OPTIONAL_H_

#include "types.h"


PENETRA_BEGIN_DECLS


typedef struct {
	_u16 magic;					/* Architeture */
	_u8 major_linker;			/* Major Linker Version */
	_u8 minor_linker;			/* Minor Linker Version*/
	_u32 code_size;				/* Size of Code*/
	_u32 size_init_data; 		/* Size of Initialized Data */
	_u32 size_uninit_data; 		/* Size of Uniniatilized Data */
	_u32 entry_point_addr; 		/* Address Of Entry Point */
	_u32 base_code; 			/* Base of Code */ 
	_u32 base_data;				/* Base of Data */
	_u32 image_base;			/* Image Base */
	_u32 section_alignment;		/* Section Alignment */
	_u32 file_alignment;		/* File Alignment */
	_u16 major_os; 				/* Major Operating System Version */
	_u16 minor_os; 				/* Minor Operating System Version */
	_u16 major_image;			/* Major Image Version */
	_u16 minor_image;			/* Minor Image Version */
	_u16 major_subsystem;		/* Major Subsystem Version */
	_u16 minor_subsystem;		/* Minor Subsystem Version */
	_u32 reserved;				/* Reserverd1 */
	_u32 size_image; 			/* Size of Image */
	_u32 size_headers;			/* Size of Headers */
	_u32 checksum;				/* Checksum */
	_u16 Subsystem;				/* Subsystem */
	_u16 dll_characteristics;	/* Dll Characteristics */
	_u32 size_stack_reserve;	/* Size of Stack Reserve */
	_u32 size_stack_commit;		/* Size of Stack Commit */
	_u32 size_heap_reserve;		/* Size of Heap Reserve */
	_u32 size_heap_commit;		/* Size of Heap Commit */
	_u32 loader_flags;			/* Loader Flags */
	_u32 nrva;					/* Number of Rva and Sizes */
} PenetraOptional32;


typedef struct {
	_u16 magic;					/* Architeture */
	_u8 major_linker;			/* Major Linker Version */
	_u8 minor_linker;			/* Minor Linker Version*/
	_u32 code_size;				/* Size of Code*/
	_u32 size_init_data; 		/* Size of Initialized Data */
	_u32 size_uninit_data; 		/* Size of Uniniatilized Data */
	_u32 entry_point_addr; 		/* Address Of Entry Point */
	_u32 base_code; 			/* Base of Code */ 
	_u32 image_base;			/* Image Base */
	_u32 section_alignment;		/* Section Alignment */
	_u32 file_alignment;		/* File Alignment */
	_u16 major_os; 				/* Major Operating System Version */
	_u16 minor_os; 				/* Minor Operating System Version */
	_u16 major_image;			/* Major Image Version */
	_u16 minor_image;			/* Minor Image Version */
	_u16 major_subsystem;		/* Major Subsystem Version */
	_u16 minor_subsystem;		/* Minor Subsystem Version */
	_u32 reserved;				/* Reserverd1 */
	_u32 size_image; 			/* Size of Image */
	_u32 size_headers;			/* Size of Headers */
	_u32 checksum;				/* Checksum */
	_u16 Subsystem;				/* Subsystem */
	_u16 dll_characteristics;	/* Dll Characteristics */
	_u64 size_stack_reserve;	/* Size of Stack Reserve */
	_u64 size_stack_commit;		/* Size of Stack Commit */
	_u64 size_heap_reserve;		/* Size of Heap Reserve */
	_u64 size_heap_commit;		/* Size of Heap Commit */
	_u32 loader_flags;			/* Loader Flags */
	_u32 nrva;					/* Number of Rva and Sizes */
} PenetraOptional64;


typedef struct {
	union {
		PenetraOptional32 opt32;
		PenetraOptional64 opt64;
	} uopt;
	_u16 arch;
} PenetraOptional;

/* Get the machine architeture.
 *
 *
 */
extern _u32 penetra_optional_get_magic(PenetraOptional *opt, _u16 *magic);



PENETRA_END_DECLS


#endif /* _PENETRA_OPTIONAL_H_ */
