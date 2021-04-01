; ----------------------------------------------------------------------------------------
; ft_write in Assembly x86_64 | Works for Linux
; To assemble :
;
;     nasm -felf64 ft_write.s
;     By rlinkov@student.s19.be
; ----------------------------------------------------------------------------------------
; ssize_t write(int fd, const void *buf, size_t count)
; syscall param : RDI, RSI, RDX
; erreur errno

section .text:
    global ft_write

ft_write:
    mov rax,1 ; le code de l'appel système write est 1
    syscall
    ret