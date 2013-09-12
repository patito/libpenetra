#include <string.h>

#include <penetra/dos.h>
#include <penetra/error.h>

_u32 penetra_dos_get_signature(PenetraDos *dos, char **signature)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;	
	}
	
	if (NULL == signature) {
		return PENETRA_EINVAL;
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
		return PENETRA_EINVAL;	
	}
	
	if (NULL == offset) {
		return PENETRA_EINVAL;
	}

	*offset = dos->e_lfanew;
		
	return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_e_cblp(PenetraDos *dos, _u16 *cblp)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == cblp) {
		return PENETRA_EINVAL;
	}

	*cblp = dos->e_cblp;
	
	return PENETRA_SUCCESS;
}


_u32 penetra_dos_get_e_cp(PenetraDos *dos, _u16 *cp)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == cp) {
		return PENETRA_EINVAL;
	}

	*cp = dos->e_cp;
	
	return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_e_crlc(PenetraDos *dos, _u16 *crlc)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == crlc) {
		return PENETRA_EINVAL;
	}

	*crlc = dos->e_crlc;
	
	return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_e_cparhdr(PenetraDos *dos, _u16 *cparhdr)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == cparhdr) {
		return PENETRA_EINVAL;
	}

	*cparhdr = dos->e_cparhdr;
	
	return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_e_minalloc(PenetraDos *dos, _u16 *minalloc)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == minalloc) {
		return PENETRA_EINVAL;
	}

	*minalloc = dos->e_minalloc;
	
	return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_e_maxalloc(PenetraDos *dos, _u16 *maxalloc)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == maxalloc) {
		return PENETRA_EINVAL;
	}

	*maxalloc = dos->e_maxalloc;
	
	return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_e_ss(PenetraDos *dos, _u16 *ss)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == ss) {
		return PENETRA_EINVAL;
	}

	*ss = dos->e_ss;
	
	return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_e_sp(PenetraDos *dos, _u16 *sp)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == sp) {
		return PENETRA_EINVAL;
	}

	*sp = dos->e_sp;
	
	return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_e_csum(PenetraDos *dos, _u16 *csum)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == csum) {
		return PENETRA_EINVAL;
	}

	*csum = dos->e_csum;
	
	return PENETRA_SUCCESS;
}


_u32 penetra_dos_get_e_ip(PenetraDos *dos, _u16 *ip)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == ip) {
		return PENETRA_EINVAL;
	}

	*ip = dos->e_ip;
	
	return PENETRA_SUCCESS;
}


_u32 penetra_dos_get_e_cs(PenetraDos *dos, _u16 *cs)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == cs) {
		return PENETRA_EINVAL;
	}

	*cs = dos->e_cs;
	
	return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_e_lfarlc(PenetraDos *dos, _u16 *lfarlc)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == lfarlc) {
		return PENETRA_EINVAL;
	}

	*lfarlc = dos->e_lfarlc;
	
	return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_e_ovno(PenetraDos *dos, _u16 *ovno)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == ovno) {
		return PENETRA_EINVAL;
	}

	*ovno = dos->e_ovno;
	
	return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_e_oemid(PenetraDos *dos, _u16 *oemid)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == oemid) {
		return PENETRA_EINVAL;
	}

	*oemid = dos->e_oemid;
	
	return PENETRA_SUCCESS;
}

_u32 penetra_dos_get_e_oeminfo(PenetraDos *dos, _u16 *oeminfo)
{
	if (NULL == dos) {
		return PENETRA_EINVAL;
	}

	if (NULL == oeminfo) {
		return PENETRA_EINVAL;
	}

	*oeminfo = dos->e_oeminfo;
	
	return PENETRA_SUCCESS;
}

