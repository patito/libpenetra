#include <stdio.h>
#include <penetra/penetra.h>

int main ()
{	
	Penetra pen;
	PenetraDos *dos;
	_u8 atype;
	_i32 offset;
	char *signature;
	_u16 cblp;
	_u16 cp;
	_u16 crlc;
	_u16 cparhdr;
	_u16 minalloc;
	_u16 maxalloc;
	_u16 ss;
	_u16 sp;
	_u16 csum;
	_u16 ip;
	_u16 cs;
	_u16 lfarlc;
	_u16 ovno;
	_u16 oemid;
	_u16 oeminfo;

	penetra_init(&pen);
	penetra_open_malloc(&pen, "/home/benatto/Downloads/putty.exe");
	
	if (PENETRA_SUCCESS == penetra_is_pe(&pen)) {
		printf("Is a PE file!\n");
	} else {
		printf("Is NOT a PE file!\n");
		return -1;
	}

	penetra_get_alloc_type(&pen, &atype);
	printf("Alloc Type = %d\n", atype);
	
	penetra_get_dos(&pen, &dos);

	penetra_dos_get_signature(dos, &signature);
	printf("e_magic = %c%c\n", signature[0], signature[1]);

	penetra_dos_get_e_cblp(dos, &cblp);
	printf("e_cblp = %d\n", cblp);
	
	penetra_dos_get_e_cp(dos, &cp);
	printf("e_cp = %d\n", cp);
	
	penetra_dos_get_e_crlc(dos, &crlc);
	printf("e_crlc = %d\n", crlc);

	penetra_dos_get_e_cparhdr(dos, &cparhdr);
	printf("e_cparhdr = %d\n", cparhdr);
	
	penetra_dos_get_e_minalloc(dos, &minalloc);
	printf("e_minalloc = %d\n", minalloc);

	penetra_dos_get_e_maxalloc(dos, &maxalloc);
	printf("e_maxalloc = %d\n", maxalloc);

	penetra_dos_get_e_ss(dos, &ss);
	printf("e_ss = %d\n", ss);

	penetra_dos_get_e_sp(dos, &sp);
	printf("e_sp = %#x\n", sp);

	penetra_dos_get_e_csum(dos, &csum);
	printf("e_csum = %d\n", csum);

	penetra_dos_get_e_ip(dos, &ip);
	printf("e_ip = %d\n", ip);

	penetra_dos_get_e_cs(dos, &cs);
	printf("e_cs = %d\n", cs);

	penetra_dos_get_e_lfarlc(dos, &lfarlc);
	printf("e_lfarlc = %#x\n", lfarlc);
	
	penetra_dos_get_e_ovno(dos, &ovno);
	printf("e_ovno = %d\n", ovno);

	penetra_dos_get_e_oemid(dos, &oemid);
	printf("e_oemid = %d\n", oemid);
	
	penetra_dos_get_e_oeminfo(dos, &oeminfo);
	printf("e_oeminfo = %d\n", oeminfo);

	penetra_dos_get_e_lfanew(dos, &offset);
	printf("e_lfanew = %#x\n", offset);

	penetra_finish(&pen);

	return 0;
}
