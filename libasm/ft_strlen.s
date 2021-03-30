; ----------------------------------------------------------------------------------------
; ft_strlen in Assembly x86_64 | Works for Linux
; To assemble and run:
;
;     nasm -felf64 ft_strlen.s && ld ft_strlen.o && ./a.out
; ----------------------------------------------------------------------------------------

section .text:
    global _start

_start:
    mov rcx,0 ; on initialise la longueur a 0 dans rcx
    cmp rdi,0 ; on compare le premier caractere de rdi
    je  _exit  ; quitte le programme si premier caractere est 0
    jmp _count ;si on a une chaine on va compter

_count:
    inc rcx ;on incremente rcx
    inc rdi ;on avance sur rdi
    cmp rdi,0 
    je _exit
    jmp _count

_exit:
    ret
