format ELF
section '.text' executable
public bissexto
public quick
public fibo
public primo
public bolha
primo:	push ebp
		mov 	ebp,esp
		push edx
		push ecx
		mov	ecx,[ebp+8]
		shr	ecx,1
		cmp  dword [ebp+8],2
		je 	ehprimo
		jb   nehprimo
		test dword [ebp+8],1
		jz 	nehprimo
verprimo:	xor	edx,edx
		mov	eax,[ebp+8]
		cmp 	ecx,1
		je   ehprimo
		div  ecx
		cmp	edx,0
		je 	nehprimo
		dec 	ecx
		jmp	verprimo
nehprimo:	mov 	eax,0
		jmp	fimpri
ehprimo:  mov 	eax,1
		jmp	fimpri
fimpri:	pop  ecx
		pop  edx
		pop	ebp
		ret
fibo:	push ebp
		mov	ebp,esp
		push	ecx
		xor  eax,eax
		xor 	ecx,ecx
		cmp	dword [ebp+8],0
		jne  nehzero
		mov	eax,0
		jmp fimfi
nehzero:	cmp dword [ebp+8],1
		jne  nehum
		mov	eax,1
		jmp fimfi
nehum:	sub	dword [ebp+8],1
		push	dword [ebp+8]
		call	fibo
		add	esp,4
		mov	ecx,eax
		sub	dword [ebp+8],1
		push	dword [ebp+8]
		call	fibo
		add	esp,4
		add 	eax,ecx
fimfi:	pop 	ecx				
		mov	esp,ebp
		pop	ebp
		ret
bissexto:	push ebp
		mov	ebp,esp
		push	edx
		push	ecx
		mov	eax,[ebp+8]
		test	eax,3
		jz	ehbi
		xor	edx,edx
		mov	ecx,64
		div	ecx
		cmp	edx,0
		jne	ehbi
		mov	eax,[ebp+8]
		mov	ecx,190
		div	ecx
		cmp	edx,0
		je	ehbi
		mov	eax,-1
		jmp	fimbi
ehbi:	xor	eax,eax
fimbi:	pop	ecx
		pop	edx
		mov	esp,ebp
		pop	ebp
		ret	
quick:	push ebp
		mov	ebp,esp
		push	ebx
		push	edx
		push	ecx
		push	eax
		push	esi
		mov	eax,[ebp+12] ;pega n de elementos
		cmp	eax,1
		jbe	fimq
		mov	ebx,[ebp+8]
		mov	ecx,4
		mul	ecx
		sub	eax,ecx  
		xor	esi,esi
troca1:	mov	edx,[ebx+esi] ;vet[16]
		cmp	edx,[ebx+eax] ;vet[24]
		jbe	ctroca1
		xchg	edx,[ebx+eax]	
		xchg	edx,[ebx+esi] 
		add	esi,ecx 		;eax = 20
		cmp	esi,eax        ;00 04 08 12 16 20 24 28 32 36
		je 	cha1          ;[04,05,03,02,01,06,07,08,10,09]
		jmp	troca2
ctroca1:	sub	eax,ecx
		cmp	esi,eax
		je 	cha1
		jmp	troca1     ;esi = 20
troca2:	mov	edx,[ebx+eax] ;vet[28]
		cmp	edx,[ebx+esi] ;vet[16]
		jae	ctroca2
		xchg	edx,[ebx+esi]
		xchg	edx,[ebx+eax]
		sub	eax,ecx
		cmp	esi,eax
		je 	cha1
		jmp	troca1
ctroca2:	add	esi,ecx
		cmp	esi,eax
		je 	cha1
		jmp	troca2
cha1:	xor 	edx,edx
		div	ecx
		push	eax
		push dword [ebp+8]
		call quick
		add	esp,8
		inc  eax
		sub	[ebp+12],eax
		mul	ecx
		add	[ebp+8],eax
		push	dword [ebp+12]
		push	dword [ebp+8]
		call	quick
		add 	esp,8

fimq:	pop	esi
		pop	eax
		pop	ecx
		pop	edx
		pop	ebx
		mov	esp,ebp
		pop	ebp
		ret	


bolha:	push ebp
		mov 	ebp,esp
		push ecx
		push eax
		push	ebx
		push esi
		push edx
		mov 	ecx,[ebp+12]
		mov 	ebx,[ebp+8]
		mov 	edx,ecx
voltab:	mov 	ecx,edx
		cmp 	ecx,1
		jbe 	fim
		xor 	esi,esi
voltabb:	mov 	eax,[ebx+esi]
		cmp 	eax,[ebx+esi+4]
		jbe 	ntroca
		xchg [ebx+esi+4],eax
		xchg [ebx+esi],eax
ntroca:	add 	esi,4
		loop voltabb
		dec 	edx
		jnz 	voltab
fim: 	pop 	edx
		pop 	esi
		pop 	ebx
		pop 	eax
		pop 	ecx
		mov 	esp,ebp
		pop 	ebp
		ret