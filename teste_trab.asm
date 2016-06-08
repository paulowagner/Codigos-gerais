format ELF
section '.text' executable
public create

create:	push		ebp
		mov			ebp,esp
		push		10
		push 		100
		push		dword [ebp+8]
		mov	 	 	eax,[ebp-12]
		add 		esp,12
		pop 		ebp
		ret