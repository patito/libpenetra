#include <stdio.h>

#include <penetra/penetra.h>
#include <penetra/nt.h>

int main (int argc, char **argv)
{	
	Penetra pen;
	PenetraNT nt;
	PenetraCoff coff;
	_u16 machine;
	_u16 nsections;

	if (argc < 2) {
    	printf("Usage: %s <pe-binary>\n", argv[0]);
    	return 1;
	}

	penetra_init(&pen);
	penetra_open(&pen, argv[1]);

	if (PENETRA_SUCCESS != penetra_is_pe(&pen)) {
		printf("NOT a PE File!\n");
		penetra_finish(&pen);
		return PENETRA_ERROR;
	}
	
	penetra_get_nt(&pen, &nt);
	penetra_nt_get_coff(&nt, &coff);
	
	penetra_coff_get_machine(&coff, &machine);
	printf("Machine = %#x\n", machine);

	penetra_coff_get_nsections(&coff, &nsections);
	printf("Number of Sections = %d\n", nsections);
	

	penetra_finish(&pen);

	return 0;
}
