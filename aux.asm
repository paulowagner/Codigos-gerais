format ELF

section '.text' executable
public inicia
public livreDouble
public livreNotDouble

public constDouble
;public constNotDouble

;public funcDouble
;public funcNotDouble
public callEnd
extrn create2
extrn malloc
public create
extrn  imprimi

create:     push    ebp
            mov     ebp,esp
            push    1024
            call    malloc
            add     esp,4
            push    eax
            push    dword [ebp+20]
            push    dword [ebp+16]
            push    dword [ebp+12]
            push    dword [ebp+8]
            call    create2
            add     esp,16
            call    imprimi
            pop     eax
            pop     ebp
            ret

inicia:     
            push    ebp
            mov     ebp,esp

            mov     eax,[ebp+8]             ; valor de k (inicialmente 0)
            mov     ebx,[ebp+12]            ; vetor v[]


            mov     byte [ebx],0x55         ;push ebp
            mov     word [ebx+1],0xe589     ;mov ebp,esp
            add     ebx,3                   ;v[3]
            add     eax,3                   ;eax=3

            pop     ebp
            ret


livreDouble:        
            push    ebp
            mov     ebp,esp

            mov     eax,[ebp+8]         ; valor de k
            mov     ebx,[ebp+12]        ; vetor v[]
            mov     ecx,[ebp+16]        ; desl
            add     ebx,eax             ; v[k]

            mov     word [ebx],0x75ff   ;push ..
            mov     [ebx+2],ecx         ; .. dword [ebp+desl]
            add     ebx,3
            add     eax,3
            sub     ecx,4
            mov     word [ebx],0x75ff   ;push ..
            mov     [ebx+2],ecx         ; .. dword [ebp+desl]
            add     ebx,3
            add     eax,3

            pop     ebp
            ret

livreNotDouble:
            push    ebp
            mov     ebp,esp

            mov     eax,[ebp+8]         ; valor de k
            mov     ebx,[ebp+12]        ; vetor v[]
            mov     ecx,[ebp+16]        ; desl
            add     ebx,eax             ; v[k]

            mov     word [ebx],0x75ff   ;push ..
            mov     [ebx+2],ecx         ; .. dword [ebp+desl]
            add     ebx,3
            add     eax,3

            pop     ebp
            ret

constDouble: 
            push    ebp
            mov     ebp,esp

            mov     eax,[ebp+8]         ; valor de k
            mov     ebx,[ebp+12]        ; vetor v[]
            mov     ecx,[ebp+16]        ; desl
            add     ebx,eax             ; v[k]
            mov     edx,[ebp+24]        ; valor da constante primeira parte
            mov     byte [ebx],0x68     ;push ..
            mov     [ebx+1],edx         ; .. const
            add     ebx,5
            add     eax,5
            mov     edx,[ebp+20]        ; valor da constante segunda parte parte
            mov     byte [ebx],0x68     ;push ..
            mov     [ebx+1],edx         ; .. const
            add     ebx,5
            add     eax,5

            pop     ebp
            ret

callEnd: 
            push    ebp
            mov     ebp,esp

            mov     ebx,[ebp+12]        ; vetor v[]
            mov     eax,[ebp+16]        ; valor de k
            mov     ecx,[ebp+8]         ; func void *f 
            add     ebx,eax             ;{
            sub     ecx,5               ;{  
            sub     ecx,ebx             ;{ calculo endereço relativo
            mov     byte [ebx],0xe8     ;{ call ..
            mov     [ebx+1],ecx         ;{ .. void *f
            
            add     ebx,5
            add     eax,5
            mov     word [ebx],0xc483   ;add esp,..
            mov     byte [ebx+2],16    ; .. 16
            add     ebx,3
            add     eax,3
            mov     word [ebx],0xec89     ;mov esp,ebp    
            mov     byte [ebx+2],0x5d   ;pop ebp
            mov     byte [ebx+3],0xc3   ;ret
            add     ebx,4
            add     eax,4

            pop     ebp
            ret
