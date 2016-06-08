format ELF
section '.text' executable
public letraj
public floatint
floatint:   push ebp
			mov	ebp,esp
			fld dword [ebp+8]
			fstp dword [ebp+8]
			mov eax,[ebp+8]
			pop ebp
			ret
			
letraj:		push ebp
			mov	ebp,esp
			fld dword [ebp+12]
			test dword [ebp+12],80000000h
			jz jj2
			fchs 
jj2:		fld dword [ebp+8]
			test dword [ebp+8],80000000h
			jz inij
			fchs
inij:		test dword [ebp+12],7fffffffh
			jnz initj
			and dword [ebp+8],7fffffffh
initj:		fyl2x

			mov eax,1
			sub esp,4
			fst dword [esp]
			and dword [esp],7fe00000h ; 0111 1111 1110 0000 0000 0000 0000 0000
			cmp dword [esp],3fe00000h ;0011 1111 1110 0000 0000 0000 0000 0000
			jb pulaj 
			
			shr dword [esp],23
			sub dword [esp],127 
			mov ecx,23
			sub ecx,[esp] ; Descobre deslocamento para deixar a parte inteira

			fst dword [esp]
			and dword [esp],007fffffh ; Pega a mantissa
			or dword [esp],00800000h;0000 0000 0010 0000 0000 0000 0000 0000 devolve 0 1 implicito

			shr dword [esp],cl ;Deixa apenas parte inteira
			fild dword [esp]
			fsubp
			mov ecx,[esp]
			shl eax,cl
pulaj:		f2xm1
			fld1
			faddp
			mov dword [esp],eax
			fild dword [esp]
			fmulp
			add esp,4
			test dword [ebp+8],80000000h
			jz baseposi
			fchs
baseposi:   test dword [ebp+12],80000000h
			jz expposi
			fld1
			fxch st1
			fdivp
expposi:	pop	ebp
			ret

			;fst dword [esp]
			;mov eax,[esp]
			;and eax,80000000h
			;fld st0
			;fild [esp]
			;fsub st1,st0
			;fst dword [esp]
			;and dword [esp],80000000h
			;cmp eax,[esp]
			;je
			;fld1
			;fsubp
