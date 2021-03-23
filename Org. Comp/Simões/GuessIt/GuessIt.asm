; Hello World - Escreve mensagem armazenada na memoria na tela

; ------- TABELA DE CORES -------
; adicione ao caracter para Selecionar a cor correspondente

; 0 branco							0000 0000
; 256 marrom						0001 0000
; 512 verde							0010 0000
; 768 oliva							0011 0000
; 1024 azul marinho					0100 0000
; 1280 roxo							0101 0000
; 1536 teal							0110 0000
; 1792 prata						0111 0000
; 2048 cinza						1000 0000
; 2304 vermelho						1001 0000
; 2560 lima							1010 0000
; 2816 amarelo						1011 0000
; 3072 azul							1100 0000
; 3328 rosa							1101 0000
; 3584 aqua							1110 0000
; 3840 branco						1111 0000

jmp Main

IncRand: var #1			; Incremento para circular na Tabela de nr. Randomicos
Rand : var #200			; Tabela de nr. Randomicos entre 0 - 9
	static Rand + #0, #5
	static Rand + #1, #7
	static Rand + #2, #8
	static Rand + #3, #3
	static Rand + #4, #9
	static Rand + #5, #5
	static Rand + #6, #4
	static Rand + #7, #0
	static Rand + #8, #7
	static Rand + #9, #0
	static Rand + #10, #5
	static Rand + #11, #9
	static Rand + #12, #1
	static Rand + #13, #1
	static Rand + #14, #6
	static Rand + #15, #3
	static Rand + #16, #7
	static Rand + #17, #1
	static Rand + #18, #9
	static Rand + #19, #1
	static Rand + #20, #9
	static Rand + #21, #0
	static Rand + #22, #5
	static Rand + #23, #6
	static Rand + #24, #2
	static Rand + #25, #7
	static Rand + #26, #6
	static Rand + #27, #7
	static Rand + #28, #0
	static Rand + #29, #8
	static Rand + #30, #1
	static Rand + #31, #5
	static Rand + #32, #4
	static Rand + #33, #2
	static Rand + #34, #9
	static Rand + #35, #3
	static Rand + #36, #7
	static Rand + #37, #5
	static Rand + #38, #5
	static Rand + #39, #2
	static Rand + #40, #6
	static Rand + #41, #3
	static Rand + #42, #4
	static Rand + #43, #7
	static Rand + #44, #4
	static Rand + #45, #1
	static Rand + #46, #2
	static Rand + #47, #3
	static Rand + #48, #3
	static Rand + #49, #0
	static Rand + #50, #4
	static Rand + #51, #4
	static Rand + #52, #0
	static Rand + #53, #1
	static Rand + #54, #2
	static Rand + #55, #6
	static Rand + #56, #1
	static Rand + #57, #5
	static Rand + #58, #2
	static Rand + #59, #1
	static Rand + #60, #6
	static Rand + #61, #7
	static Rand + #62, #5
	static Rand + #63, #3
	static Rand + #64, #9
	static Rand + #65, #8
	static Rand + #66, #5
	static Rand + #67, #8
	static Rand + #68, #5
	static Rand + #69, #2
	static Rand + #70, #3
	static Rand + #71, #4
	static Rand + #72, #5
	static Rand + #73, #7
	static Rand + #74, #7
	static Rand + #75, #1
	static Rand + #76, #9
	static Rand + #77, #9
	static Rand + #78, #5
	static Rand + #79, #0
	static Rand + #80, #9
	static Rand + #81, #1
	static Rand + #82, #8
	static Rand + #83, #1
	static Rand + #84, #3
	static Rand + #85, #4
	static Rand + #86, #8
	static Rand + #87, #4
	static Rand + #88, #4
	static Rand + #89, #2
	static Rand + #90, #9
	static Rand + #91, #5
	static Rand + #92, #9
	static Rand + #93, #0
	static Rand + #94, #0
	static Rand + #95, #7
	static Rand + #96, #0
	static Rand + #97, #5
	static Rand + #98, #7
	static Rand + #99, #6
	static Rand + #100, #3
	static Rand + #101, #6
	static Rand + #102, #5
	static Rand + #103, #5
	static Rand + #104, #5
	static Rand + #105, #4
	static Rand + #106, #7
	static Rand + #107, #2
	static Rand + #108, #2
	static Rand + #109, #3
	static Rand + #110, #6
	static Rand + #111, #3
	static Rand + #112, #9
	static Rand + #113, #2
	static Rand + #114, #9
	static Rand + #115, #4
	static Rand + #116, #5
	static Rand + #117, #5
	static Rand + #118, #0
	static Rand + #119, #1
	static Rand + #120, #3
	static Rand + #121, #1
	static Rand + #122, #3
	static Rand + #123, #8
	static Rand + #124, #2
	static Rand + #125, #3
	static Rand + #126, #7
	static Rand + #127, #2
	static Rand + #128, #0
	static Rand + #129, #3
	static Rand + #130, #8
	static Rand + #131, #3
	static Rand + #132, #5
	static Rand + #133, #6
	static Rand + #134, #0
	static Rand + #135, #2
	static Rand + #136, #8
	static Rand + #137, #1
	static Rand + #138, #5
	static Rand + #139, #4
	static Rand + #140, #6
	static Rand + #141, #4
	static Rand + #142, #8
	static Rand + #143, #3
	static Rand + #144, #9
	static Rand + #145, #5
	static Rand + #146, #0
	static Rand + #147, #3
	static Rand + #148, #2
	static Rand + #149, #0
	static Rand + #150, #8
	static Rand + #151, #5
	static Rand + #152, #1
	static Rand + #153, #5
	static Rand + #154, #1
	static Rand + #155, #3
	static Rand + #156, #6
	static Rand + #157, #1
	static Rand + #158, #5
	static Rand + #159, #9
	static Rand + #160, #8
	static Rand + #161, #6
	static Rand + #162, #2
	static Rand + #163, #1
	static Rand + #164, #0
	static Rand + #165, #2
	static Rand + #166, #4
	static Rand + #167, #8
	static Rand + #168, #5
	static Rand + #169, #7
	static Rand + #170, #3
	static Rand + #171, #0
	static Rand + #172, #6
	static Rand + #173, #3
	static Rand + #174, #3
	static Rand + #175, #4
	static Rand + #176, #0
	static Rand + #177, #7
	static Rand + #178, #8
	static Rand + #179, #6
	static Rand + #180, #6
	static Rand + #181, #8
	static Rand + #182, #2
	static Rand + #183, #3
	static Rand + #184, #0
	static Rand + #185, #4
	static Rand + #186, #2
	static Rand + #187, #6
	static Rand + #188, #5
	static Rand + #189, #0
	static Rand + #190, #9
	static Rand + #191, #5
	static Rand + #192, #6
	static Rand + #193, #3
	static Rand + #194, #7
	static Rand + #195, #5
	static Rand + #196, #9
	static Rand + #197, #4
	static Rand + #198, #0
	static Rand + #199, #3

