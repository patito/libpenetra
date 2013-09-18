#include <stdio.h>
#include <string.h>

#include <penetra/penetra.h>

int main (int argc, char** argv)
{
	Penetra pen;
	PenetraNT nt;
	PenetraOptional opt;
	_u16 magic;
	_u32 sheaders;

	if (argc < 2) {
		printf("Usage: %s <bin>\n", *argv);
		return 1;
	}

	penetra_init(&pen);
	penetra_open(&pen, argv[1]);

	if (PENETRA_SUCCESS != penetra_is_pe(&pen)) {
		penetra_finish(&pen);
		return PENETRA_ENOT_PE;
	}

	penetra_get_nt(&pen, &nt);

	penetra_nt_get_optional(&nt, &opt);

	penetra_optional_get_magic(&opt, &magic);
	printf("Magic = %#x\n", magic);
	
	penetra_optional_get_size_headers(&opt, &sheaders);
	printf("Size Of Headers = %#x\n", sheaders);

	penetra_finish(&pen);

	return 0;
}
