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

/*! \file defines.h
 *  \brief Our macros used on the project.
 */

#ifndef _PENETRA_DEFINES_H_
#define _PENETRA_DEFINES_H_

/*! \def PENETRA_BEGIN_DECLS
 *  \brief A macro that verify __cpluscplus (extern C)
 *
 *  PENETRA_BEGIN_DECLS should be used at the beginnning of your declarations,
 *  so that C++ don't mangle their names. Use PENETRA_END_DECLS at the end of
 *  C declarations.
 */
#ifdef __cplusplus
# define PENETRA_BEGIN_DECLS extern "C" {
# define PENETRA_END_DECLS }
#else
# define PENETRA_BEGIN_DECLS /*  empty */
# define PENETRA_END_DECLS /*  empty */
#endif


/*  Unused variables */
#define UNUSED(x) (void)x


/*! \def PENETRA_ALLOC_NONE
 *  \brief A macro that defines none alloc type.
 */
#define PENETRA_ALLOC_NONE  0

/*! \def PENETRA_ALLOC_MMAP
 *  \brief A macro that defines mmap as the alloc type.
 */
#define PENETRA_ALLOC_MMAP  1

/*! \def PENETRA_ALLOC_MALLOC
 *  \brief A macro that defines malloc as the alloc type.
 */
#define PENETRA_ALLOC_MALLOC 2

/*! \def MZ_SIGNATURE
 *  \brief A macro that stores the MZ Signature: 0x5a4d.
 */
#define MZ_SIGNATURE 0x5a4d

/*! \def SIZEOF_NT_SIGNATURE
 *  \brief A macro that stores the size of NT Signature 4 bytes.
 */
#define SIZEOF_NT_SIGNATURE 4

/*! \def NT_SIGNATURE
 *  \brief A macro that stores the NT Signature: 0x4550.
 */
#define NT_SIGNATURE 0x4550

/*! \def PE_ARCH32
 *  \brief A macro that stores the PE architeture 32 bits: 0x10b.
 */
#define PE_ARCH32 0x10b

/*! \def PE_ARCH64
 *  \brief A macro that stores the PE architeture 64 bits: 0x20b.
 */
#define PE_ARCH64 0x20b

/*! \def NUMBEROF_DIRECTORY_ENTRIES
 *  \brief A macro that stores the number of directories entry.
 */
#define NUMBEROF_DIRECTORY_ENTRIES 16

#endif /* _PENETRA_DEFINES_H_ */
