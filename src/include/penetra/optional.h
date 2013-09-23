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

#ifndef _PENETRA_OPTIONAL_H_
#define _PENETRA_OPTIONAL_H_

#include "types.h"
#include "directory.h"
#include "defines.h"


PENETRA_BEGIN_DECLS

typedef enum {
	IMAGE_DIRECTORY_ENTRY_EXPORT			= 0,
	IMAGE_DIRECTORY_ENTRY_IMPORT			= 1,
	IMAGE_DIRECTORY_ENTRY_RESOURCE			= 2,
	IMAGE_DIRECTORY_ENTRY_EXCEPTION			= 3,
	IMAGE_DIRECTORY_ENTRY_SECURITY			= 4,
	IMAGE_DIRECTORY_ENTRY_BASERELOC			= 5,
	IMAGE_DIRECTORY_ENTRY_DEBUG				= 6,
	IMAGE_DIRECTORY_ENTRY_COPYRIGHT			= 7,
	IMAGE_DIRECTORY_ENTRY_GLOBALPTR			= 8,
	IMAGE_DIRECTORY_ENTRY_TLS				= 9,
	IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG		= 10,
	IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT		= 11,
	IMAGE_DIRECTORY_ENTRY_IAT				= 12,
	IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT		= 13,
	IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR	= 14 
} PenetraDirectoryEntry;

typedef struct {
	_u16 magic;					/*!< Architeture */
	_u8 major_linker;			/*!< Major Linker Version */
	_u8 minor_linker;			/*!< Minor Linker Version */
	_u32 code_size;				/*!< Size of Code*/
	_u32 size_init_data; 		/*!< Size of Initialized Data */
	_u32 size_uninit_data; 		/*!< Size of Uniniatilized Data */
	_u32 entry_point; 			/*!< Address Of Entry Point */
	_u32 base_code; 			/*!< Base of Code */ 
	_u32 base_data;				/*!< Base of Data */
	_u32 image_base;			/*!< Image Base */
	_u32 section_alignment;		/*!< Section Alignment */
	_u32 file_alignment;		/*!< File Alignment */
	_u16 major_os; 				/*!< Major Operating System Version */
	_u16 minor_os; 				/*!< Minor Operating System Version */
	_u16 major_image;			/*!< Major Image Version */
	_u16 minor_image;			/*!< Minor Image Version */
	_u16 major_subsystem;		/*!< Major Subsystem Version */
	_u16 minor_subsystem;		/*!< Minor Subsystem Version */
	_u32 reserved;				/*!< Reserverd1 */
	_u32 size_image; 			/*!< Size of Image */
	_u32 size_headers;			/*!< Size of Headers */
	_u32 checksum;				/*!< Checksum */
	_u16 subsystem;				/*!< Subsystem */
	_u16 dll_characteristics;	/*!< Dll Characteristics */
	_u32 size_stack_reserve;	/*!< Size of Stack Reserve */
	_u32 size_stack_commit;		/*!< Size of Stack Commit */
	_u32 size_heap_reserve;		/*!< Size of Heap Reserve */
	_u32 size_heap_commit;		/*!< Size of Heap Commit */
	_u32 loader_flags;			/*!< Loader Flags */
	_u32 nrva;					/*!< Number of Rva and Sizes */
	PenetraDirectory directory[NUMBEROF_DIRECTORY_ENTRIES];
} PenetraOptional32;


typedef struct {
	_u16 magic;					/*!< Architeture */
	_u8 major_linker;			/*!< Major Linker Version */
	_u8 minor_linker;			/*!< Minor Linker Version*/
	_u32 code_size;				/*!< Size of Code*/
	_u32 size_init_data; 		/*!< Size of Initialized Data */
	_u32 size_uninit_data; 		/*!< Size of Uniniatilized Data */
	_u32 entry_point; 			/*!< Address Of Entry Point */
	_u32 base_code; 			/*!< Base of Code */ 
	_u32 image_base;			/*!< Image Base */
	_u32 section_alignment;		/*!< Section Alignment */
	_u32 file_alignment;		/*!< File Alignment */
	_u16 major_os; 				/*!< Major Operating System Version */
	_u16 minor_os; 				/*!< Minor Operating System Version */
	_u16 major_image;			/*!< Major Image Version */
	_u16 minor_image;			/*!< Minor Image Version */
	_u16 major_subsystem;		/*!< Major Subsystem Version */
	_u16 minor_subsystem;		/*!< Minor Subsystem Version */
	_u32 reserved;				/*!< Reserverd1 */
	_u32 size_image; 			/*!< Size of Image */
	_u32 size_headers;			/*!< Size of Headers */
	_u32 checksum;				/*!< Checksum */
	_u16 subsystem;				/*!< Subsystem */
	_u16 dll_characteristics;	/*!< Dll Characteristics */
	_u64 size_stack_reserve;	/*!< Size of Stack Reserve */
	_u64 size_stack_commit;		/*!< Size of Stack Commit */
	_u64 size_heap_reserve;		/*!< Size of Heap Reserve */
	_u64 size_heap_commit;		/*!< Size of Heap Commit */
	_u32 loader_flags;			/*!< Loader Flags */
	_u32 nrva;					/*!< Number of Rva and Sizes */
	PenetraDirectory directory[NUMBEROF_DIRECTORY_ENTRIES];
} PenetraOptional64;


