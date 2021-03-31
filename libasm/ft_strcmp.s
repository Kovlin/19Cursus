; ----------------------------------------------------------------------------------------
; ft_strcmp in Assembly x86_64 | Works for Linux
; To assemble :
;
;     nasm -felf64 ft_strcmp.s
;     By rlinkov@student.s19.be
; ----------------------------------------------------------------------------------------

;return *s1 - *s2 => [RDI] - [RSI]

section .text:
    global ft_strcmp

ft_strcmp:
    mov rax,0   ; on utilisera rax comme index, on l'initialise donc à 0
    jmp compare ; on saute à la fonction de comparaison

compare:
    mov r10,BYTE    [rdi + rax] ; on place le caractère actuel de la chaîne 1 dans le registre r10
    mov r11,BYTE    [rsi + rax] ; on place le caractère actuel de la chaîne 2 dans le registre r11
    cmp r10,0                   ; on vérifie si on est en bout de chaîne 1
    je  exit                    ; si on est en bout de chaîne on saute à la fonction exit
    cmp r11,0                   ; on vérifie si on est en bout de chaîne 2
    je  exit                    ; si on est en bout de chaîne on saute à la fonction exit
    cmp r10,r11                 ; on compare le caractère actuel des deux chaînes
    jne exit                    ; si ils sont différents on saute à la fonction exit
    inc rax                     ; on incrémente rax de 1
    jmp compare                 ; on saute au début de la fonction compare


exit:
    sub r10,r11 ; on soustrait à la valeur du caractère de la chaîne 1 celle du caractère de la chaîne 2
    mov rax,r10 ; on met dans rax la valeur à retourner
    ret         ; met fin à la fonction, la valeur contenue dans rax est renvoyée par la fonction          