Num: var #1				; Valor do numero a ser sorteado
Tentativas: var #1		; Tentativas


;---- Inicio do Programa Principal -----
 
Main:
	loadn r0, #0			; Posicao na tela onde a mensagem sera' escrita
	store Num, r0			; 
	store Tentativas, r0	; Incializa os Tentativas
	loadn r1, #TelaInit0	; Carrega r1 com o endereco do vetor que contem a mensagem
	loadn r2, #3328			; Seleciona a COR da Mensagem

	; Tela inicial 
	call ImprimeTela

	loadn r1, #255	; Se nao digitar nada vem 255
	Main_StartLoop:			; loop tela incial
		inchar r0			; Le o teclado, se nada for digitado = 255
		cmp r0, r1			;compara r0 com 255
		jeq Main_StartLoop	; Fica lendo ate' que digite uma tecla valida
	
	loadn r1, #TelaReg0
	call ImprimeTela
	
	loadn r1, #255	; Se nao digitar nada vem 255	
	loadn r2, #0	; inica o contador
	loadn r3, #200	
	Main_RulesLoop:			; loop para mostrar as regras
		inchar r0			; Le o teclado, se nada for digitado = 255		
		inc r2
		cmp r2, r3			; incrementa contador
		jne Main_RulesLoop_Skip
			loadn r2, #0			
		Main_RulesLoop_Skip:
			cmp r0, r1			; compara r0 com 255
			jeq Main_RulesLoop	; Fica lendo ate' que digite uma tecla valida
			
	store IncRand, r2		; inicia o contador em um numero 'aleatorio'

	; Função que fica gerando numeros 
	Main_GeraNum:
		call GeraNum
		call DigiNum
		jmp Main_GeraNum

	halt		
