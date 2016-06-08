format ELF
section '.text' executable
public create
public  destroy
extrn	malloc
extrn	free
extrn	realloc

create:	
		push		ebp
		mov			ebp,esp
											;Aloca espaço para função(EBX)
		push		1024
		call		malloc		    
		add			esp,4
		push		eax
											;Aloca espaço para parametros(EDX)
		push		512				
		call		malloc		   
		add			esp,4
		push 		eax
											;Aloca espaço para uso temporario(EAX)
		push		512
		call		malloc		   
		add			esp,4
											;Salva os endereçoes citados nos registradores correspondentes
		pop			edx
		pop			ebx
 											;Inicialização da memória
		push		eax
		push		512
		call		inicializaMemoria
		add			esp,4					;Deixa EAX na pilha para dar free no final
											;Preparação para a escrita
		push		ebx
		push		edx
		mov			[ebx],edx				;No início de EBX fica o endereço para o espaço de memória alocada para os parâmetros
		add			ebx,4
		mov			dword [edx],0			;No início de EDX fica a quantidade de parâmtros
		add			edx,4
											;Inicia a escrita da função
		push		esi
		push		edi

		mov			ecx,[ebp+16]			;Quantidade de parâmetros (n) passada pela função create
		mov			esi,ecx
		dec			esi
		shl			esi,4					;Calcula o tamanho dos (argumentos - 1)
		add			esi,[ebp+20]			;Começa no ultimo parametro (tamanho dos (argumentos - 1)) + início do vetorde parâmetros
		mov			byte [ebx],0x55			;Escreve na memória "push ebp"
		mov			word [ebx+1],0xe589		;Escreve na memória "mov ebp,esp"
		add			ebx,3

	inicializaParametros: 					;Inicia os parametros de trás para frente (Início de loop)
											;Iniciar parâmetros nesse contexto é escrever na função dinâmica os PUSHs
											;...referentes aos parâmetros que foram recebidos.

		cmp			dword [esi],1			;Verifica a amarração
		ja 			Funcao
		je 			Constante
											;Argumento de amarração livre:
		cmp			dword [esi+4],4			;Verifica Tipo do argumento
		jne			Livre4Bytes				
		call		parametros8bytes
		jmp 		LoopParametro

	Livre4Bytes:
		call		parametros4bytes
		jmp			LoopParametro
											;Argumento de amarração constante:
	Constante:
		cmp			dword [esi+4],4			;Verifica Tipo do argumento
		je			ConstanteDouble
		call 		constante4Bytes
		jmp 		LoopParametro

	ConstanteDouble:
											;Escreve no endereço apontado por EBX
											;os opcodes referentes aos PUSHs de um argumento do tipo double
		mov			byte [ebx],0x68			
		mov			edi,[esi+12]
		mov			[ebx+1],edi
		mov			byte [ebx+5],0x68
		mov			edi,[esi+8]
		mov			[ebx+6],edi
		add 		ebx,10
		jmp 		LoopParametro
											;Argumento de amarração "função":
	Funcao:	
		mov			edi,[esi+8]   
		push		ecx
		mov			ecx,[edi-4]
		mov			edi,ecx
		mov			ecx,[edi]
		push		edi
		jecxz		FimVerificacao
		add 		edi,4		
											;Verifica os parâmetros do argumento de amarração "função"
	VoltaVerificacao: 
		cmp 		dword [edi],4
		jne			oito
		call 		parametros4bytes
		jmp 		LoopVerificacao

	oito:	
		call 		parametros8bytes

	LoopVerificacao:	
		add			edi,4
		loop 		VoltaVerificacao

	FimVerificacao:
		call 		finalizafuncao
		add 		esp,4          			;OLHAR DEPOIS
		pop     	ecx

	LoopParametro:
		sub			esi,16
		loop		inicializaParametros

		mov			byte [ebx],0xe8    		;Escreve na memória o opcode da instrução CALL que será utilizada para chamar a função principal
		mov			ecx,[ebp+8]
		sub			ecx,ebx
		sub			ecx,5
		mov			[ebx+1],ecx 	   		;Escreve no byte após o opcode da instrução CALL o endereço relativo da função principal
		add			ebx,5
		mov			word [ebx],0xc481 		;Escreve add	esp,..
		push		eax
		call 		somargp
		mov			dword [ebx+2],eax
		add			ebx,6
		pop			eax
		mov			byte [ebx],0x5d   		;pop	ebp
		mov			byte [ebx+1],0xc3   	;ret
		add			ebx,2
		call		salvaFun
		pusha
		mov			edi,[ebp-8]
		push 		dword [edi]
		call 		somarg
		add			esp,4
		mov			ebx,[ebp-4]		
		mov 		ecx,eax
		shr 		ecx,2
		jecxz   	fim
		add			eax,4

	rel:	
		mov         edx,[ebx]
		mov			[edx],eax
		sub			eax,4
		add 		ebx,4
		loop 		rel
        
	fim:	
		popa
		pop 		edi
		pop			esi
		
		push        ebx
		mov 		ecx,edx
		sub			ecx,[ebp-12]
		push        ecx
		push		dword [ebp-12]
		call 		realloc
		add			esp,8

		mov 		ecx,[ebp-8]
		mov			[ecx],eax
		pop         ebx  		
		add 		esp,4
				
		mov 		ecx,ebx
		sub			ecx,[ebp-8]
		push		ecx
		push		dword [ebp-8]
		call 		realloc
		add			esp,12
		push        eax
		push    	dword [ebp-4]
		call 		free
		add 		esp,4
		pop 		eax
		
		pop 		ebx
		add			eax,4
		pop 		ebp
		ret	

