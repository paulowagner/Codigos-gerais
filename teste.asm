section .data
	n1 		db 0
	n2 		db 0
	soma 	db 0
	resto 	db 0
	multi 	db 0
	divi 	db 0
	msgn1 	db 10,13,"Digite o primeiro numero: ",'$'
	msgn2 	db 10,13,"Digite o segundo numero: ",'$'
	msg1 	db 10,13,"Soma = ",'$'
	msg2 	db 10,13,"Resto = ",'$'
	msg3 	db 10,13,"Multiplicacao = ",'$'
	msg4 	db 10,13,"Divisao = ",'$'

section .text
	global main

main:
		mov 	ax,@data
		mov 	ds,ax

		mov 	ah,09
		lea 	dx,msgn1
		int 	21h
		mov 	ah,01
		int 	21h
		sub 	al,30h
		mov 	n1,al

		mov 	ah,09
		lea 	dx,msgn2
		int 	21h
		mov 	ah,01
		int 	21h
		sub 	al,30h
		mov 	n1,al

		mov 	al,n1
		add 	al,n2
		mov 	soma,al

		mov 	al,n1
		sub 	al,n2
		mov 	resto,al

		mov 	al,n1
		mul 	n2
		mov 	multi,al

		mov 	al,n1
		div 	n2
		mov 	divi,al

		mov 	ah, 09
		lea 	dx,msg1
		int 	21h
		mov 	dl,soma
		add 	dl,30h
		mov 	ah,02
		int 	21h

		mov 	ah, 09
		lea 	dx,msg2
		int 	21h
		mov 	dl,resto
		add 	dl,30h
		mov 	ah,02
		int 	21h

		mov 	ah, 09
		lea 	dx,msg2
		int 	21h
		mov 	dl,multi
		add 	dl,30h
		mov 	ah,02
		int 	21h

		mov 	ah, 09
		lea 	dx,msg4
		int 	21h
		mov 	dl,divi
		add 	dl,30h
		mov 	ah,02
		int 	21h

		mov 	ah,4ch
		int 	21h