;------------------------


;********************************************************
;                       GERA NUMERO
;********************************************************
GeraNum:
	push r0
	push r1
	push r2
	push r3
	push r4
	push r5
	push r6

	; sorteia nr. randomico entre 0 - 9
	load r1, IncRand
	loadn r2, #Rand 	; declara ponteiro para tabela rand na memoria!
	add r2, r2, r1		; Soma Incremento ao inicio da tabela Rand
						; r2 = Rand + IncRand
	loadi r3, r2 		; busca nr. randomico da memoria em r3
						; r3 = Rand(IncRand)
    inc r1	
	loadn r2, #200
	cmp r1, r2
	jne GeraNum_Skip
	loadn r1, #0
	GeraNum_Skip:
		store IncRand , r1;		

	GeraNum_Case0:
		loadn r2, #0			; Se Rand = 0
		cmp r3, r2				
		jne GeraNum_Case1
		loadn r2, #0 			; Inserindo o número gerado na variável
		store Num, r2			; Guardar Num aleatorio
		loadn r0, #0			; Posicao na tela
		loadn r1, #adivinheNum0	; Primeira tela de advinhacao
		loadn r2, #1280			; Seleciona cor
		jmp GeraNum_FimSwitch	; Break do Switch

   	GeraNum_Case1:
		loadn r2, #1			; Se Rand = 1
		cmp r3, r2				
		jne GeraNum_Case2
		loadn r2, #1
		store Num, r2
		loadn r0, #0
		loadn r1, #adivinheNum0
		loadn r2, #1280
		jmp GeraNum_FimSwitch	; Break do Switch

   	GeraNum_Case2:				
		loadn r2, #2			; Se Rand = 2
		cmp r3, r2
		jne GeraNum_Case3
		loadn r2, #2
		store Num, r2
		loadn r0, #0
		loadn r1, #adivinheNum0
		loadn r2, #1280	
		jmp GeraNum_FimSwitch	; Break do Switch

   	GeraNum_Case3:
		loadn r2, #3			; Se Rand = 3
		cmp r3, r2
		jne GeraNum_Case4
		loadn r2, #3
		store Num, r2
		loadn r0, #0
		loadn r1, #adivinheNum0
		loadn r2, #1280
		jmp GeraNum_FimSwitch	; Break do Switch

   	GeraNum_Case4:
		loadn r2, #4			; Se Rand = 4
		cmp r3, r2
		jne GeraNum_Case5
		loadn r2, #4
		store Num, r2
		loadn r0, #0
		loadn r1, #adivinheNum0
		loadn r2, #1280	
		jmp GeraNum_FimSwitch	; Break do Switch

   	GeraNum_Case5:
		loadn r2, #5			; Se Rand = 5
		cmp r3, r2
		jne GeraNum_Case6
		loadn r2, #5
		store Num, r2
		loadn r0, #0
		loadn r1, #adivinheNum0
		loadn r2, #1280	
		jmp GeraNum_FimSwitch	; Break do Switch

   	GeraNum_Case6:
		loadn r2, #6			; Se Rand = 6
		cmp r3, r2
		jne GeraNum_Case7
		loadn r2, #6
		store Num, r2
		loadn r0, #0
		loadn r1, #adivinheNum0
		loadn r2, #1280	
		jmp GeraNum_FimSwitch	; Break do Switch	

   	GeraNum_Case7:
		loadn r2, #7			; Se Rand = 7
		cmp r3, r2
		jne GeraNum_Case8
		loadn r2, #7
		store Num, r2
		loadn r0, #0
		loadn r1, #adivinheNum0
		loadn r2, #1280	
		jmp GeraNum_FimSwitch	; Break do Switch	

	GeraNum_Case8:
		loadn r2, #8			; Se Rand = 8
		cmp r3, r2
		jne GeraNum_Case9
		loadn r2, #8
		store Num, r2
		loadn r0, #0
		loadn r1, #adivinheNum0
		loadn r2, #1280	
		jmp GeraNum_FimSwitch	; Break do Switch	

	GeraNum_Case9:
		loadn r2, #9			; Se Rand = 9
		cmp r3, r2
		jne GeraNum_Fim
		loadn r2, #9
		store Num, r2
		loadn r0, #0
		loadn r1, #adivinheNum0
		loadn r2, #1280	
		jmp GeraNum_FimSwitch	; Break do Switch
		
 	; Fim Switch:
  	GeraNum_FimSwitch:		
  		call ImprimeTela		; Printa a primeira tela adivnheNum

  	GeraNum_Fim:
		pop r6
		pop r5
		pop r4
		pop r3
		pop r2
		pop r1
		pop r0
		rts
