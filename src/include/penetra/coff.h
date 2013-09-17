/* IMAGE_FILE/COFF_HEADER
 *
 * 
 */

#ifndef _PENETRA_COFF_H_
#define _PENETRA_COFF_H_

#include "types.h"


PENETRA_BEGIN_DECLS


typedef struct {
	_u16 machine;			/* Machine */
	_u16 nsections;			/* Number of Sections */
	_u32 tstamp;			/* Time Date Stamp*/
	_u32 symbol_table;		/* Pointer To Symbol Table */
	_u32 nsymbols;			/* Number of Symbols */
	_u16 size_opt_header;	/* Size of Optional Header */
	_u16 characteristics;	/* Characteristics */
} PenetraCoff;


typedef struct {
	char *meaning;
	_u32 value;
} MachineTable;


/* Get the machine architeture.
 *
 *
 */
extern _u32 penetra_coff_get_machine(PenetraCoff *coff, _u16 *machine);


/* Get the number of sections.
 *
 *
 */
extern _u32 penetra_coff_get_nsections(PenetraCoff *coff, _u16 *nsections);


/* Get the time date state
 *
 *
 */
extern _u32 penetra_coff_get_tstamp(PenetraCoff *coff, _u16 *tstamp);


/* Get file offset of the COFF symbol table
 *
 *
 */
extern _u32 penetra_coff_get_symbol_table(PenetraCoff *coff, _u16 *symbol_table);


/* Get the number of symbols.
 *
 *
 */
extern _u32 penetra_coff_get_nsymbols(PenetraCoff *coff, _u16 *nsymbols);


/* Get the size of optional header.
 *
 *
 */
extern _u32 penetra_coff_get_size_opt_header(PenetraCoff *coff, _u16 *size);


/* Get flags with information about the file.
 *
 *
 */
extern _u32 penetra_coff_get_characteristics(PenetraCoff *coff, 
											 _u16 *characteristics);



PENETRA_END_DECLS


#endif /* _PENETRA_DOS_H_ */
