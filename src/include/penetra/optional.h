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

/*! \file optional.h
 *  \brief Stores all information about optional header.
 */

/*! \enum PenetraDirectoryEntry
 *  \brief Stores the directories entry.
 */
typedef enum {
    IMAGE_DIRECTORY_ENTRY_EXPORT            = 0,
    IMAGE_DIRECTORY_ENTRY_IMPORT            = 1,
    IMAGE_DIRECTORY_ENTRY_RESOURCE          = 2,
    IMAGE_DIRECTORY_ENTRY_EXCEPTION         = 3,
    IMAGE_DIRECTORY_ENTRY_SECURITY          = 4,
    IMAGE_DIRECTORY_ENTRY_BASERELOC         = 5,
    IMAGE_DIRECTORY_ENTRY_DEBUG             = 6,
    IMAGE_DIRECTORY_ENTRY_COPYRIGHT         = 7,
    IMAGE_DIRECTORY_ENTRY_GLOBALPTR         = 8,
    IMAGE_DIRECTORY_ENTRY_TLS               = 9,
    IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG       = 10,
    IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT      = 11,
    IMAGE_DIRECTORY_ENTRY_IAT               = 12,
    IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT      = 13,
    IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR    = 14 
} PenetraDirectoryEntry;


/*! \struct PenetraOptional32
 * \brief Stores all info about Optional Header (32 bits).
 */
typedef struct {
    _u16 magic;                 /*!< Architeture */
    _u8 major_linker;           /*!< Major Linker Version */
    _u8 minor_linker;           /*!< Minor Linker Version */
    _u32 code_size;             /*!< Size of Code*/
    _u32 size_init_data;        /*!< Size of Initialized Data */
    _u32 size_uninit_data;      /*!< Size of Uniniatilized Data */
    _u32 entry_point;           /*!< Address Of Entry Point */
    _u32 base_code;             /*!< Base of Code */ 
    _u32 base_data;             /*!< Base of Data */
    _u32 image_base;            /*!< Image Base */
    _u32 section_alignment;     /*!< Section Alignment */
    _u32 file_alignment;        /*!< File Alignment */
    _u16 major_os;              /*!< Major Operating System Version */
    _u16 minor_os;              /*!< Minor Operating System Version */
    _u16 major_image;           /*!< Major Image Version */
    _u16 minor_image;           /*!< Minor Image Version */
    _u16 major_subsystem;       /*!< Major Subsystem Version */
    _u16 minor_subsystem;       /*!< Minor Subsystem Version */
    _u32 reserved;              /*!< Reserverd1 */
    _u32 size_image;            /*!< Size of Image */
    _u32 size_headers;          /*!< Size of Headers */
    _u32 checksum;              /*!< Checksum */
    _u16 subsystem;             /*!< Subsystem */
    _u16 dll_characteristics;   /*!< Dll Characteristics */
    _u32 size_stack_reserve;    /*!< Size of Stack Reserve */
    _u32 size_stack_commit;     /*!< Size of Stack Commit */
    _u32 size_heap_reserve;     /*!< Size of Heap Reserve */
    _u32 size_heap_commit;      /*!< Size of Heap Commit */
    _u32 loader_flags;          /*!< Loader Flags */
    _u32 nrva;                  /*!< Number of Rva and Sizes */
    PenetraDirectory directory[NUMBEROF_DIRECTORY_ENTRIES];
} PenetraOptional32;


/*! \struct PenetraOptional64
 *  \brief Stores all info about Optional Header (64 bits).
 */
