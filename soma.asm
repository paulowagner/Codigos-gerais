format ELF
section '.text' executable
public soma
public negar
public memset
public strlen
public strcat
public strcpy
public abs
public strchr
public strstr
public toupper
toupper:	push ebp
		mov	ebp,esp
		mov 	eax,[ebp+8]
		cmp 	eax,97
		jb 	fimup
		cmp 	eax,122
		ja 	fimup
		sub  eax,32
fimup:	mov 	esp,ebp
		pop 	ebp
		ret
		
strstr:	push ebp
		mov	ebp,esp
		push	ebx
		push	ecx
		push	edx
		push	esi
		mov	ebx,[ebp+8]
		mov	edx,[ebp+12]
		push	dword [ebp+8]	;Pega o
		call	strlen		;tamanho
		add	esp,4		;da string
		mov	ecx,eax
		push	dword [ebp+12]	;Pega o 
		call	strlen		;tamanho
		add	esp,4		;substring
		push	eax
		cmp	ecx,eax 		;Compara o tamanho das strings
		jnb 	contstr		;Se sub for menor não haverá ocorrencia
		mov	eax,0
		jmp	fimstr
contstr:	sub	ecx,eax
		xor	esi,esi
voltastr:	mov	al,[ebx]
		cmp	al,[edx]
		jne	loopstr
voltae:	inc	esi
		cmp 	esi,[esp]
		jne	pulastr
		mov	eax,ebx
		jmp	fimstr
pulastr:	mov	al,[ebx+esi]
		cmp 	al,[edx+esi]
		je 	voltae
loopstr:	xor	esi,esi
		inc	ebx
		loop voltastr
		mov	eax,0
fimstr:	add 	esp,4
		pop 	esi
		pop 	edx
		pop	ecx
		pop	ebx
		mov 	esp,ebp
		pop 	ebp
		ret
strchr:	push	dword [esp+4]
		call strlen
		add	esp,4
		push ebp
		mov	ebp,esp
		push	ebx
		push	ecx
		mov	ecx,eax
		inc	ecx
		mov 	ebx,[ebp+8]
		mov	eax,[ebp+12]
voltachr:	cmp 	byte [ebx],0
		jne	contchr
		mov	eax,0
		jmp	fimchr
contchr:	cmp	[ebx],al
		jne	contlchr
		mov	eax,ebx
		jmp	fimchr
contlchr:	inc	ebx
		loop	voltachr		
fimchr:	pop	ecx
		pop	ebx
		mov	esp,ebp
		pop	ebp
		ret

abs:		push	ebp
		mov 	ebp,esp
		mov 	eax,[ebp+8]
		cmp	eax,0
		jnl	nmuda
		neg 	eax
nmuda:	mov 	esp,ebp
		pop 	ebp
		ret

strcpy:	push	dword [esp+4]
		call strlen
		add	esp,4
		push	ebp
		mov 	ebp,esp
		push	ebx
		push	esi
		push	ecx
		mov	ecx,eax
		inc	ecx
		mov 	ebx,[ebp+8]
		mov	esi,[ebp+12]
voltacpy:	mov	al,[esi]
		mov 	[ebx],al
		inc	esi
		inc	ebx
		loop	voltacpy		
		pop	ecx
		pop	esi
		pop	ebx
		mov 	esp,ebp	
		pop 	ebp
		ret

strcat:	push word [esp+4]	
		call strlen
		add	esp,4
		push	ebp
		mov 	ebp,esp
		push	ebx
		push	esi
		mov	esi,eax
		mov 	ebx,[ebp+8]
		add	esi,ebx
		mov	ebx,[ebp+12]
voltacat:	cmp 	byte [ebx],0
		jz	fimcat
		mov	al,[ebx]
		mov 	[esi],al
		inc	esi
		inc	ebx
		jmp	voltacat		
fimcat:	pop	esi
		pop	ebx
		mov 	esp,ebp	
		pop 	ebp
		ret

strlen:	push	ebp
		mov 	ebp,esp
		push ebx
		push	esi
		xor	esi,esi
		mov 	ebx,[ebp+8]
		xor	eax,eax
voltacmp:	cmp 	byte [ebx+esi],0
		jz	fimlen
		inc	eax
		inc	esi
		jmp	voltacmp		
fimlen:	pop	esi
		pop	ebx
		mov 	esp,ebp	
		pop 	ebp
		ret
 
soma:
 		push	ebp
		mov 	ebp,esp
		mov 	eax,[ebp+8]
		add 	eax,[ebp+12]
		mov 	esp,ebp
		pop 	ebp
		ret

negar:
		push	ebp
		mov 	ebp,esp
		mov 	eax,[ebp+8]
		neg 	eax
		mov 	esp,ebp
		pop 	ebp
		ret

memset:
		push	ebp
		mov 	ebp,esp
		push	ebx
		push esi
		push	ecx
		mov 	ecx,[ebp+16]
		cmp 	ecx,0
		jz 	fimset
		mov 	eax,[ebp+12]
		mov 	ebx,[ebp+8]
		xor 	esi,esi
volta:	mov 	[ebx+esi],al
		inc	esi
		loop	volta
fimset:	mov 	eax,[ebp+8]
		pop	ecx
		pop	esi
		pop	ebx
		mov 	esp,ebp
		pop 	ebp
		ret		