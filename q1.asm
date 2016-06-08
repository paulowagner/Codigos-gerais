format ELF
section '.text' executable
public 	busbin
public  buscalin
busbin: push 	ebp
		mov		ebp,esp
		push 	esi
		push 	edi
		mov 	eax,[ebp+16]
		mov 	esi,[ebp+12]
		xor 	edi,edi
		cmp 	esi,0
		je 		nachou
		mov 	ecx,esi
		dec 	ecx
		xor 	edx,edx
		mov		ebx,[ebp+8]

whil: 	cmp 	ecx,edx
		jb 		nachou
		shr     esi,1
		cmp		eax,[ebx+4*esi]
		jl 		fm
		jg 		im
		mov		edi,esi
		shl 	edi,2  		;Na prova usei dois shl edi,1
		add 	edi,ebx
fm: 	mov 	ecx,esi
		jecxz	nachou
		dec 	ecx
		mov 	esi,edx
		add 	esi,ecx
		jmp 	whil
im:		mov 	edx,esi
		add 	edx,1
		mov 	esi,edx
		add 	esi,ecx
		jmp 	whil
nachou: mov		eax,edi
		pop 	edi
		pop 	esi
		pop 	ebp
		ret

buscalin:push 	ebp
		mov		ebp,esp

		mov 	ecx,[ebp+12]
		jecxz 	fim
		mov 	eax,[ebp+16]
		mov 	ebx,[ebp+8]
comp:	cmp 	eax,[ebx]
		je      achou
		add     ebx,4
		loop 	comp
		xor		eax,eax
		jmp 	fim
achou: 	mov 	eax,ebx
fim: 	pop		ebp
		ret