typedef struct {
    _u16 magic;                 /*!< Architeture */
    _u8 major_linker;           /*!< Major Linker Version */
    _u8 minor_linker;           /*!< Minor Linker Version*/
    _u32 code_size;             /*!< Size of Code*/
    _u32 size_init_data;        /*!< Size of Initialized Data */
    _u32 size_uninit_data;      /*!< Size of Uniniatilized Data */
    _u32 entry_point;           /*!< Address Of Entry Point */
    _u32 base_code;             /*!< Base of Code */ 
    _u32 image_base;            /*!< Image Base */
    _u32 section_alignment;     /*!< Section Alignment */
    _u32 file_alignment;        /*!< File Alignment */
    _u16 major_os;              /*!< Major Operating System Version */
    _u16 minor_os;              /*!< Minor Operating System Version */
    _u16 major_image;           /*!< Major Image Version */
    _u16 minor_image;           /*!< Minor Image Version */
    _u16 major_subsystem;       /*!< Major Subsystem Version */
    _u16 minor_subsystem;       /*!< Minor Subsystem Version */
    _u32 reserved;              /*!< Reserverd1 */
    _u32 size_image;            /*!< Size of Image */
    _u32 size_headers;          /*!< Size of Headers */
    _u32 checksum;              /*!< Checksum */
    _u16 subsystem;             /*!< Subsystem */
    _u16 dll_characteristics;   /*!< Dll Characteristics */
    _u64 size_stack_reserve;    /*!< Size of Stack Reserve */
    _u64 size_stack_commit;     /*!< Size of Stack Commit */
    _u64 size_heap_reserve;     /*!< Size of Heap Reserve */
    _u64 size_heap_commit;      /*!< Size of Heap Commit */
    _u32 loader_flags;          /*!< Loader Flags */
    _u32 nrva;                  /*!< Number of Rva and Sizes */
    PenetraDirectory directory[NUMBEROF_DIRECTORY_ENTRIES];
} PenetraOptional64;


/*! \struct PenetraOptional
 *  \brief Stores all info about Optional Header (64 bits).
 */
typedef struct {
    /*! \union uopt
     *  \brief Union to store Optional Header 32 or 64 bits.
     */
    union {
        PenetraOptional32 opt32;  /*!< Optional Header 32 bits. */
        PenetraOptional64 opt64;  /*!< Optional Header 64 bits. */
    } uopt;
    _u16 arch;  /*!< Architeture: 32 or 64 bits. */
} PenetraOptional;


