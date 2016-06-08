format ELF
section '.text' executable
public letraj
letraj: 	push 	0xffffccee
			push 	0xccee
			push 	0xee
			fstp dword [esp]
			fstp qword [esp]
			sub	esp,0x4
			sub	esp,0x8
			add esp,0x7f
			add esp,0x7fff
			add esp,0x7fffffff
			push	dword [ebp+0xffffff]
			push	eax
			nop
			mov 	esp,ebp	