;------------------------


;********************************************************
;                   DIGITE UM NÚMERO
;********************************************************
DigiNum:						; Espera que uma tecla seja digitada
	push r0
	push r1
	push r2
	push r3
	push r4
	loadn r1, #255				; Se nao digitar nada vem 255
	DigiNum_Loop:
			inchar r0			; Le o teclado, se nada for digitado = 255
			cmp r0, r1			; Compara r0 com 255
			jeq DigiNum_Loop	; Fica lendo ate' que digite uma tecla valida
			load r1, Num        ; Numero aleatorio

		DigiNum_0:				; Como o inchar lê os números na forma de char, preciso fazer uma conversão criando novas funcoes que leiam como inteiros para assim efetuar as operacoes
			loadn r3, #'0'
			cmp r3, r0 
			jeq ComparaNum_0

		DigiNum_1:
			loadn r3, #'1'
			cmp r3, r0
			jeq ComparaNum_1

		DigiNum_2:
			loadn r3, #'2'
			cmp r3, r0
			jeq ComparaNum_2

		DigiNum_3:
			loadn r3, #'3'
			cmp r3, r0
			jeq ComparaNum_3

		DigiNum_4:
			loadn r3, #'4'
			cmp r3, r0
			jeq ComparaNum_4

		DigiNum_5:
			loadn r3, #'5'
			cmp r3, r0
			jeq ComparaNum_5

		DigiNum_6:
			loadn r3, #'6'
			cmp r3, r0
			jeq ComparaNum_6

		DigiNum_7:
			loadn r3, #'7'
			cmp r3, r0
			jeq ComparaNum_7

		DigiNum_8:
			loadn r3, #'8'
			cmp r3, r0
			jeq ComparaNum_8

		DigiNum_9:
			loadn r3, #'9'
			cmp r3, r0
			jeq ComparaNum_9

		jmp	Entrada_Invalida 		; Se nenhuma das entradas for um número indicar ao usuário

		ComparaNum_0:
			loadn r3, #0   			; Corresponder o char equivalente ao inteiro  poder fazer as comparacoes
			cmp r3, r1
			jgr DigiNum_Errou_Mais  ; Se o número inserido for maior
			jle DigiNum_Errou_Menos ; Se o número inserido for menor
			jeq DigiNum_Acertou		; Se for igual, termina o jogo

		ComparaNum_1:
			loadn r3, #1
			cmp r3, r1
			jgr DigiNum_Errou_Mais
			jle DigiNum_Errou_Menos
			jeq DigiNum_Acertou

		ComparaNum_2:
			loadn r3, #2
			cmp r3, r1
			jgr DigiNum_Errou_Mais
			jle DigiNum_Errou_Menos
			jeq DigiNum_Acertou

		ComparaNum_3:
			loadn r3, #3
			cmp r3, r1
			jgr DigiNum_Errou_Mais
			jle DigiNum_Errou_Menos
			jeq DigiNum_Acertou
								
		ComparaNum_4:
			loadn r3, #4
			cmp r3, r1
			jgr DigiNum_Errou_Mais
			jle DigiNum_Errou_Menos
			jeq DigiNum_Acertou

		ComparaNum_5:
			loadn r3, #5
			cmp r3, r1
			jgr DigiNum_Errou_Mais
			jle DigiNum_Errou_Menos
			jeq DigiNum_Acertou
			
		ComparaNum_6:
			loadn r3, #6
			cmp r3, r1
			jgr DigiNum_Errou_Mais
			jle DigiNum_Errou_Menos
			jeq DigiNum_Acertou
		
		ComparaNum_7:
			loadn r3, #7
			cmp r3, r1
			jgr DigiNum_Errou_Mais
			jle DigiNum_Errou_Menos
			jeq DigiNum_Acertou
										
		ComparaNum_8:
			loadn r3, #8
			cmp r3, r1
			jgr DigiNum_Errou_Mais
			jle DigiNum_Errou_Menos
			jeq DigiNum_Acertou

		ComparaNum_9:
			loadn r3, #9
			cmp r3, r1
			jgr DigiNum_Errou_Mais
			jle DigiNum_Errou_Menos
			jeq DigiNum_Acertou

	DigiNum_Errou_Menos:
		load r3, Tentativas				; Incrementa o contador de Tentativas
		inc r3
		store Tentativas, r3
		loadn r0, #0					; Posicao na tela onde a mensagem sera' escrita
		loadn r1, #adivinheNumMenor0	; Carrega r1 com o endereco do vetor que contem a mensagem
		loadn r2, #1280					; Seleciona a COR da Mensagem
		call ImprimeTela
		load r5, Tentativas
		loadn r6, #615
		call PrintaNumero				; Imprimindo tentativas
		jmp DigiNum

	DigiNum_Errou_Mais:
		load r3, Tentativas				; Incrementa o contador de Tentativas
		inc r3
		store Tentativas, r3
		loadn r0, #0					; Posicao na tela onde a mensagem sera' escrita
		loadn r1, #adivinheNumMaior0	; Carrega r1 com o endereco do vetor que contem a mensagem
		loadn r2, #1280					; Seleciona a COR da Mensagem
		call ImprimeTela
		load r5, Tentativas
		loadn r6, #615
		call PrintaNumero				; Imprimindo tentativas
		jmp DigiNum

	Entrada_Invalida:
		loadn r0, #0				; Posicao na tela onde a mensagem sera' escrita
		loadn r1, #invalidInput0	; Carrega r1 com o endereco do vetor que contem a mensagem
		loadn r2, #1280				; Seleciona a COR da Mensagem
		call ImprimeTela
		jmp DigiNum		

	DigiNum_Acertou:
		load r3, Tentativas			; Incrementa o contador de Tentativas
		inc r3
		store Tentativas, r3
		loadn r0, #0				; Posicao na tela onde a mensagem sera' escrita
		loadn r1, #telaFim0			; Carrega r1 com o endereco do vetor que contem a mensagem
		loadn r2, #768				; Seleciona a COR da Mensagem
		call ImprimeTela
		load r5, Tentativas
		loadn r6, #859
		call PrintaNumero			; Imprimindo tentativas
		load r5, Num				; Imprimindo número sorteado
		loadn r6, #953
		loadn r0, #10
		loadn r2, #48
		div r1, r5, r0	; Divide o numero por 10 para imprimir a dezena
		mul r1, r1, r0	; Multiplica a dezena por 10
		sub r1, r5, r1	; Pra subtrair do numero e pegar o resto
		add r1, r1, r2	; Soma 48 ao numero pra dar o Cod.  ASCII do numero
		outchar r1, r6		
		
		restartLoop:
			loadn r1, #'r'			; Se nao digitar nada vem 255
			inchar r0
			cmp r0, r1
			jeq Main
			jmp restartLoop
		halt 						; Encerra o programa
		
	DigiNum_Fim:
		pop r6
		pop r5
		pop r4
		pop r3
		pop r2
		pop r1
		pop r0
		rts