typedef struct {
	union {
		PenetraOptional32 opt32;  /*!< Optional Header 32 bits. */
		PenetraOptional64 opt64;  /*!< Optional Header 64 bits. */
	} uopt;
	_u16 arch;	/*!< Architeture: 32 or 64 bits. */
} PenetraOptional;

/*! Get the machine architeture.
 *
 *
 */
extern _u32 penetra_optional_get_magic(PenetraOptional *opt, _u16 *magic);


/* Get the machine architeture.
 *
 *
 */
extern _u32 penetra_optional_get_major_linker(PenetraOptional *opt, 
											  _u16 *major);


/*
 *
 */
extern _u32 penetra_optional_get_minor_linker(PenetraOptional *opt, 
											  _u16 *minor);


/*
 *
 */
extern _u32 penetra_optional_get_code_size(PenetraOptional *opt, _u32 *csize);


/*
 *
 */
extern _u32 penetra_optional_get_size_init_data(PenetraOptional *opt, 
												_u32 *size);


/*
 *
 */
extern _u32 penetra_optional_get_size_uninit_data(PenetraOptional *opt, 
												  _u32 *size);


/*
 *
 */
extern _u32 penetra_optional_get_entry_point(PenetraOptional *opt, _u32 *addr);


/*
 *
 */
extern _u32 penetra_optional_get_base_code(PenetraOptional *opt, _u32 *code);


/* Only PE_ARCH32
 *
 */
extern _u32 penetra_optional_get_base_data(PenetraOptional *opt, _u32 *data);


/*
 *
 */
extern _u32 penetra_optional_get_image_base(PenetraOptional *opt, _u32 *image);


/*
 *
 */
extern _u32 penetra_optional_get_section_alignment(PenetraOptional *opt,
												   _u32 *setion);


/*
 *
 */
extern _u32 penetra_optional_get_file_alignment(PenetraOptional *opt, 
												_u32 *file);


/*
 *
 */
extern _u32 penetra_optional_get_major_os(PenetraOptional *opt, _u16 *os);


/*
 *
 */
extern _u32 penetra_optional_get_minor_os(PenetraOptional *opt, _u16 *os);


/*
 *
 */
extern _u32 penetra_optional_get_major_image(PenetraOptional *opt, 
											 _u16 *image);


/*
 *
 */
extern _u32 penetra_optional_get_minor_image(PenetraOptional *opt, 
											 _u16 *image);


/*
 *
 */
extern _u32 penetra_optional_get_major_subsystem(PenetraOptional *opt,
											 	 _u16 *subsystem);


/*
 *
 */
extern _u32 penetra_optional_get_minor_subsystem(PenetraOptional *opt, 
											 	 _u16 *subsystem);


/*
 *
 */
extern _u32 penetra_optional_get_reserved(PenetraOptional *opt, _u32 *reserved);


/*
 *
 */
extern _u32 penetra_optional_get_size_image(PenetraOptional *opt, _u32 *size);


/*
 *
 */
extern _u32 penetra_optional_get_size_headers(PenetraOptional *opt, _u32 *size);


/*
 *
 */
extern _u32 penetra_optional_get_checksum(PenetraOptional *opt, _u32 *checksum);


/*
 *
 */
extern _u32 penetra_optional_get_subsystem(PenetraOptional *opt, 
										   _u16 *subsystem);


/*
 *
 */
extern _u32 penetra_optional_get_characteristics(PenetraOptional *opt,
										   		 _u16 *characteristics);


/*
 *
 */
extern _u32 penetra_optional_get_size_stack_reserve(PenetraOptional *opt,
										   		 	_u64 *size);


/*
 *
 */
extern _u32 penetra_optional_get_size_stack_commit(PenetraOptional *opt,
										   		   _u64 *size);


/*
 *
 */
extern _u32 penetra_optional_get_size_heap_reserve(PenetraOptional *opt,
										   		  _u64 *size);


/*
 *
 */
extern _u32 penetra_optional_get_size_heap_commit(PenetraOptional *opt,
										   		  _u64 *size);


/*
 *
 */
extern _u32 penetra_optional_get_loader_flags(PenetraOptional *opt,
											  _u32 *flags);


/*
 *
 */
extern _u32 penetra_optional_get_rva(PenetraOptional *opt, _u32 *rva);


extern _u32 print_dirs(PenetraOptional *opt);

PENETRA_END_DECLS


#endif /* _PENETRA_OPTIONAL_H_ */
