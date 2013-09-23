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

	printf("magic = %#x\n", dos.magic);
	printf("cblp = %d\n", dos.cblp);
	printf("cp = %d\n", dos.cp);
	printf("crlc = %d\n", dos.crlc);
	printf("cparhdr = %d\n", dos.cparhdr);
	printf("minalloc = %d\n", dos.minalloc);
	printf("maxalloc = %d\n", dos.maxalloc);
	printf("ss = %d\n", dos.ss);
	printf("sp = %#x\n", dos.sp);
	printf("csum = %d\n", dos.csum);
	printf("ip = %d\n", dos.ip);
	printf("cs = %d\n", dos.cs);
	printf("lfarlc = %#x\n", dos.lfarlc);
	printf("ovno = %d\n", dos.ovno);
	printf("oemid = %d\n", dos.oemid);
	printf("oeminfo = %d\n", dos.oeminfo);
	printf("lfanew = %#x\n", dos.lfanew);

	penetra_finish(&pen);

	return 0;
}
