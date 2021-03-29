; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
; To assemble and run:
;
;     nasm -felf64 hello.asm && ld hello.o && ./a.out
; ----------------------------------------------------------------------------------------

section .text
    global _start ; RAX RCX RDX RBX RSP RBP RSI RDI

_start :
    mov rax,13 ;registre de longueur du msg
    mov rcx,msg ;registre dans lequel ont met le message
    mov rdx,1 ;sortie du msg, stdout
    mov rbx,4 ;numero de l'appel systeme (sys_write)
    int 0x80  ;appel noyeau

    mov rbx,1 ;system call number (sys exit)
    syscall ;appel noyau

section .data
    msg db "Hello world!",10