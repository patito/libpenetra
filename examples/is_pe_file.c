#include <stdio.h>

#include <penetra/penetra.h>

int main (int argc, char** argv)
{
	Penetra pen;

        if (argc < 2) {
                printf("Usage: %s <bin>\n", *argv);
                return 1;
        }

	penetra_init(&pen);
	penetra_open_malloc(&pen, argv[1]);

	if (PENETRA_SUCCESS == penetra_is_pe(&pen)) {
		printf("Is a PE file!\n");
	} else {
 		printf("Is NOT a PE file!\n");
	}

	penetra_finish(&pen);

	return 0;
}
