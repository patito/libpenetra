#include <stdio.h>
#include <penetra/penetra.h>

int main ()
{	
	Penetra pen;
	bool st;

	penetra_init(&pen);
	
	penetra_open(&pen, "/home/benatto/Downloads/putty.exe");
	
	if (PENETRA_SUCCESS == penetra_is_pe(&pen)) {
		printf("Is a PE file!\n");
	}

	penetra_finish(&pen);

	return 0;
}
