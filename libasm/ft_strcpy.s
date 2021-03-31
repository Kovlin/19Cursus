; ----------------------------------------------------------------------------------------
; ft_strcpy in Assembly x86_64 | Works for Linux
; To assemble :
;
;     nasm -felf64 ft_strcpy.s
;     By rlinkov@student.s19.be
; ----------------------------------------------------------------------------------------

section .text:
    global ft_strcpy

ft_strcpy:
    mov rax,0   ; on initialise rax à 0 qui nous servira de compteur
                ; la destination se trouve dans RDI et la source dans RSI (conventions d'appel)
    jmp copy    ; on saute à la fonction de copie

copy:
    cmp BYTE    [rdi + rax],0           ; on compare la position actuelle dans la source et le caractère nul
    je  exit                            ; on saute à la fonction de sortie si on est au bout de la source
    
    mov r11, [rdi + rax]
    mov [rsi + rax], r11
    
    ;mov         [rsi + rax],[rdi + rax] ; on copie le caractère de la source vers la destination
    inc         rax                     ; on incrémente rax de 1
    jmp         copy                    ; on retourne au début de la fonction copy

exit:
    mov BYTE    [rdi + rax], 0x0        ; on force le \0 la fin de la destination
    ret                                 ; met fin à la fonction, la valeur contenue dans rax est renvoyée par la fonction