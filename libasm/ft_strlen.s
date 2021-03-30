; ----------------------------------------------------------------------------------------
; ft_strlen in Assembly x86_64 | Works for Linux
; To assemble and run:
;
;     nasm -felf64 ft_strlen.s && ld ft_strlen.o && ./a.out
; ----------------------------------------------------------------------------------------

section .text:
    global ft_strlen

ft_strlen:
    mov rax,0 ; on initialise la longueur a 0 dans rcx
    cmp BYTE [rdi + rax],0 ; on compare le premier caractere de rdi
    je  exit  ; quitte le programme si premier caractere est 0
    jmp count ;si on a une chaine on va compter

count:
    inc rax ;on incremente rcx
    cmp BYTE [rdi + rax],0 
    je exit
    jmp count

exit:
    ret
