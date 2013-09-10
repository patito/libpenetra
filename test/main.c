#include <stdio.h>
#include <penetra/penetra.h>

int main ()
{	
	Penetra pen;

	penetra_init(&pen);
	
	penetra_load(&pen, "/bin/ls");
	
	penetra_finish(&pen);

	return 0;
}
