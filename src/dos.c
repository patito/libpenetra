#include <string.h>

#include <penetra/dos.h>
#include <penetra/error.h>

_u32 penetra_dos_get_signature(PenetraDos *dos, char **signature)
{
	if (NULL == dos) {
		return PENETRA_ERROR;	
	}
	
	if (NULL == signature) {
		return PENETRA_ERROR;
	}

	*signature = (char *)dos;

	return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_e_magic(PenetraDos *dos, char **signature)
{
	return penetra_dos_get_signature(dos, signature);
}

_u32 penetra_dos_get_e_lfanew(PenetraDos *dos, _i32 *offset)
{
	if (NULL == dos) {
		return PENETRA_ERROR;	
	}
	
	if (NULL == offset) {
		return PENETRA_ERROR;
	}

	*offset = dos->e_lfanew;
		
	return PENETRA_SUCCESS;
}


