###########################################################################
# Some rules for building asm files:

SUFFIXES = .asm

.asm.o:
	nasm -f bin $< -o $@
###########################################################################

bin_PROGRAMS = 	is_pe_file \
		show_coff_header \
		show_coff_header2 \
		show_dos_header \
		show_dos_header2



# hack to force automake to don't link the assembled binary
text_section_LINK = 	@cp text_section.o text_section.bin; \
			echo "link a flat binary? hacking autohell ..."

is_pe_file_SOURCES = is_pe_file.c
show_coff_header_SOURCES = show_coff_header.c
show_coff_header2_SOURCES = show_coff_header2.c
show_dos_header_SOURCES = show_dos_header.c
show_dos_header2_SOURCES = show_dos_header2.c

AM_CFLAGS = -ggdb -Wall -Wextra -Werror -I../src/include
LDADD = -L../src/.libs -lpenetra
