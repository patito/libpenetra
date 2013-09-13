#include <stdio.h>

#include <penetra/penetra.h>

int main ()
{	
	Penetra pen;
	PenetraCoff *coff;
	_u16 arch;

	penetra_init(&pen);
	penetra_open_malloc(&pen, "/home/benatto/Downloads/putty.exe");

	penetra_get_coff(&pen, &coff);
	
	penetra_coff_get_arch(coff, &arch);
	printf("Machine = %#x\n", arch);

	penetra_finish(&pen);

	return 0;
}