;------------------------	


;********************************************************
;                    PrintaNumero
;********************************************************

; Imprime um numero de 2 digitos na tela

PrintaNumero:		; R5 contem um numero de ate' 2 digitos e R6 a posicao onde vai imprimir na tela
	push r0
	push r1
	push r2
	push r3
	loadn r0, #10
	loadn r2, #48
	div r1, r5, r0	; Divide o numero por 10 para imprimir a dezena
	add r3, r1, r2	; Soma 48 ao numero pra dar o Cod.  ASCII do numero
	outchar r3, r6
	inc r6			; Incrementa a posicao na tela
	mul r1, r1, r0	; Multiplica a dezena por 10
	sub r1, r5, r1	; Pra subtrair do numero e pegar o resto
	add r1, r1, r2	; Soma 48 ao numero pra dar o Cod.  ASCII do numero
	outchar r1, r6
	pop r3
	pop r2
	pop r1
	pop r0
	rts
;------------------------		


;********************************************************
;                       IMPRIME TELA
;********************************************************
ImprimeTela: 	;  Rotina de Impresao de Cenario na Tela Inteira
				;  r1 = endereco onde comeca a primeira linha do Cenario
				;  r2 = cor do Cenario para ser impresso

	push r0	; protege o r3 na pilha para ser usado na subrotina
	push r1	; protege o r1 na pilha para preservar seu valor
	push r2	; protege o r1 na pilha para preservar seu valor
	push r3	; protege o r3 na pilha para ser usado na subrotina
	push r4	; protege o r4 na pilha para ser usado na subrotina
	push r5	; protege o r4 na pilha para ser usado na subrotina
	loadn r0, #0  	; posicao inicial tem que ser o comeco da tela!
	loadn r3, #40  	; Incremento da posicao da tela!
	loadn r4, #41  	; incremento do ponteiro das linhas da tela
	loadn r5, #1200 ; Limite da tela!

   ImprimeTela_Loop:
		call ImprimeStr
		add r0, r0, r3  		; incrementaposicao para a segunda linha na tela -->  r0 = R0 + 40
		add r1, r1, r4  		; incrementa o ponteiro para o comeco da proxima linha na memoria (40 + 1 porcausa do /0 !!) --> r1 = r1 + 41
		cmp r0, r5				; Compara r0 com 1200
		jne ImprimeTela_Loop	; Enquanto r0 < 1200

	pop r5	; Resgata os valores dos registradores utilizados na Subrotina da Pilha
	pop r4
	pop r3
	pop r2
	pop r1
	pop r0
	rts
