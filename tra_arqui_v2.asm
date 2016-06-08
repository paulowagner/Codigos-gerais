format ELF
section '.text' executable
public create
public  destroy
extrn	malloc
extrn	free
extrn	realloc
create:	push		ebp     ;Funçao principal
		mov			ebp,esp
		push		1024				
		call 		malloc		   ;Aloca espaço para função         -- EBX 
		add			esp,4
		push 		eax
		push		512				
		call 		malloc		   ;Aloca espaço para parametros     -- EDX
		add			esp,4
		push 		eax
		push 		512
		call 		malloc		   ;Aloca espaço para uso temporario -- EAX
		add			esp,4
		pop         edx
		pop   		ebx
		push 		eax
		push 		512
		call 		inimem		  ;Salva para dar free ao final
		add    		esp,4
		push		ebx
		push		edx
		mov			[ebx],edx
		add 		ebx,4
		mov			dword [edx],0
		add 		edx,4
		push		esi
		push		edi
		mov			ecx,[ebp+16]
		mov			esi,ecx
		dec			esi
		shl			esi,4
		add			esi,[ebp+20]   ;Começa no ultimo parametro
		mov			byte [ebx],0x55 	   ;push ebp
		mov			word [ebx+1],0xe589  ;mov ebp,esp
		add 		ebx,3

inipar: 				;inicia os parametros de tras para frente
		cmp			dword [esi],1
		ja 			funcao
		je 			const
		cmp			dword [esi+4],4
		jne			quatro
		call		poito
		jmp 		looppar

quatro:	
		call		pqua
		jmp			looppar

const:	
		cmp			dword [esi+4],4
		je			double
		call 		const4
		jmp 		looppar

double:	
		mov			byte [ebx],0x68
		mov			edi,[esi+12]
		mov			[ebx+1],edi
		mov			byte [ebx+5],0x68
		mov			edi,[esi+8]
		mov			[ebx+6],edi
		add 		ebx,10
		jmp 		looppar

funcao:	
		mov			edi,[esi+8]   
		push		ecx
		mov			ecx,[edi-4]
		mov			edi,ecx
		mov			ecx,[edi]
		push		edi
		jecxz		fimverf	
		add 		edi,4		

volver: 
		cmp 		dword [edi],4
		jne			oito
		call 		fpqua
		jmp 		lver

oito:	
		call 		fpoito

lver:	
		add			edi,4
		loop 		volver

fimverf:
		call 		fifu
		add 		esp,4          ;OLHAR DEPOIS
		pop      	ecx

looppar:
		sub			esi,16
		loop 		inipar
		mov			byte [ebx],0xe8    ;call ..
		mov			ecx,[ebp+8]
		sub			ecx,ebx
		sub			ecx,5
		mov			[ebx+1],ecx 	   ; FUNÇÃO PRINCIPAL
		add			ebx,5
		mov			word [ebx],0xc481 ;add esp,..
		push		eax
		call 		somargp
		mov			dword [ebx+2],eax
		add			ebx,6
		pop			eax
		mov			byte [ebx],0x5d   ;pop	ebp
		mov			byte [ebx+1],0xc3   ;ret
		add			ebx,2
		call        salvaFun
		pusha
		mov			edi,[ebp-8]
		push 		dword [edi]
		call 		somarg
		add			esp,4
		mov			ebx,[ebp-4]		
		mov 		ecx,eax
		shr 		ecx,2
		jecxz       fim
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

inimem:	
		push		ebp
		mov			ebp,esp
		push		ebx
		push		ecx
		mov			ecx,[ebp+8]
		jecxz		pulaini
		mov			ebx,[ebp+12]

lmem:	
		mov			byte [ebx],0
		inc			ebx
		loop 		lmem

pulaini:
		pop			ecx
		pop			ebx
		pop			ebp
		ret		

somarg:	
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


const4: 
		mov			byte [ebx],0x68
		mov			edi,[esi+8]
		mov			[ebx+1],edi
		add 		ebx,5
		ret



fpqua:	
		mov			word [ebx],0xb5ff  ;push ..
		add			ebx,2
		mov			dword [eax],ebx
		add 		ebx,4
		add			eax,4
		push 		edi
		mov			edi,[ebp-12]
		inc			dword [edi]
		pop 		edi
		mov 		dword [edx],4
		add			edx,4
		ret

fpoito:	
		mov			word [ebx],0xb5ff  ;push ..
		add			ebx,2	
		mov			[eax],ebx    ;Salva endereço para calc
		add			eax,4
		add 		ebx,4
		mov			word [ebx],0xb5ff  ;push ..
		add			ebx,2			
		mov			[eax],ebx    ;Salva endereço para calc
		add			eax,4		
		add			ebx,4
		push 		ebx
		mov			ebx,[ebp-12]
		inc			dword [ebx]
		pop 		ebx
		mov 		dword [edx],8
		add			edx,4
		ret

fifu:	
		mov			byte [ebx],0xe8    ;call ..
		mov			ecx,[esi+8]
		sub			ecx,ebx
		sub			ecx,5
		mov			[ebx+1],ecx 	   ; .. soma
		add			ebx,5
		
		mov			edi,[esi+8]   
		mov			ecx,[edi-4]
		mov			edi,ecx
		mov			ecx,[edi]
		jecxz       ehz

		mov			word [ebx],0xc481 ;add esp,..
		mov			edi,[esi+8] 
		mov 		ecx,[edi-4]
		push		eax
		push		ecx
		call 		somarg
		add			esp,4
		mov			dword [ebx+2],eax ;fim do add
		add			ebx,6
		pop			eax

ehz:	
		cmp			dword [esi+4],3
		jne 		cmpq
		mov			dword [ebx],0x04ec83	;sub	esp,4
		mov			dword [ebx+3],0x2414d9   ;fst dword [esp]
        add			ebx,6

		jmp 		fimfi

cmpq:	
		cmp			dword [esi+4],4
		jne			ehint
		mov			dword [ebx],0x08ec83
		mov			dword [ebx+3],0x2414dd
		add			ebx,6
		jmp 		fimfi

ehint:	
		cmp			dword [esi+4],0
		je 			fimfi
		mov			byte [ebx],0x50
		inc 		ebx
		
fimfi: 	
		ret

poito:  
		mov			word [ebx],0xb5ff  ;push [ebp+desloc] ..
		add			ebx,2	
		mov			[eax],ebx    ;Salva endereço para calc desloc
		add			eax,4
		add 		ebx,4
		mov			word [ebx],0xb5ff  ;push ..
		add			ebx,2			
		mov			[eax],ebx    ;Salva endereço para calc
		add			eax,4		
		add			ebx,4
		push 		ebx
		mov			ebx,[ebp-12]
		inc			dword [ebx]
		pop 		ebx
		mov 		dword [edx],8
		add			edx,4
		ret

pqua:   
		mov			word [ebx],0xb5ff  ;push ..
		add			ebx,2
		mov			dword [eax],ebx
		add 		ebx,4
		add			eax,4
		mov			edi,[ebp-12]
		inc			dword [edi]
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