#include <stdio.h>

#include <penetra/penetra.h>

int main ()
{	
	Penetra pen;
	PenetraCoff *coff;
	_u16 machine;

	penetra_init(&pen);
	penetra_open_malloc(&pen, "/home/benatto/Downloads/putty.exe");

	if (PENETRA_SUCCESS == penetra_is_pe(&pen)) {
		printf("Is a PE file!\n");
	} else {
 		printf("Is NOT a PE file!\n");
	}

	penetra_finish(&pen);

	return 0;
}