;---------------------------


;********************************************************
;                   IMPRIME STRING
;********************************************************	
ImprimeStr:	;  Rotina de Impresao de Mensagens:    r0 = Posicao da tela que o primeiro caractere da mensagem sera' impresso;  r1 = endereco onde comeca a mensagem; r2 = cor da mensagem.   Obs: a mensagem sera' impressa ate' encontrar "/0"
	push r0	; protege o r0 na pilha para preservar seu valor
	push r1	; protege o r1 na pilha para preservar seu valor
	push r2	; protege o r1 na pilha para preservar seu valor
	push r3	; protege o r3 na pilha para ser usado na subrotina
	push r4	; protege o r4 na pilha para ser usado na subrotina
	loadn r3, #'\0'	; Criterio de parada

   ImprimeStr_Loop:	
		loadi r4, r1
		cmp r4, r3		; If (Char == \0)  vai Embora
		jeq ImprimeStr_Sai
		add r4, r2, r4	; Soma a Cor
		outchar r4, r0	; Imprime o caractere na tela
		inc r0			; Incrementa a posicao na tela
		inc r1			; Incrementa o ponteiro da String
		jmp ImprimeStr_Loop
	
   ImprimeStr_Sai:	
	pop r4	; Resgata os valores dos registradores utilizados na Subrotina da Pilha
	pop r3
	pop r2
	pop r1
	pop r0
	rts	
;---------------------------	

		
;---------------------------------- TELA INCIAL----------------------------------------------------------------
TelaInit0  : string "|======================================|"
TelaInit1  : string "|                                      |"
TelaInit2  : string "|                                      |"
TelaInit3  : string "|                                      |"
TelaInit4  : string "|         @@@ @ @ @@@ @@@ @@@          |"
TelaInit5  : string "|         @   @ @ @   @   @            |"
TelaInit6  : string "|         @@@ @ @ @@@ @@@ @@@          |"
TelaInit7  : string "|         @ @ @ @ @     @   @          |"
TelaInit8  : string "|         @@@ @@@ @@@ @@@ @@@          |"
TelaInit9  : string "|                                      |"
TelaInit10 : string "|              @@@ @@@ @               |"
TelaInit11 : string "|               @   @  @               |"
TelaInit12 : string "|               @   @  @               |"
TelaInit13 : string "|               @   @                  |"
TelaInit14 : string "|              @@@  @  @               |"
TelaInit15 : string "|                                      |"
TelaInit16 : string "|                                      |"
TelaInit17 : string "|                                      |"
TelaInit18 : string "|                                      |"
TelaInit19 : string "|                                      |"
TelaInit20 : string "|                                      |"
TelaInit21 : string "|                                      |"
TelaInit22 : string "|                                      |"
TelaInit23 : string "|                                      |"
TelaInit24 : string "|        Press any key to start        |"
TelaInit25 : string "|        _____ ___ ___ __ _____        |"
TelaInit26 : string "|                                      |"
TelaInit27 : string "|                                      |"
TelaInit28 : string "|                                      |"  
TelaInit29 : string "|======================================|"


