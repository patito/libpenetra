/* IMAGE_DOS_HEADER
 *
 * 
 */

#ifndef _PENETRA_COFF_H_
#define _PENETRA_COFF_H_

#include "types.h"


PENETRA_BEGIN_DECLS


typedef struct {
	_u16 arch;				/* Machine */
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
extern _u32 penetra_coff_get_arch(PenetraCoff *coff, _u16 *arch);


/*
 *
 *
 */
extern _u32 penetra_coff_get_nsections(PenetraCoff *coff, _u16 *nsections);


/*
 *
 *
 */
extern _u32 penetra_coff_get_tstamp(PenetraCoff *coff, _u16 *tstamp);


/*
 *
 *
 */
extern _u32 penetra_coff_get_symbol_table(PenetraCoff *coff, _u16 *symbol_table);


/*
 *
 *
 */
extern _u32 penetra_coff_get_nsymbols(PenetraCoff *coff, _u16 *nsymbols);


/*
 *
 *
 */
extern _u32 penetra_coff_get_size_opt_header(PenetraCoff *coff, _u16 *size);


/*
 *
 *
 */
extern _u32 penetra_coff_get_characteristics(PenetraCoff *coff, 
											 _u16 *characteristics);



PENETRA_END_DECLS


#endif /* _PENETRA_DOS_H_ */
