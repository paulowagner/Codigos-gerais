format ELF
section '.text' executable
public create
extrn	malloc

create:	push 		ebp
		mov		ebp,esp
		push		19				
		call 		malloc		   ;Aloca 19 bytes de espaço
		add		esp,4
		mov         ecx,[ebp+8]	         ;Calculo do
		sub		ecx,14		   ;endereço 
		sub		ecx,eax		   ;relativo   ecx-=(eax+14)
		mov		byte [eax],0x55 	   ;push ebp
		mov		word [eax+1],0xe589  ;mov ebp,esp
		mov		word [eax+3],0x75ff  ;push ..
		mov		byte [eax+5],0x08	   ; .. dword [ebp+8]
		mov		word [eax+6],0x75ff  ;push ..
		mov		byte [eax+8],0x0c	   ; .. dword [ebp+12]
		mov		byte [eax+9],0xe8    ;call ..
		mov		[eax+10],ecx 	   ; .. soma
		mov		word [eax+14],0xc483 ;add esp,..
		mov		byte [eax+16],08	   ; .. 8
		mov		byte [eax+17],0x5d   ;pop	ebp
		mov		byte [eax+18],0xc3   ;ret
		pop		ebp
		ret

create2:	push		ebp
		mov		ebp,esp
		push		esi
		mov		ecx,[ebp+16]
		jecxz		sempar
		mov		ebx,[ebp+20]
		push		1024				
		call 		malloc		   ;Aloca 19 bytes de espaço
		add		esp,4
		xor		esi,esi
		push 		0
inipar:	cmp		dword [ebx],1
		ja 		funcao
		je 		const
		cmp		dword [ebx+4],4
		jne		quatro
		add		dword	[esp],6
		mov		dword [eax+esi*4],8
		inc		esi
		jmp 		looppar
quatro:	mov		dword [eax+esi*4],4
		inc		esi
		add		dword	[esp],3
		jmp		looppar
const:	mov		dword [eax+esi*4],2
		add		dword	[esp],5
		cmp		dword [ebx+4],4
		jne		notdou
		add		dword	[esp],5
		inc		dword [eax+esi*4]
notdou:	inc		esi
		jmp 		looppar
funcao:	mov		edx,[ebx+8]
		push		ecx
		mov		ecx,[edx-4]
		jecxz		fimverf
		shl		ecx,2
		sub		edx,8
		sub		edx,ecx
		shr		ecx,2
voltaver:   cmp 		dword [edx],2
		je		loopver
		cmp         dword [edx],1
		jne  		verq
		add 		edx,4
		jmp 		loopver
verq:		mov		dword [eax+esi*4],4
		add		dword	[esp],3
		cmp         dword [edx],8
		jne 		nehoito
		add		dword	[esp],3
		add		dword [eax+esi*4],4
ehoito:	inc 		esi
loopver:	add		edx,4
		loop 		voltaver
fimverf:	mov		ecx,[edx]
		add		dword	[esp],8
		
		mov		dword [eax+esi*4],1
		mov		dword [eax+esi*4],ecx
		pop		ecx
looppar:	add		ebx,16
		loop 		inipar
		mov		ecx,[ebp+12]
		mov         dword [eax+esi*4],ecx
		inc		esi
		mov         dword [eax+esi*4],esi
		inc         dword [eax+esi*4],1
		shl         dword [eax+esi*4],2
		add		eax,[eax+esi*4]
		xor 		esi,esi
		mov		byte [eax],0x55 	   ;push ebp
		mov		word [eax+1],0xe589  ;mov ebp,esp
            cmp		[eax-4],8
            jbe 		calcrel
            mov		ebx,eax
            sub		ebx,[eax-4]
            mov		ecx,[eax-4]
            sub		ecx,8
            shr		ecx,2
loopes:     cmp		dword [ebx],8
		jne        	testeq
		mov		word [eax+esi],0x75ff  ;push ..
		mov		byte [eax+esi+2],0x08	   ; .. dword [ebp+8]
		mov		word [eax+esi+3],0x75ff  ;push ..
		mov		byte [eax+esi+5],0x0c	   ; .. dword [ebp+12]
		add		esi,6


calcrel:	mov         edx,[ebp+8]	         ;Calculo do
		sub		edx,14		   ;endereço 
		sub		edx,eax		   ;relativo
		mov		byte [eax+esi],0xe8    ;call ..
		mov		[eax+esi],edx 	   ; .. soma
		mov		word [eax+esi],0xc483 ;add esp,..
		mov		byte [eax+esi],08	   ; .. 8  ALTERAR
		mov		byte [eax+esi],0x5d   ;pop	ebp
		mov		byte [eax+esi],0xc3   ;ret
		pop		ebp
		ret


		