;--------------------------------- COMANDOS ---------------------------------------------------------------
TelaReg0  : string "|======================================|"
TelaReg1  : string "|                                      |"
TelaReg2  : string "|                RULES!                |"
TelaReg3  : string "|                                      |"
TelaReg4  : string "|                                      |"
TelaReg5  : string "|   -Type any number until you         |"
TelaReg6  : string "|                                      |"
TelaReg7  : string "|    match it with the raffled one.    |"
TelaReg8  : string "|                                      |"
TelaReg9  : string "|                                      |"
TelaReg10 : string "|   -Raffled numbers can be from 0     |"
TelaReg11 : string "|                                      |"
TelaReg12 : string "|    to 9.                             |"
TelaReg13 : string "|                                      |"
TelaReg14 : string "|                                      |"
TelaReg15 : string "|                                      |"
TelaReg16 : string "|                                      |"
TelaReg17 : string "|                                      |"
TelaReg18 : string "|                                      |"
TelaReg19 : string "|                                      |"
TelaReg20 : string "|                                      |"
TelaReg21 : string "|                                      |"
TelaReg22 : string "|                                      |"
TelaReg23 : string "|                                      |"
TelaReg24 : string "|        Press any key to play!        |"
TelaReg25 : string "|        _____ ___ ___ __ _____        |"
TelaReg26 : string "|                                      |"
TelaReg27 : string "|                                      |"
TelaReg28 : string "|                                      |"
TelaReg29 : string "|======================================|"


;---------------------------------- TELA ADIVINHE O NÚMERO----------------------------------------------------------------	
adivinheNum0  : string "                                        "
adivinheNum1  : string "                                        "
adivinheNum2  : string "                                        "
adivinheNum3  : string "                                        "
adivinheNum4  : string "                                        "
adivinheNum5  : string "                                        "
adivinheNum6  : string "                                        "
adivinheNum7  : string "                                        "
adivinheNum8  : string "                                        "
adivinheNum9  : string "                                        "
adivinheNum10 : string "                                        "
adivinheNum11 : string "                                        "
adivinheNum12 : string "                                        "
adivinheNum13 : string "       GIVE YOUR GUESS !                "
adivinheNum14 : string "                                        "
adivinheNum15 : string "       ENTER A NUMBER FROM 0 TO 9.      "
adivinheNum16 : string "                                        "
adivinheNum17 : string "                                        "
adivinheNum18 : string "                                        "
adivinheNum19 : string "                                        "
adivinheNum20 : string "                                        "
adivinheNum21 : string "                                        "
adivinheNum22 : string "                                        "
adivinheNum23 : string "                                        "
adivinheNum24 : string "                                        "
adivinheNum25 : string "                                        "
adivinheNum26 : string "                                        "
adivinheNum27 : string "                                        "
adivinheNum28 : string "                                        "
adivinheNum29 : string "                                        "

;---------------------------------- TELA TOO BIG----------------------------------------------------------------	
adivinheNumMaior0  : string "                                        "
adivinheNumMaior1  : string "                                        "
adivinheNumMaior2  : string "                                        "
adivinheNumMaior3  : string "                                        "
adivinheNumMaior4  : string "                                        "
adivinheNumMaior5  : string "                                        "
adivinheNumMaior6  : string "                                        "
adivinheNumMaior7  : string "                                        "
adivinheNumMaior8  : string "                                        "
adivinheNumMaior9  : string "                                        "
adivinheNumMaior10 : string "                                        "
adivinheNumMaior11 : string "                                        "
adivinheNumMaior12 : string "                                        "
adivinheNumMaior13 : string "          TOO BIG, TRY AGAIN !          "
adivinheNumMaior14 : string "                                        "
adivinheNumMaior15 : string "                   GUESSES !            "
adivinheNumMaior16 : string "                                        "
adivinheNumMaior17 : string "                                        "
adivinheNumMaior18 : string "                                        "
adivinheNumMaior19 : string "                                        "
adivinheNumMaior20 : string "                                        "
adivinheNumMaior21 : string "                                        "
adivinheNumMaior22 : string "                                        "
adivinheNumMaior23 : string "                                        "
adivinheNumMaior24 : string "                                        "
adivinheNumMaior25 : string "                                        "
adivinheNumMaior26 : string "                                        "
adivinheNumMaior27 : string "                                        "
adivinheNumMaior28 : string "                                        "
adivinheNumMaior29 : string "                                        "



