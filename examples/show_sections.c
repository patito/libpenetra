#include <stdio.h>
#include <string.h>

#include <penetra/penetra.h>
#include <penetra/coff.h>
#include <penetra/nt.h>
#include <penetra/section.h>
#include <penetra/error.h>

int main (int argc, char** argv)
{
    Penetra pen;
    PenetraNT nt;
    PenetraCoff coff;
    PenetraOptional opt;
    PenetraDirectory dir;
    PenetraSection *section;
    _u16 nsec;
    _u16 nreloc;
    _u32 paddress;
    _u32 rva;
    _u32 offset;
    _u32 vaddress;
    _u32 rdsize;
    _u32 characteristics;
    _u32 rdpointer;
    _u16 i;
    _u8 name[8] = {0};

    if (argc < 2) {
        printf("Usage: %s <bin>\n", *argv);
        return 1;
    }

    penetra_init(&pen);
    penetra_open(&pen, argv[1]);

    if (PENETRA_SUCCESS != penetra_is_pe(&pen)) {
        return PENETRA_EINVALID_ARCH;
    }

    penetra_get_nt(&pen, &nt);
    penetra_nt_get_coff(&nt, &coff);
    penetra_coff_get_nsections(&coff, &nsec);
    penetra_get_section(&pen, &section);

    printf("--------------------------------------------\n");
	printf("Number Of Sections = %d\n", nsec);
    printf("--------------------------------------------\n");
    for (i = 0; i < nsec; i++) {
        penetra_section_get_name(section, name, i);
        printf("Name: %s\n", name);

        penetra_section_get_vaddress(section, &vaddress, i);
        printf("Virtual Address: %#x\n", vaddress);

        penetra_section_get_paddress(section, &paddress, i);
        printf("Physical Address: %#x\n", paddress);

        penetra_section_get_raw_data_size(section, &rdsize, i);
        printf("Raw Data Size: %d bytes\n", rdsize);

        penetra_section_get_raw_data_pointer(section, &rdpointer, i);
        printf("Raw Data Pointer: %#x\n", rdpointer);

        penetra_section_get_nrelocations(section, &nreloc, i);
        printf("Number Of Relocations: %d\n", nreloc);

        penetra_section_get_characteristics(section, &characteristics, i);
        printf("Characteristics: %#x\n", characteristics);
        
        printf("--------------------------------------------\n");
    }

    penetra_nt_get_optional(&nt, &opt);

    penetra_optional_get_directory(&opt, IMAGE_DIRECTORY_ENTRY_IMPORT, &dir);

    penetra_directory_get_rva(&dir, &rva);

    penetra_rva2ofs(&pen, rva, &offset);

    penetra_finish(&pen);

    return 0;
}
