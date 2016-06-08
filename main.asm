


iniciastring:
        xor ebx,ebx
ini:    cmp byte [ecx],' '
        je  fim1
        cmp byte [ecx],'-'
        jne lab1
        mov ebx,1
        jmp fim1
lab1:   cmp byte [ecx],'+'
        je  fim1
        cmp byte [ecx],'0'
        jl  error
        cmp byte [ecx],'9'
        jg  error
        xor eax,eax
        mov edx,10
        push ebx
        call pega1num
        pop ebx
        cmp ebx,1
        jne pulaop
        neg eax
pulaop: jmp pegaoperador
fim1:   inc ecx
        jmp ini
pega1num:
        cmp byte [ecx],'0'
        jl  fimpega1num
        cmp byte [ecx],'9'
        jg  fimpega1num
        mul edx
        xor ebx,ebx
        sub byte [ecx],'0'
        mov bl,[ecx]
        add eax,ebx
        inc ecx
        jmp pega1num
fimpega1num:
    
        ret

pegaoperador:
        cmp     byte [ecx],' '
        je      fim2
        cmp     byte [ecx],'-'
        jne     labo2
        mov     edx,1
        jmp     pega2num
labo2:  cmp     byte [ecx],'+'
        jne     labo3
        mov     edx,2
        jmp     pega2num
labo3:  cmp     byte [ecx],'/'
        jne     labo4
        mov     edx,3
        jmp     pega2num
labo4:  cmp     byte [ecx],'*'
        jne     error
        mov     edx,4
        jmp     pega2num
fim2:   inc     ecx
        jmp     pegaoperador




ini2:   cmp byte [ecx],' '
        je  fim3
        cmp byte [ecx],'-'
        jne lab3
        mov ebx,1
        jmp fim3
lab3:   cmp byte [ecx],'+'
        je  fim3
        cmp byte [ecx],'0'
        jl  error
        cmp byte [ecx],'9'
        jg  error
        push eax
        push edx
        push ebx
        mov edx,10
        call pega2num
        pop ebx
        cmp ebx,1
        jne pops
        neg eax
pops:   pop edx
        pop ebx
        xchg eax,ebx
        jmp operacao
fim3:    inc ecx
        jmp ini

pega2num:
        cmp byte [ecx],'0'
        jl  fimpega2num
        cmp byte [ecx],'9'
        jg  fimpega2num
        mul edx
        xor ebx,ebx
        sub byte [ecx],'0'
        mov bl,[ecx]
        add eax,ebx
        inc ecx
        jmp pega2num
fimpega2num:
        ret



operacao:
        cmp edx,1
        jne pop2
        add eax,ebx
        jmp fim4
pop2:   cmp edx,2
        jne pop3
        sub ebx,eax
        mov eax,ebx
        jmp fim4
pop3:   cmp edx,3
        jne pop4
        div ebx
        jmp fim4
pop4:   mul ebx

fim4:   ret 

