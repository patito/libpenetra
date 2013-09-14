###########################################################################
# Some rules for building asm files:

SUFFIXES = .asm

.asm.o:
	nasm -fwin32 $< -o $@
###########################################################################

bin_PROGRAMS = hello_asm

hello_asm_SOURCES = hello.asm

AM_CFLAGS = -Wall -Wextra -Werror
uninfected_asm_LINK = ld /lib/i386-linux-gnu/libc-2* -o hello_asm
