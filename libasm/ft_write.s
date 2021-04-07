; ----------------------------------------------------------------------------------------
; ft_write in Assembly x86_64 | Works for Linux
; To assemble :
;
;     nasm -felf64 ft_write.s
;     By rlinkov@student.s19.be
; ----------------------------------------------------------------------------------------

extern __errno_location ;déclaration de l'accès à la variable globale errno de errno.h

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
    neg             rax         ; la valeur opposée à errno se retrouve dans rax (sous Linux)
                                ; on fait donc rax *-1 pour récupérer sa valeur
    push            rax         ; on push la valeur de rax sur la stack
    call    __errno_location    ; on appelle ___errno_location, on récupère donc le pointeur
                                ; de errno dans rax
    pop     qword   [rax]       ; on récupère la valeur push de rax dans [rax],
                                ; on met donc la valeur de rax push auparavant là où pointe errno
    
    ; mov     [rax],
    ; mov r12, rax ; on met le contenu de rax dans r12
    ; push rax; on push le contenu de rax sur la stack
    ; call    __errno_location ;rax pointe mtn sur errno
    ; mov rax , r12 ; on met le contenu de r12 dans errno
    ; pop rax ; on recupere le contenu du haut de la stack dans rax (on repointe dessus)
    ;         ;errno a changé et on renvoi le -1 apres


    mov rax,-1      ; on met rax à -1 car c'est la valeur à retourner en cas d'erreur
    ret             ; on retourne à la fonction d'appel