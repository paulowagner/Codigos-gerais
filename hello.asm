section .data
			msg1 db 'Entre com o primeiro digito: '
			msg1size equ $-msg1
			msg2 db 'Entre com o segundo digito: '
			msg2size equ $-msg2
			msg3 db 'A soma é: '
			msg3size equ $-msg3
			msgerro db 'Entre somente com 1 digito.',10,13
			msgerrosize equ $-msgerro
			num1 db 0
			num2 db 0
			result db 0
section .bss
			digito resb 2
section .text
			global main
main:
lenum1:
			mov ecx, msg1
			mov edx, msg1size
			mov eax, 4
			mov ebx, 1
			int 80h
			mov ecx, digito
			mov edx, 2 ; 2 Byte
			mov eax, 3
			mov ebx, 1
			int 80h
			cmp eax,2 ; leu mais de 1 Byte + /n
			jg near erro
armazena_num1:
			mov al, [byte digito]
			sub al, 48 ; converte de ASCII para inteiro
			mov [byte num1], al
lenum2:
			mov ecx, msg2
			mov edx, msg2size
			mov eax, 4
			mov ebx, 1
			int 80h
			mov ecx, digito			
			mov edx, 2 ; 2 Bytes
			mov eax, 3
			mov ebx, 1
			int 80h
			cmp eax,2 ; leu mais de 1 Byte
			jg erro
armazena_num2:
			mov al, [byte digito]
			sub al, 48 ; converte de ASCII para inteiro
			mov [byte num2], al
soma:
			mov ecx, msg3
			mov edx, msg3size
			mov eax, 4
			 mov ebx, 1
			int 80h
			mov al, [byte num1]
			add al, [byte num2]
			add al, 48 ; converte de inteiro para ASCII
			mov [byte result], al
imprime_soma:
			mov [byte digito],al
			mov al,10 ;enter, ou /n
			mov [byte digito+1],al
			mov ecx, digito
			mov edx, 2 ; 2 Bytes
			mov eax, 4
			mov ebx, 1
			int 80h
			jmp fim
erro:
			mov ecx, msgerro
			mov edx, msgerrosize
			mov eax, 4
			mov ebx, 1
			int 80h
			jmp fim
fim:
			mov eax,1
			mov ebx,0
			int 80h




























