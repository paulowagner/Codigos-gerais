format ELF
section '.text' executable
public strlenn

strlenn:	
		push	ebp
		mov 	ebp,esp
		push 	ebx
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
		pop 	ebp
		ret