/*! Get the machine architeture.
 *
 * @param opt A valid PenetraOptional object.
 * @param magic The architeture saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_magic(PenetraOptional *opt, _u16 *magic);


/*! Get the major version number of the linker.
 *
 * @param opt A valid PenetraOptional object.
 * @param major The major version saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_major_linker(PenetraOptional *opt, 
                                              _u16 *major);


/*! Get The minor version number of the linker.
 *
 * @param opt A valid PenetraOptional object.
 * @param minor The minor version saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_minor_linker(PenetraOptional *opt, 
                                              _u16 *minor);


/*! Get the size of the code section, in bytes, or the sum of all
 *  such sections if there are multiple code sections.
 *
 * @param opt A valid PenetraOptional object.
 * @param size The size of code section saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_code_size(PenetraOptional *opt, _u32 *size);


/*! Get the size of the initialized data section, in bytes, or the 
 *  sum of all such sections if there are multiple initialized data sections.
 *
 * @param opt A valid PenetraOptional object.
 * @param size The size of the initialized data section saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_size_init_data(PenetraOptional *opt, 
                                                _u32 *size);


/*! Get the size of the uninitialized data section, in bytes, or the
 *  sum of all such sections if there are multiple uninitialized data
 *  sections.
 *
 * @param opt A valid PenetraOptional object.
 * @param size The size of the uninitialized data section saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_size_uninit_data(PenetraOptional *opt, 
                                                  _u32 *size);


/*! Get a pointer to the entry point function, relative to the image
 *  base address. For executable files, this is the starting address.
 *  For device drivers, this is the address of the initialization function.
 *  The entry point function is optional for DLLs. When no entry point is 
 *  present, this member is zero.
 *
 * @param opt A valid PenetraOptional object.
 * @param addr Entry point address saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_entry_point(PenetraOptional *opt, _u32 *addr);


/*! Get a pointer to the beginning of the code section, relative to the
 *  image base.
 *
 * @param opt A valid PenetraOptional object.
 * @param code Address od beginning code section saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_base_code(PenetraOptional *opt, _u32 *code);


/*! Get a pointer to the beginning of the data section, relative to the image
 *  base. (Only architeture 32 bits)
 *
 * @param opt A valid PenetraOptional object.
 * @param data Address of beginning data section saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_base_data(PenetraOptional *opt, _u32 *data);


/*! Get the preferred address of the first byte of the image when it is loaded
 *  in memory.
 *
 * @param opt A valid PenetraOptional object.
 * @param image Address of the first byte of the image saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_image_base(PenetraOptional *opt, _u32 *image);


/*! Get the alignment of sections loaded in memory, in bytes.
 *
 * @param opt A valid PenetraOptional object.
 * @param alignment The alignment of sections saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_section_alignment(PenetraOptional *opt,
                                                   _u32 *alignment);


/*! Get the alignment of the raw data of sections in the image file, in bytes.
 *
 * @param opt A valid PenetraOptional object.
 * @param alignment The alignment of the raw data of sections saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_file_alignment(PenetraOptional *opt, 
                                                _u32 *alignment);


/*! Get the major version number of the required operating system.
 *
 * @param opt A valid PenetraOptional object.
 * @param version The major version saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_major_os(PenetraOptional *opt, _u16 *version);


/*! Get the minor version number of the required operating system.
 *
 * @param opt A valid PenetraOptional object.
 * @param version The minor version saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_minor_os(PenetraOptional *opt, _u16 *version);


/*! Get the major version number of the image.
 *
 * @param opt A valid PenetraOptional object.
 * @param version The major version saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_major_image(PenetraOptional *opt, 
                                             _u16 *version);


/*! Get the mainor version number of the image.
 *
 * @param opt A valid PenetraOptional object.
 * @param version The minor version saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_minor_image(PenetraOptional *opt, 
                                             _u16 *version);


/*! Get the major version number of the subsystem.
 *
 * @param opt A valid PenetraOptional object.
 * @param version The major version saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_major_subsystem(PenetraOptional *opt,
                                                 _u16 *version);


/*! Get the minor version number of the subsystem.
 *
 * @param opt A valid PenetraOptional object.
 * @param version The minor version saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_minor_subsystem(PenetraOptional *opt, 
                                                 _u16 *version);


/*! This member is reserved and must be 0.
 *
 * @param opt A valid PenetraOptional object.
 * @param reserved WTF?
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_reserved(PenetraOptional *opt, _u32 *reserved);


/*! Get the size of the image, in bytes, including all headers.
 *
 * @param opt A valid PenetraOptional object.
 * @param size The size of the image saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_size_image(PenetraOptional *opt, _u32 *size);


/*! Get the combined size of the following items: e_lfanew, signature, 
 *  IMAGE_FILE_HEADER, optional header and size of all section headers.
 *
 * @param opt A valid PenetraOptional object.
 * @param size The combined size saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_size_headers(PenetraOptional *opt, _u32 *size);


/*! Get the image file checksum.
 *
 * @param opt A valid PenetraOptional object.
 * @param checksum The image file checksum saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_checksum(PenetraOptional *opt, _u32 *checksum);


/*! Get the subsystem required to run this image.
 *
 * @param opt A valid PenetraOptional object.
 * @param subsystem The subsystem saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_subsystem(PenetraOptional *opt, 
                                           _u16 *subsystem);


/*! Get the DLL characteristics of the image.
 *
 * @param opt A valid PenetraOptional object.
 * @param characteristics The DLL characteristics saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_characteristics(PenetraOptional *opt,
                                                 _u16 *characteristics);


/*! Get the number of bytes to reserve for the stack.
 *
 * @param opt A valid PenetraOptional object.
 * @param size The number of bytes saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_size_stack_reserve(PenetraOptional *opt,
                                                    _u64 *size);


/*! Get the number of bytes to commit for the stack.
 *
 * @param opt A valid PenetraOptional object.
 * @param size The number of bytes saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_size_stack_commit(PenetraOptional *opt,
                                                   _u64 *size);


/*! Get the number of bytes to reserve for the local heap.
 *
 * @param opt A valid PenetraOptional object.
 * @param size The number of bytes saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_size_heap_reserve(PenetraOptional *opt,
                                                  _u64 *size);


/*! Get the number of bytes to commit for the local heap.
 *
 * @param opt A valid PenetraOptional object.
 * @param size The number of bytes saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_size_heap_commit(PenetraOptional *opt,
                                                  _u64 *size);


/*! This member is obsolete.
 *
 * @param opt A valid PenetraOptional object.
 * @param flags Obsolete.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_loader_flags(PenetraOptional *opt,
                                              _u32 *flags);


/*! Get the number of directory entries in the remainder of the optional header.
 *
 * @param opt A valid PenetraOptional object.
 * @param rva The number of directory entries saved.
 *
 * @return PENETRA_SUCCESS in case of success, otherwise an ERROR.
 */
extern _u32 penetra_optional_get_rva(PenetraOptional *opt, _u32 *rva);


PENETRA_END_DECLS


#endif /* _PENETRA_OPTIONAL_H_ */
