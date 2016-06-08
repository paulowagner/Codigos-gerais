format ELF
section '.text' executable
public detorad ;Letra A float detorad(float num)
public poli ;Letra B double poli(void *base,double x,int grau)
public bask ;Letra C void bask(void *base)
public mediapon ;Letra D double mediapon(void *base,void *peso,int tam)
public mediage ;Letra E float mediage(void *base,int tam)
public mediahar ;Letra F double mediahar(void *base,int tam)
public powbfei ;Letra G float powbfei(float base,int expoente)
public powbdei ;Letra H double powbdei(double base,int expoente)
public powbdeis ;Letra I double powbdeis(double base,int expoente)
public letraj ;Letra J float letraj(float base,float expoente)
detorad:	push ebp
			mov	ebp,esp
			fld dword [ebp+8]
			mov	ebx,180
			push ebx
			fild dword [esp]
			add  esp,4
			fdivp
			fldpi
			fmulp
			pop	ebp
			ret

poli:		push ebp
			mov	ebp,esp

			push dword [ebp+20]
			push dword [ebp+16]
			push dword [ebp+12]
			call powbdei
			add esp,12

			mov ebx,[ebp+8]
			xor esi,esi
			mov ecx,[ebp+20]
			inc ecx

			fldz
voltapoli: 	fld qword [ebx + esi*8]
			fmul st0,st2
			faddp
			inc esi
			fld qword [ebp+12]
			fdiv st2,st0
			fstp st0
			loop voltapoli

			fxch st1
			fstp st0

fimpoli:	pop ebp
			ret

bask:		push ebp
			mov	ebp,esp
			mov ebx,[ebp+8]
			fld dword [ebx+4]
			fmul st0,st0
			fld dword [ebx]
			fadd st0,st0
			fadd st0,st0
			fld dword [ebx+8]
			fmulp
			fsubp st1,st0
			fsqrt

			fld dword [ebx+4]
			fchs
			fld dword [ebx]
			fadd st0,st0
			fdiv st2,st0
			fdivp
			
			fld1
			fmul st0,st1
			fadd st0,st2
			fxch st2
			fsubp st1,st0
			fstp dword [ebx]
			fstp dword [ebx+4]
			pop	ebp
			ret

mediapon:	push ebp
			mov	ebp,esp

			mov ecx,[ebp+16]
			mov ebx,[ebp+8]
			mov esi,[ebp+12]
			fldz
			jecxz fimpon
			fldz
			xor eax,eax
voltapon:	fld qword [ebx + eax*8]
			fld qword [esi + eax*8]
			fadd st3,st0
			fmulp
			faddp
			inc eax
			loop voltapon
			fxch st1
			fdivp
fimpon:		pop ebp
			ret
			
mediage:	push ebp
			mov	ebp,esp
			mov ebx,[ebp+8]
			mov	ecx,[ebp+12]
			jecxz	fimge
			fld1
			xor	esi,esi
somamege:	fld dword [ebx+esi*4]
			fmulp
			inc	esi
			loop somamege
			
			fld1
			push esi
			fild dword [esp]
			add esp,4
			fdivp
			sub esp,8
			fstp dword [esp+4]
			fstp dword [esp]
			call letraj
			add esp,8
fimge:		pop	ebp
			ret

mediahar: 	push ebp
			mov	ebp,esp

			mov ebx,[ebp+8]
			mov ecx,[ebp+12]
			xor esi,esi
			fild dword [ebp+12]
			fldz
			jecxz fimhar
voltahar:   fld1
			fld qword [ebx + esi*8]
			inc esi
			fdivp
			faddp
			loop voltahar
			fdivp
fimhar:		pop ebp
			ret
			
powbfei:	push ebp
			mov	ebp,esp
			fld1
			fld dword [ebp+8]
			mov	ecx,[ebp+12]
pulabfei1:	jecxz fimbfei
  			test ecx,1
  			jz 	pulabfei2
  			fmul st1,st0
pulabfei2:	shr ecx,1
    		fmul st0,st0
    		jmp pulabfei1
fimbfei:    fstp st0
			pop	ebp
			ret


powbdei:	push ebp
			mov	ebp,esp
			fld1
			fld qword [ebp+8]
			mov	ecx,[ebp+16]
pulabdei1:	jecxz fimbdei
  			test ecx,1
  			jz 	pulabdei2
  			fmul st1,st0
pulabdei2:	shr ecx,1
    		fmul st0,st0
    		jmp pulabdei1
fimbdei:    fstp st0
			pop	ebp
			ret

powbdeis:	push ebp
			mov	ebp,esp

			cmp dword [ebp+16],0
			jge normaleis

			fld1
			neg dword [ebp+16]
			push dword [ebp+16]
			push dword [ebp+12]
			push dword [ebp+8]
			call powbdei
			add esp,12
			fdivp
			jmp fimbdeis

normaleis:	push dword [ebp+16]
			push dword [ebp+12]
			push dword [ebp+8]
			
			call powbdei
			add esp,12

fimbdeis:   pop	ebp
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