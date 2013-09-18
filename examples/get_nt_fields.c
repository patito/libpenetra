#include <stdio.h>
#include <string.h>

#include <penetra/penetra.h>
#include <penetra/nt.h>

int main (int argc, char** argv)
{
	Penetra pen;
	PenetraNT nt;
	PenetraCoff coff;
	PenetraOptional opt;
	_u16 signature;

	if (argc < 2) {
		printf("Usage: %s <pe-binary>\n", "./get_nt_fields");
		return 1;
	}

	if (PENETRA_SUCCESS != penetra_init(&pen)) {
 		printf("[ERROR] Trying to initialize penetra object!\n");
		goto _out;
	}

	if (PENETRA_SUCCESS != penetra_open(&pen, argv[1])) {
 		printf("[ERROR] Trying to open binary PE file!\n");
		goto _out;
	}

	if (PENETRA_SUCCESS != penetra_is_pe(&pen)) {
 		printf("[ERROR] NOT a PE file!\n");
		goto _out;
	}

	if (PENETRA_SUCCESS != penetra_get_nt(&pen, &nt)) {
 		printf("[ERROR] Trying get NT Header!\n");
		goto _out;
	}

	if (PENETRA_SUCCESS != penetra_nt_get_signature(&nt, &signature)) {
 		printf("[ERROR] Trying get NT Signature!\n");
		goto _out;
	} else {
		printf("NT Signature = %#x\n", signature);
	}

	if (PENETRA_SUCCESS != penetra_nt_get_optional(&nt, &opt)) {
 		printf("[ERROR] Trying get Optional Header!\n");
		goto _out;
	} else {
		if (PE_ARCH32 == opt.arch) {
			printf("Optional32 Magic = %#x\n", opt.uopt.opt32.magic);
		} else {
			printf("Optional64 Magic = %#x\n", opt.uopt.opt64.magic);
		}
	}

	if (PENETRA_SUCCESS != penetra_nt_get_coff(&nt, &coff)) {
 		printf("[ERROR] Trying get Coff Header!\n");
		goto _out;
	} else {
		printf("Machine = %#x\n", coff.machine);
	}

	return PENETRA_SUCCESS;

_out:
	penetra_finish(&pen);
	return PENETRA_ERROR;
}
