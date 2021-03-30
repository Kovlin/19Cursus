; ----------------------------------------------------------------------------------------
; ft_strlen in Assembly x86_64 | Works for Linux
; To assemble and run:
;
;     nasm -felf64 ft_strlen.s && ld ft_strlen.o && ./a.out
; ----------------------------------------------------------------------------------------

section .text:
    global _start

_start:
    mov rax,0 ; on initialise la longueur a 0 dans rcx
    cmp rdi,0 ; on compare le premier caractere de rdi
    je  exit  ; quitte le programme si premier caractere est 0
    jmp count ;si on a une chaine on va compter

count:
    inc rax ;on incremente rcx
    inc rdi ;on avance sur rdi
    cmp rdi,0 
    je exit
    jmp count

exit:
    mov r9,rax ;on met la valeur de rax dans r9
    mov rax,1 ;on prepare le write
    mov r9, [r9 + 47] ;on met le chiffre en lettre
    mov rdi,1
    mov rsi,r9
    mov rdx,1
    syscall
    mov rax, 60
    syscall
    ;ret