inicializaMemoria:
											;Inicializa a memória que será utillizada para a função dinâmica.
		push		ebp
		mov			ebp,esp
		push		ebx
		push		ecx
		mov			ecx,[ebp+8]
		jecxz		pulaInicializacao
		mov			ebx,[ebp+12]

	loopMem:
		mov			byte [ebx],0
		inc			ebx
		loop 		loopMem

	pulaInicializacao:
		pop			ecx
		pop			ebx
		pop			ebp
		ret		

somarg:	
											;Usada para determinar o espaço usado na pilha por uma função qualquer, função tal gerada pelo create.
											;Tem com função secundária, somar o tamanho de todos argumentos para encontrar...
											;...o deslocamento usado nas instruções "PUSH [EBP + DESLOC.]" nas funções dinâmicas
		push		ebp
		mov			ebp,esp
		push		ebx
		push		ecx
		mov			ebx,[ebp+8]
		xor			eax,eax
		mov			ecx,[ebx]
		jecxz       fimsom
		add			ebx,4

	somar:	
		add         eax,[ebx]
		add 		ebx,4
		loop 		somar
		
	fimsom:	
		pop			ecx
		pop			ebx
		pop			ebp
		ret

constante4Bytes:
											;Escreve no endereço apontado por EBX o código de máquina de um PUSH
		mov			byte [ebx],0x68
		mov			edi,[esi+8]
		mov			[ebx+1],edi
		add 		ebx,5
		ret

finalizafuncao:	
		mov			byte [ebx],0xe8			;Escreve no endereço apontado por EBX o opcode da instrução "CALL" (Sem o endereço relativo)
		mov			ecx,[esi+8]
		sub			ecx,ebx
		sub			ecx,5
		mov			[ebx+1],ecx				;Escreve em EBX+1 o argumento da instrução CALL
		add			ebx,5
		
		mov			edi,[esi+8]   
		mov			ecx,[edi-4]
		mov			edi,ecx
		mov			ecx,[edi]
		jecxz       ehz

		mov			word [ebx],0xc481		;Escreve no endereço apontado por EBX o opcode da instrução	"ADD ESP,IMM"
		mov			edi,[esi+8] 
		mov 		ecx,[edi-4]
		push		eax
		push		ecx
		call 		somarg
		add			esp,4
		mov			dword [ebx+2],eax		;fim do add
		add			ebx,6
		pop			eax

	ehz:	
		cmp			dword [esi+4],3
		jne 		cmpq
		mov			dword [ebx],0x04ec83	;sub esp,4
		mov			dword [ebx+3],0x2414d9	;fst dword [esp]
        add			ebx,6

		jmp 		fimFinalizacao

	cmpq:	
		cmp			dword [esi+4],4
		jne			ehint
		mov			dword [ebx],0x08ec83
		mov			dword [ebx+3],0x2414dd
		add			ebx,6
		jmp 		fimFinalizacao

	ehint:	
		cmp			dword [esi+4],0
		je 			fimFinalizacao
		mov			byte [ebx],0x50
		inc 		ebx
		
	fimFinalizacao: 	
		ret

