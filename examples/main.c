#include <stdio.h>
#include <penetra/penetra.h>

int main ()
{	
	Penetra pen;
	PenetraDos *dos;
	_u8 atype;
	_i32 offset;
	char *signature;

	penetra_init(&pen);
	penetra_open_malloc(&pen, "/home/benatto/Downloads/putty.exe");
	
	if (PENETRA_SUCCESS == penetra_is_pe(&pen)) {
		printf("Is a PE file!\n");
	} else {
		printf("Is NOT a PE file!\n");
	}

	penetra_get_alloc_type(&pen, &atype);
	printf("Alloc Type = %d\n", atype);
	
	penetra_get_dos(&pen, &dos);

	penetra_dos_get_signature(dos, &signature);
	printf("Signature = %c\n", signature[0]);
	printf("Signature = %c\n", signature[1]);

	penetra_dos_get_e_lfanew(dos, &offset);
	printf("PE Header Offset = 0x%08x\n", offset);


	penetra_finish(&pen);

	return 0;
}