;---------------------------------- TELA TOO SMALL----------------------------------------------------------------	
adivinheNumMenor0  : string "                                        "
adivinheNumMenor1  : string "                                        "
adivinheNumMenor2  : string "                                        "
adivinheNumMenor3  : string "                                        "
adivinheNumMenor4  : string "                                        "
adivinheNumMenor5  : string "                                        "
adivinheNumMenor6  : string "                                        "
adivinheNumMenor7  : string "                                        "
adivinheNumMenor8  : string "                                        "
adivinheNumMenor9  : string "                                        "
adivinheNumMenor10 : string "                                        "
adivinheNumMenor11 : string "                                        "
adivinheNumMenor12 : string "                                        "
adivinheNumMenor13 : string "          TOO SMALL, TRY AGAIN !        "
adivinheNumMenor14 : string "                                        " 
adivinheNumMenor15 : string "                   GUESSES !            "
adivinheNumMenor16 : string "                                        "
adivinheNumMenor17 : string "                                        "
adivinheNumMenor18 : string "                                        "
adivinheNumMenor19 : string "                                        "
adivinheNumMenor20 : string "                                        "
adivinheNumMenor21 : string "                                        "
adivinheNumMenor22 : string "                                        "
adivinheNumMenor23 : string "                                        "
adivinheNumMenor24 : string "                                        "
adivinheNumMenor25 : string "                                        "
adivinheNumMenor26 : string "                                        "
adivinheNumMenor27 : string "                                        "
adivinheNumMenor28 : string "                                        "
adivinheNumMenor29 : string "                                        "

;---------------------------------- TELA ENTRADA INVALIDA----------------------------------------------------------------	
invalidInput0  : string "                                        "
invalidInput1  : string "                                        "
invalidInput2  : string "                                        "
invalidInput3  : string "                                        "
invalidInput4  : string "                                        "
invalidInput5  : string "                                        "
invalidInput6  : string "                                        "
invalidInput7  : string "                                        "
invalidInput8  : string "                                        "
invalidInput9  : string "                                        "
invalidInput10 : string "                                        "
invalidInput11 : string "                                        "
invalidInput12 : string "                                        "
invalidInput13 : string "                                        "
invalidInput14 : string "       INVALID INPUT, TRY AGAIN !       "
invalidInput15 : string "                                        "
invalidInput16 : string "                                        "
invalidInput17 : string "                                        "
invalidInput18 : string "                                        "
invalidInput19 : string "                                        "
invalidInput20 : string "                                        "
invalidInput21 : string "                                        "
invalidInput22 : string "                                        "
invalidInput23 : string "                                        "
invalidInput24 : string "                                        "
invalidInput25 : string "                                        "
invalidInput26 : string "                                        "
invalidInput27 : string "                                        "
invalidInput28 : string "                                        "
invalidInput29 : string "                                        "

;---------------------------------- FIM DE JOGO ----------------------------------------------------------------
telaFim0  : string "|======================================|"
telaFim1  : string "|                                      |"
telaFim2  : string "|                                      |"
telaFim3  : string "|                                      |"
telaFim4  : string "|           @@@ @@@ @ @ @@@            |"
telaFim5  : string "|           @   @ @ @@@ @              |"
telaFim6  : string "|           @@@ @@@ @@@ @@@            |"
telaFim7  : string "|           @ @ @ @ @ @ @              |"
telaFim8  : string "|           @@@ @ @ @ @ @@@            |"
telaFim9  : string "|           ___ ___ ___ ___            |"
telaFim10 : string "|                                      |"
telaFim11 : string "|                                      |"
telaFim12 : string "|           @@@ @ @ @@@ @@  @          |"
telaFim13 : string "|           @ @ @ @ @   @ @ @          |"
telaFim14 : string "|           @ @ @ @ @@@ @@  @          |"
telaFim15 : string "|           @ @ @ @ @   @ @            |"
telaFim16 : string "|           @@@  @  @@@ @ @ @          |"
telaFim17 : string "|           ___ ___ ___ ___ _          |"
telaFim18 : string "|                                      |"
telaFim19 : string "|             You've tried             |"
telaFim20 : string "|                                      |"
telaFim21 : string "|                                      |"
telaFim22 : string "|                                      |"
telaFim23 : string "|      times to guess the number       |"
telaFim24 : string "|                                      |"
telaFim25 : string "|       Press R Restart the Game       |"
telaFim26 : string "|       _____ _ _______ ___ ____       |"
telaFim27 : string "|                                      |"
telaFim28 : string "|                                      |"
telaFim29 : string "|======================================|"