parametros8bytes:
											;Escreve na função os PUSHs referente a um parâmmetro de 8 bytes
		mov			word [ebx],0xb5ff		;Escreve na função "push [ebp+desloc]"
		add			ebx,2	
		mov			[eax],ebx				;Salva endereço para cálculo de deslocamento
		add			eax,4
		add 		ebx,4
		mov			word [ebx],0xb5ff		;Escreve na função "push [ebp+desloc]"
		add			ebx,2			
		mov			[eax],ebx				;Salva endereço para cálculo de deslocamento
		add			eax,4		
		add			ebx,4
		push 		ebx
		mov			ebx,[ebp-12]
		inc			dword [ebx]
		pop 		ebx
		mov 		dword [edx],8
		add			edx,4
		ret

parametros4bytes:
	;Escreve na função os PUSHs referente a um parâmmetro de 4 bytes
		mov			word [ebx],0xb5ff		;Escreve na função "push [ebp+desloc]"
		add			ebx,2
		mov			dword [eax],ebx			;Salva endereço para cálculo de deslocamento
		add 		ebx,4
		add			eax,4
		push 		edi
		mov			edi,[ebp-12]
		inc			dword [edi]
		pop 		edi
		mov 		dword [edx],4
		add			edx,4
		ret

somargp:
		push 		ebx
		mov 		ebx,[ebp+20]
		push 		ecx
		mov 		ecx,[ebp+16]
		xor 		eax,eax

	vcon:
		cmp 		dword [ebx+4],4
		jne         pcon
		add 		eax,4

	pcon:
		add 		eax,4
		add 		ebx,16
		loop 		vcon		
		pop 		ecx
		pop 		ebx
		ret

salvaFun:
		push 		ebx
		push 		ecx
		push        eax
		mov			eax,edx
		mov			dword [eax],0
		add 		edx,4
		mov 		ebx,[ebp+20]
		mov 		ecx,[ebp+16]
	salfun:	
		cmp 		dword [ebx],2
		jne         psal
		mov 		edi,[ebx+8]
		mov 		[edx],edi
		add 		edx,4
		inc 		dword [eax]		

	psal:	
		loop 		salfun
		pop 		eax		
		pop 		ecx
		pop 		ebx
		ret

destroy:
		push 		ebp
		mov	 		ebp,esp
		pusha
		cmp 		dword [ebp+12],0
		je 			freesimples
		mov 		ebx,[ebp+8]
		push 		dword [ebx-4]
		call 		freefuncoes
		add 		esp,4

	freesimples:
		mov 		ebx,[ebp+8]
		push 		dword [ebx-4]
		call 		free
		add 		esp,4
		sub			ebx,4
		push 		ebx
		call 		free
		add 		esp,4
	fimdestroy:
		popa
		pop 		ebp
		ret

freefuncoes:
		push 		ebp
		mov	 		ebp,esp
		pusha		
		mov 		ebx,[ebp+8]
		mov 		ecx,[ebx]
		inc 		ecx
		shl 		ecx,2
		add 		ebx,ecx
		mov 		ecx,[ebx]
		jecxz	    funcoesfree
	listafuncoes:
		add 		ebx,4
		mov 		edx,[ebx]
		push 		1
		push 		edx
		call 		destroy
		add    		esp,8
		loop 		listafuncoes
	funcoesfree:
		popa
		pop 		ebp
		ret