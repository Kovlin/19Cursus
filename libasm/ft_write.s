; ----------------------------------------------------------------------------------------
; ft_write in Assembly x86_64 | Works for Linux
; To assemble :
;
;     nasm -felf64 ft_write.s
;     By rlinkov@student.s19.be
; ----------------------------------------------------------------------------------------

extern __errno_location

section .text:
    global ft_write

ft_write:
    mov rax,1       ; le code de l'appel système write est 1
    syscall         ; on appelle la fonction associée au code passé à rax
    cmp rax,0       ; on évalue rax par rapport à 0
    jl  exit_error  ; si rax est inférieur à 0, il y a eu une erreur
                    ; on saute à la fonction de gestion de l'erreur
    ret             ; si tout ce passe bien, on retourne à la fonction d'appel

exit_error:
    neg rax         ; la valeur opposée à errno se retrouve dans rax (sous Linux)
                    ; on fait donc rax *-1 pour récupérer sa valeur
    mov rcx,rax

    mov rax,-1      ; on met rax à -1 car c'est la valeur à retourner en cas d'erreur
    ret             ; on retourne à la fonction d'appel