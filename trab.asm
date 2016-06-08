section .data
	msg_string_entrada db 'Entre com a expressão, 2 inteiros e uma operação: '
		msg_string_entrada_size equ $-msg_string_entrada
	msg_erro db 'Problema com a string de entrada. ',0ah
		msg_erro_size equ $-msg_erro
	num2 dw 0 						; variavel para guardar o segundo numero da expressao
	op dw 0;

	section .bss
	entrada resb 44 				;variavel que será iniciada com o buffer do teclado. Sua expressão

	section .text
	global main

main:
leExpressao:
	;imprime msg na tela
	mov 	ecx, msg_string_entrada
	mov 	edx, msg_string_entrada_size
	mov 	eax, 4
	mov 	ebx, 1
	int 	80h

									;pega e transfere o buffer do teclado para a variavel entrada
	mov 	ecx, entrada
	mov 	edx, 44 				; 44 bytes
	mov 	eax, 3
	mov 	ebx, 1
	int 	80h
	cmp 	eax,44 					; se ler mais que 44 bytes, pode sair que a expressão está errada.
	jg 		erroOverflow

inicializarVariaveis:
	mov 	ebx, 10 				; multiplicador 
	xor 	eax,eax					; resultado
	xor 	ecx,ecx
	xor 	esi,esi 				; variavel para percorrer o vetor "entrada"
	xor 	edx,edx

decodificador:
	mov 	cl, [entrada] 			;leio o primeiro valor do vetor entrada
	cmp 	ecx, 45 				;comparo com cl com 45, para ver se é um numero negativo, pois o menos tem valor 45 na tabela asc
	je 		negativo 				; se for negativo, pula pra parte que trata numero negativo
	cmp 	ecx, 43 				; comparo cl para ver se é positivo, se for pula pra la.
	je 		positivo 				; pulo para a parte que trata o valor positivo
	jmp 	semSinal 				; caso nao tenha sinal, considero que seja positivo
positivo:
	inc 	esi
	call 	converte_numero 		; chamo a função que pega os digitos e converte em inteiro. 
	push	rax
	jmp 	near leOperacao 		; ja li o numero, então o proximo valor a ser lido é a operacao.
negativo:
	inc 	esi
	call 	converte_numero 		; chamo a função que pega os digitos e converte em inteiro
	neg 	eax 					; * -1
	push	rax
	jmp 	near leOperacao 		; o proximo valor a ser lido é a operação
semSinal:
    call 	converte_numero 		; chamo a função para converter digitos em um valor inteiro
	push    rax
leOperacao: 
	push 	rcx
	jmp 	decodificador2
leOperacao1:
	pop 	rcx
	pop     rax
	cmp 	rcx, '+'
	je 		somar
 	jmp 	fim
;29+25

; decodificador do numero 2
decodificador2:
	inc 	esi
	xor     eax,eax
	mov 	cl, byte[entrada+esi]
	cmp 	ecx, 45
	je 		negativo2
	cmp 	ecx, 43
	je 		positivo2
	jmp 	near semSinal2
positivo2:
	inc 	esi
	call 	converte_numero
	mov 	[num2],eax
	jmp 	near leOperacao1
negativo2:
	inc 	esi
	call 	converte_numero
	neg 	eax
	mov 	[num2],eax
	jmp 	near leOperacao1
semSinal2:
	call 	converte_numero
	mov 	[num2],eax
	jmp 	near leOperacao1


converte_numero:
inicioConverte:
	mov 	cl,[entrada + esi] 				; pego o primeiro digito do numero, repare que aqui ocorre o deslocamento no vetor
	cmp 	cl, 43 						;comparo para ver se o proximo valor é uma operacao, se for, vou para o fim da funcao;
	je 		near retornoConverteNumero 		; finalizo esse loop caso seja uma operacao
	cmp 	cl, 45
	je 		near retornoConverteNumero
	cmp 	cl, 42
	je 		near retornoConverteNumero
	cmp 	cl, 47
	je 		near retornoConverteNumero
	


	sub 	ecx, 48 				; converto o digito para inteiro valido
treta:
	cmp 	ecx, 0 					; vejo se está fora do range, ou seja, se é um numero mesmo
	jl 		retornoConverteNumero 			; se nao for um digito valido, erro.
	cmp 	ecx, 9 					; vejo se está fora do range, ou seja, se é um numero mesmo
	jg 		erroOverflow 			; se nao for um digito valido, erro.
teste:
	mul 	ebx 					; multiplico o que tem em eax por 10;
	cmp 	edx,0 					; testa para ver se a multiplicacao extrapolou a saida.
	jne 	erroOverflow 
teste2:
	add 	eax, ecx 				; somar o digito que acabei de ler para o valor final
teste3:
	jc 		erroOverflow 			; se deu carry, extrapolou.
	js 		erroOverflow 			; se virou negativo, extrapolou tambem pq o numero é com sinal
	inc 	esi 					; aqui eu aumento a variavel que é o deslocamento no vetor, seria o i++ do for 
	jmp 	inicioConverte 			; inicio o loop novamente
retornoConverteNumero:
	ret 							; retorno da funcao

erroOverflow: 						; aqui é a função que imprime erro na tela.
	mov 	ecx, msg_erro
	mov 	edx, msg_erro_size
	mov 	eax, 4
	mov 	ebx, 1
	int 	80h
	jmp 	fim


;operacoes
somar:
    add  	eax, [num2]
    jmp  	fim

imprime:
	 mov    ebx, 1
     mov    eax, 4
     int    80h


fim:
	mov 	eax,1
	mov 	ebx,0
	int 	80h