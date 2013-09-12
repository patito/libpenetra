#include <string.h>

#include <penetra/dos.h>
#include <penetra/error.h>

_u32 penetra_dos_get_signature(PenetraDos *dos, char *buffer, _u32 len)
{
	if (NULL == dos) {
		return PENETRA_ERROR;	
	}
	
	if (NULL == buffer) {
		return PENETRA_ERROR;
	}

	if (0 == len) {
		len = 2;
	}

	if (NULL == strncpy(buffer, (const char*)dos, len)) {
		return PENETRA_ERROR;
	}

	buffer[2] = '\0';

	return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_e_magic(PenetraDos *dos, char *buffer, _u32 len)
{
	return penetra_dos_get_signature(dos, buffer, len);
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


