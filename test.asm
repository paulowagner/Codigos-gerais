section .data
	msg1 db 'Entre com a expressão: '
	msg1size equ $-msg1
	msg2 db 'Entre com o segundo valor: '
	msg2size equ $-msg2
	msg3 db 'A soma é:'
	msg3size equ $-msg3
	
	num1 db 6
	num2 db 6
	result db 6
	
	
section .bss
	digito resb 11

section .text
	global main
	
main:
lenum1:
	;imprime mensagem 1
	mov ecx,msg1
	mov edx,msg1size
	call leitura
	
	;;cmp eax,2
	;;je umByte
	;cmp eax, 10		;verifica se tem mais que 3 bytes
	jmp armazena_num1
	;jg near erro
	
umByte:
	mov al, [byte digito]
	sub al, 48
	mov [byte num1], al
	jmp umByte2
	
armazena_num1:
	;primeiro byte
	mov al,[byte digito]
	sub al,48
	
	;multiplica por 10
	mov cl,10
	mul cl
	mov [byte num1],ax
	
	;segundo byte
	mov al,[byte digito+1]
	sub	 al,48
	
	;num1=num1*10+al
	add [byte num1],al


umByte2:
	mov al, [byte digito+5]
	sub al, 48
	mov [byte num2], al
	jmp soma

armazena_num2:
	;primeiro byte
	mov al,[byte digito+5]
	sub al,48
	
	;multiplica por 10
	mov cl,10
	mul cl
	mov [byte num2],al
	
	;segundo byte
	mov al,[byte digito+6]
	sub al,48
	
	;num2=num2*10+al
	add [byte num2],al
		
soma:
	;imprime mensagem
	mov ecx,msg3
	mov edx,msg3size
	mov eax,4
	mov ebx,1
	int 80h
	
	;somou num1 e num2
	mov al,[byte num1]
	add al,[byte num2]
	
	;pega o primeiro valor do result+48 e guarda em result
	mov cl,10
	div cl
	add al,48
	mov [byte result],al
	
	;pega o valor do resto+48 e guarda em result+1
	add ah,48
	mov [byte result+1],ah
	
imprime_soma:
	mov al,[byte result]
	mov [byte digito],al
	mov al,[byte result+1]
	mov [byte digito+1],al
	mov al,10
	mov [byte digito+2],al
	mov ecx,digito
	mov edx,10
	mov eax,4
	mov ebx,1
	int 80h
	jmp fim
	

fim:
	mov eax,1
	mov ebx,0
	int 80h
	
leitura:
	mov eax,4
	mov ebx,1
	int 80h
	mov ecx,digito	;espera a entrada do valor
	mov edx,10
	mov eax,3
	mov ebx,1
	int 80h
	ret
	
