/* Showing Coff info without getters */

#include <stdio.h>

#include <penetra/penetra.h>

int main ()
{	
	Penetra pen;
	PenetraCoff *coff;

	penetra_init(&pen);
	penetra_open_malloc(&pen, "/home/benatto/Downloads/putty.exe");

	penetra_get_coff(&pen, &coff);
	
	printf("Machine = %#x\n", coff->arch);

	penetra_finish(&pen);

	return 0;
}
