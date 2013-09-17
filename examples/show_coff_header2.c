/* Showing Coff info without getters */

#include <stdio.h>

#include <penetra/penetra.h>

int main (int argc, char **argv)
{	
	Penetra pen;
	PenetraNT nt;
	PenetraCoff coff;

	if (argc < 2) {
 		printf("Usage: %s <pe-binary>\n", argv[0]);
		return 1;
	}

	penetra_init(&pen);
	penetra_open(&pen, argv[1]);

	if (PENETRA_SUCCESS != penetra_is_pe(&pen)) {
		printf("Not a PE File!\n");
		penetra_finish(&pen);
		return PENETRA_ERROR;
	}

	penetra_get_nt(&pen, &nt);
	penetra_nt_get_coff(nt, &coff);
	
	printf("Machine = %#x\n", coff.machine);
	printf("Number of Sections = %d\n", coff.nsections);

	penetra_finish(&pen);

	return 0;
}
