#ifndef _PENETRA_H_
#define _PENETRA_H_

#include <stdbool.h>

#include "defines.h"
#include "error.h"
#include "types.h"

PENETRA_BEGIN_DECLS

typedef struct {
	_i32 fd;
	_u32 size;
	char *fname;
	_u8 alloc_type;
	_u8 *mem;
} Penetra;


/* 
 *
 *
 */
extern _u32 penetra_init(Penetra *pen);


/* 
 *
 *
 */
extern _u32 penetra_open(Penetra *pen, const char *fp);


/* 
 *
 *
 */
extern _u32 penetra_open_mmap(Penetra *pen, const char *fp);


/* 
 *
 *
 */
extern _u32 penetra_open_malloc(Penetra *pen, const char *fp);


/* 
 *
 *
 */
extern _u32 penetra_finish(Penetra *pen);

/* 
 *
 *
 */
extern _u32 penetra_is_pe(Penetra *pen);




/*GETTERS */


/* 
 *
 *
 */
extern _u32 penetra_get_alloc_type(Penetra *pen, _u8 *alloc_type);

/* SETTERS */


/* 
 *
 *
 */
extern _u32 penetra_set_alloc_type(Penetra *pen, _u8 alloc_type);

PENETRA_END_DECLS

#endif /* _PENETRA_H_ */
