format ELF
section '.text' executable
public hypot
hypot: 	push ebp
		mov 	ebp,esp
		fld 	qword [ebp+8]
		fmul	st,st
		fld 	qword [ebp+16]
		fmul	st,st
		faddp	st(1),st
		fsqrt
		pop		ebp
		ret