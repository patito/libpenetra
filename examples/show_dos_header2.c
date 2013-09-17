/* Showing Dos Header Attributes without Getters. */
#include <stdio.h>

#include <penetra/penetra.h>

int main (int argc, char **argv)
{
	Penetra pen;
	PenetraDos dos;

	if (argc < 2) {
		printf("Usage: %s <bin>\n", argv[0]);
		return 1;
	}

	penetra_init(&pen);
	penetra_open(&pen, argv[1]);
	if (PENETRA_SUCCESS != penetra_is_pe(&pen)) {
		printf("Not a PE file!\n");
		penetra_finish(&pen);
    	return PENETRA_ERROR;
	}

	penetra_get_dos(&pen, &dos);

	printf("e_magic = %#x\n", dos.e_magic);
	printf("e_cblp = %d\n", dos.e_cblp);
	printf("e_cp = %d\n", dos.e_cp);
	printf("e_crlc = %d\n", dos.e_crlc);
	printf("e_cparhdr = %d\n", dos.e_cparhdr);
	printf("e_minalloc = %d\n", dos.e_minalloc);
	printf("e_maxalloc = %d\n", dos.e_maxalloc);
	printf("e_ss = %d\n", dos.e_ss);
	printf("e_sp = %#x\n", dos.e_sp);
	printf("e_csum = %d\n", dos.e_csum);
	printf("e_ip = %d\n", dos.e_ip);
	printf("e_cs = %d\n", dos.e_cs);
	printf("e_lfarlc = %#x\n", dos.e_lfarlc);
	printf("e_ovno = %d\n", dos.e_ovno);
	printf("e_oemid = %d\n", dos.e_oemid);
	printf("e_oeminfo = %d\n", dos.e_oeminfo);
	printf("e_lfanew = %#x\n", dos.e_lfanew);

	penetra_finish(&pen);

	return 0;
}
