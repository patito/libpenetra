; ----------------------------------------------------------------------------
; helloworld.asm
;
; This is a Win32 console program that writes "Hello, World" on one line and
; then exits.  It needs to be linked with a C library.
; ----------------------------------------------------------------------------

        global  _main
        extern  printf

        section .text
_main:
        push    message
        call    printf
        add     esp, 4
        ret
message:
        db      'Hello, World', 10, 0
