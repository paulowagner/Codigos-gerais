format ELF
section '.text' executable
public create
extrn	malloc
create:	  push 		ebp
		  mov		ebp,esp
		
		  push		21			
		  call 		malloc				   ;Aloca 19 bytes de espaço
		  add		esp,4
		
		  mov       ecx,[ebp+8]			   ;Calculo do
		  sub		ecx,16				   ;endereço 
		  sub		ecx,eax				   ;relativo

		  mov		ebx,[ebp+20]
		  add		ebx,24
		  push 		dword [ebx]
		  pop		ebx
		
		  mov		byte [eax],0x55 	   ;push ebp
		  mov		word [eax+1],0xe589    ;mov ebp,esp
		  mov		word [eax+3],0x75ff	   ;push ..
		  mov		byte [eax+5],0x08	   ; .. dword [ebp+8]
		  mov		byte [eax+6],0x68	   ;push..
		  mov		[eax+7],ebx            ;..dword [ebx]
		  mov		byte [eax+11],0xe8 	   ;call ..
		  mov		[eax+12],ecx 		   ; .. mult
		  mov		word [eax+16],0xc483   ;add esp,..
		  mov		byte [eax+18],08	   ; .. 8
		  mov		byte [eax+19],0x5d 	   ;pop	ebp
		  mov		byte [eax+20],0xc3 	   ;ret

final:	  pop 		ebp
		  ret
