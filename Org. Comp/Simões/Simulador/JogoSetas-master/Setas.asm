; Hello World - Escreve mensagem armazenada na memoria na tela


; ------- TABELA DE CORES -------
; adicione ao caracter para Selecionar a cor correspondente

; 0 branco							0000 0000
; 256 marrom						0001 0000
; 512 verde							0010 0000
; 768 oliva							0011 0000
; 1024 azul marinho					0100 0000
; 1280 ro@o							0101 0000
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
Rand : var #200			; Tabela de nr. Randomicos entre 0 - 7
	static Rand + #0, #5
	static Rand + #1, #7
	static Rand + #2, #8
	static Rand + #3, #3
	static Rand + #4, #11
	static Rand + #5, #5
	static Rand + #6, #4
	static Rand + #7, #10
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
	static Rand + #25, #11
	static Rand + #26, #11
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
	static Rand + #45, #10
	static Rand + #46, #10
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
	static Rand + #62, #11
	static Rand + #63, #10
	static Rand + #64, #9
	static Rand + #65, #8
	static Rand + #66, #5
	static Rand + #67, #8
	static Rand + #68, #5
	static Rand + #69, #2
	static Rand + #70, #3
	static Rand + #71, #11
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
	static Rand + #85, #10
	static Rand + #86, #8
	static Rand + #87, #4
	static Rand + #88, #4
	static Rand + #89, #2
	static Rand + #90, #9
	static Rand + #91, #10
	static Rand + #92, #9
	static Rand + #93, #0
	static Rand + #94, #0
	static Rand + #95, #7
	static Rand + #96, #0
	static Rand + #97, #5
	static Rand + #98, #7
	static Rand + #99, #6
	static Rand + #100, #11
	static Rand + #101, #10
	static Rand + #102, #5
	static Rand + #103, #5
	static Rand + #104, #5
	static Rand + #105, #4
	static Rand + #106, #10
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
	static Rand + #120, #11
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
	static Rand + #135, #11
	static Rand + #136, #10
	static Rand + #137, #11
	static Rand + #138, #5
	static Rand + #139, #4
	static Rand + #140, #6
	static Rand + #141, #4
	static Rand + #142, #8
	static Rand + #143, #3
	static Rand + #144, #10
	static Rand + #145, #5
	static Rand + #146, #11
	static Rand + #147, #3
	static Rand + #148, #2
	static Rand + #149, #11
	static Rand + #150, #8
	static Rand + #151, #5
	static Rand + #152, #1
	static Rand + #153, #11
	static Rand + #154, #1
	static Rand + #155, #3
	static Rand + #156, #6
	static Rand + #157, #1
	static Rand + #158, #5
	static Rand + #159, #10
	static Rand + #160, #8
	static Rand + #161, #6
	static Rand + #162, #2
	static Rand + #163, #1
	static Rand + #164, #0
	static Rand + #165, #2
	static Rand + #166, #4
	static Rand + #167, #10
	static Rand + #168, #5
	static Rand + #169, #10
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
	static Rand + #182, #11
	static Rand + #183, #11
	static Rand + #184, #0
	static Rand + #185, #4
	static Rand + #186, #2
	static Rand + #187, #6
	static Rand + #188, #5
	static Rand + #189, #0
	static Rand + #190, #9
	static Rand + #191, #5
	static Rand + #192, #10
	static Rand + #193, #3
	static Rand + #194, #7
	static Rand + #195, #10
	static Rand + #196, #9
	static Rand + #197, #11
	static Rand + #198, #0
	static Rand + #199, #3
	
Seta: var #1			; direcao da seta
Cor: var #1				; cor da seta
Pontos: var #1			; pontos

;---- Inicio do Programa Principal -----
 
Main:
	loadn r0, #0			; Posicao na tela onde a mensagem sera' escrita	
	store Seta, r0			; incializa a seta
	store Cor, r0			; incializa a cor
	store Pontos, r0		; incializa os pontos
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
			cmp r0, r1			;compara r0 com 255
			jeq Main_RulesLoop	; Fica lendo ate' que digite uma tecla valida
	
	store IncRand, r2		; inicia o contador em um numero 'aleatorio'
	
	; Função que fica gerando setas 
	Main_GeraSeta:
		call GeraSeta
		call DigLetra
		jmp Main_GeraSeta

	halt	
	
;********************************************************
;                       GERA SETA
;********************************************************		
GeraSeta:
	push r0
	push r1
	push r2
	push r3
	push r4
	push r5
	push r6

	; sorteia nr. randomico entre 0 - 11
	load r1, IncRand
	loadn r2, #Rand 	; declara ponteiro para tabela rand na memoria!
	add r2, r2, r1		; Soma Incremento ao inicio da tabela Rand
						; r2 = Rand + IncRand
	loadi r3, r2 		; busca nr. randomico da memoria em r3
						; r3 = Rand(IncRand)
    	inc r1;
	loadn r2 , #200
	cmp r1 , r2
	jne GeraSeta_Skip	
	loadn r1 , #0
	GeraSeta_Skip:
		store IncRand , r1;		

	; Case 0 : Seta Cima Verde
	GeraSeta_Case0:
		loadn r2, #0
		cmp r3, r2	; Se Rand = 0
		jne GeraSeta_Case1
		loadn r2, #'i'
		store Seta, r2
		loadn r0, #0
		loadn r1, #setaCima0
		loadn r2, #512
		store Cor, r2
		jmp GeraSeta_FimSwitch	; Break do Switch

 	; Case 1 : Seta Direita Verde
   	GeraSeta_Case1:
		loadn r2, #1
		cmp r3, r2	; Se Rand = 1
		jne GeraSeta_Case2
		loadn r2, #'l'
		store Seta, r2
		loadn r0, #0
		loadn r1, #setaDir0
		loadn r2, #512
		store Cor, r2
		jmp GeraSeta_FimSwitch	; Break do Switch

	; Case 2 : Seta Baixo Verde
   	GeraSeta_Case2:
		loadn r2, #2	; Se Rand = 2
		cmp r3, r2
		jne GeraSeta_Case3
		loadn r2, #'k'
		store Seta, r2
		loadn r0, #0
		loadn r1, #setaBaixo0
		loadn r2, #512	
		store Cor, r2
		jmp GeraSeta_FimSwitch	; Break do Switch

 	; Case 3 : Seta Esquerda Verde
   	GeraSeta_Case3:
		loadn r2, #3	; Se Rand = 3
		cmp r3, r2
		jne GeraSeta_Case4
		loadn r2, #'j'
		store Seta, r2
		loadn r0, #0
		loadn r1, #setaEsq0
		loadn r2, #512	
		store Cor, r2
		jmp GeraSeta_FimSwitch	; Break do Switch

 	; Case 4 : Seta Cima Vermelho	
   	GeraSeta_Case4:
		loadn r2, #4	; Se Rand = 4
		cmp r3, r2
		jne GeraSeta_Case5
		loadn r2, #'i'
		store Seta, r2
		loadn r0, #0
		loadn r1, #setaCima0
		loadn r2, #2304	
		store Cor, r2
		jmp GeraSeta_FimSwitch	; Break do Switch

 	; Case 5 : Seta Direita Veremelho
   	GeraSeta_Case5:
		loadn r2, #5	; Se Rand = 5
		cmp r3, r2
		jne GeraSeta_Case6
		loadn r2, #'l'
		store Seta, r2
		loadn r0, #0
		loadn r1, #setaDir0
		loadn r2, #2304	
		store Cor, r2
		jmp GeraSeta_FimSwitch	; Break do Switch

 	; Case 6 : Seta Baixo Vermelho
   	GeraSeta_Case6:
		loadn r2, #6	; Se Rand = 6
		cmp r3, r2
		jne GeraSeta_Case7
		loadn r2, #'k'
		store Seta, r2
		loadn r0, #0
		loadn r1, #setaBaixo0
		loadn r2, #2304	
		store Cor, r2
		jmp GeraSeta_FimSwitch	; Break do Switch	

 	; Case 7 : Seta Esuquerda Vermelho
   	GeraSeta_Case7:
		loadn r2, #7	; Se Rand = 7
		cmp r3, r2
		jne GeraSeta_Case8
		loadn r2, #'j'
		store Seta, r2
		loadn r0, #0
		loadn r1, #setaEsq0
		loadn r2, #2304	
		store Cor, r2
		jmp GeraSeta_FimSwitch	; Break do Switch	

	; Case 8 : Seta Cima Azul
	GeraSeta_Case8:
		loadn r2, #8	; Se Rand = 8
		cmp r3, r2
		jne GeraSeta_Case9
		loadn r2, #'i'
		store Seta, r2
		loadn r0, #0
		loadn r1, #setaCima0
		loadn r2, #3072	
		store Cor, r2
		jmp GeraSeta_FimSwitch	; Break do Switch	

	; Case 9 : Seta Direita Azul
	GeraSeta_Case9:
		loadn r2, #9	; Se Rand = 9
		cmp r3, r2
		jne GeraSeta_Case10
		loadn r2, #'l'
		store Seta, r2
		loadn r0, #0
		loadn r1, #setaDir0
		loadn r2, #3072	
		store Cor, r2
		jmp GeraSeta_FimSwitch	; Break do Switch	

	; Case 10 : Seta Baixo Azul
	GeraSeta_Case10:
		loadn r2, #10	; Se Rand = 10
		cmp r3, r2
		jne GeraSeta_Case11
		loadn r2, #'k'
		store Seta, r2
		loadn r0, #0
		loadn r1, #setaBaixo0
		loadn r2, #3072	
		store Cor, r2
		jmp GeraSeta_FimSwitch	; Break do Switch	

	; Case 11 : Seta Esquerda Azul
	GeraSeta_Case11:
		loadn r2, #11	; Se Rand = 11
		cmp r3, r2
		jne GeraSeta_Fim
		loadn r2, #'j'
		store Seta, r2
		loadn r0, #0
		loadn r1, #setaEsq0
		loadn r2, #3072
		store Cor, r2	

 	; Fim Switch:
  	GeraSeta_FimSwitch:				
  		;call ApagaTela							;Apaga a tela 			
  		call ImprimeTela						;Printa a seta	  		
  		
  	GeraSeta_Fim:
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
;                   DIGITE UMA LETRA
;********************************************************

DigLetra:	; Espera que uma tecla seja digitada
	push r0
	push r1
	push r2
	push r3
	
	loadn r1, #255	; Se nao digitar nada vem 255
	loadn r2, #0	; limite de tempo
	loadn r3, #2000	; valor de controle do tempo minimo
	
	DigLetra_Loop:
		inc r2
		cmp r2, r3
		; breakp
		jne DigLetra_Loop_Skip
			loadn r2, #0
			dec r3
			cmp r2, r3			; valor limite = r3! (fatorial)
			jeq DigLetra_Errou
		
		DigLetra_Loop_Skip: 
			inchar r0			; Le o teclado, se nada for digitado = 255
			cmp r0, r1			;compara r0 com 255
			jeq DigLetra_Loop	; Fica lendo ate' que digite uma tecla valida
	
	load r1, Seta
	load r2, Cor
	;breakp
	DigLetra_Verde:
		loadn r3, #512	; verde -> segue
		cmp r2, r3
		;breakp
		jne DigLetra_Vermelho
		;breakp
		cmp r0, r1
		jne DigLetra_Errou
		jmp DigLetra_Acertou
			
	DigLetra_Vermelho:
		loadn r3, #2304	; vermelho -> contrario
		cmp r2, r3
		;breakp
		jne DigLetra_Azul
		
		DigLetra_Vermelho_Cima:
			loadn r3, #'i'
			cmp r1, r3
			jne DigLetra_Vermelho_Direita
			loadn r3, #'k'
			cmp r0, r3
			jne DigLetra_Errou
			jmp DigLetra_Acertou
			
		DigLetra_Vermelho_Direita:
			loadn r3, #'l'
			cmp r1, r3
			jne DigLetra_Vermelho_Baixo
			loadn r3, #'j'
			cmp r0, r3
			jne DigLetra_Errou
			jmp DigLetra_Acertou
			
		DigLetra_Vermelho_Baixo:
			loadn r3, #'k'
			cmp r1, r3
			jne DigLetra_Vermelho_Esquerda
			loadn r3, #'i'
			cmp r0, r3
			jne DigLetra_Errou
			jmp DigLetra_Acertou
			
		DigLetra_Vermelho_Esquerda:
			loadn r3, #'j'
			cmp r1, r3
			jne DigLetra_Errou
			loadn r3, #'l'
			cmp r0, r3
			jne DigLetra_Errou
			jmp DigLetra_Acertou
		
		
	DigLetra_Azul:
		loadn r3, #3072	; azul -> negado
		cmp r2, r3
		;breakp
		jne DigLetra_Errou
		cmp r0, r1
		jeq DigLetra_Errou
		jmp DigLetra_Acertou
	
	DigLetra_Acertou:
		load r3, Pontos		; incrementa o contador de pontos
		inc r3
		store Pontos, r3
		jmp DigLetra_Fim
		
	DigLetra_Errou:
		loadn r0, #0			; Posicao na tela onde a mensagem sera' escrita
		loadn r1, #telaFim0	; Carrega r1 com o endereco do vetor que contem a mensagem
		loadn r2, #2304			; Seleciona a COR da Mensagem
		call ImprimeTela
		load r5, Pontos
		loadn r6, #661
		call PrintaNumero
		
		
		restartLoop:
			loadn r1, #'r'	; Se nao digitar nada vem 255
			inchar r0
			cmp r0, r1
			jeq Main
			jmp restartLoop
		
		
		halt 					; encerra o programa
		
	DigLetra_Fim:
		pop r3
		pop r2
		pop r1
		pop r0
		rts	


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
		add r0, r0, r3  	; incrementaposicao para a segunda linha na tela -->  r0 = R0 + 40
		add r1, r1, r4  	; incrementa o ponteiro para o comeco da proxima linha na memoria (40 + 1 porcausa do /0 !!) --> r1 = r1 + 41
		cmp r0, r5			; Compara r0 com 1200
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
;------------------------	

;********************************************************
;                    PrintaNumero
;********************************************************

; Imprime um numero de 2 digitos na tela

PrintaNumero:	; R5 contem um numero de ate' 2 digitos e R6 a posicao onde vai imprimir na tela

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

;;---------------------------------- SETA DA CIMA----------------------------------------------------------------	
setaCima0  : string "                                        "
setaCima1  : string "                                        "
setaCima2  : string "                                        "
setaCima3  : string "                   @                    "
setaCima4  : string "                  @@@                   "
setaCima5  : string "                 @@@@@                  "
setaCima6  : string "                @@@@@@@                 "
setaCima7  : string "               @@@@@@@@@                "
setaCima8  : string "              @@@@@@@@@@@               "
setaCima9  : string "                 @@@@@                  "
setaCima10 : string "                 @@@@@                  "
setaCima11 : string "                 @@@@@                  "
setaCima12 : string "                 @@@@@                  "
setaCima13 : string "                 @@@@@                  "
setaCima14 : string "                 @@@@@                  "
setaCima15 : string "                 @@@@@                  "
setaCima16 : string "                 @@@@@                  "
setaCima17 : string "                 @@@@@                  "
setaCima18 : string "                 @@@@@                  "
setaCima19 : string "                 @@@@@                  "
setaCima20 : string "                 @@@@@                  "
setaCima21 : string "                 @@@@@                  "
setaCima22 : string "                 @@@@@                  "
setaCima23 : string "                 @@@@@                  "
setaCima24 : string "                 @@@@@                  "
setaCima25 : string "                                        "
setaCima26 : string "                                        "
setaCima27 : string "                                        "
setaCima28 : string "                                        "
setaCima29 : string "                                        "

;;---------------------------------- SETA DA DIREITA----------------------------------------------------------------
setaDir0  : string "                                        "
setaDir1  : string "                                        "
setaDir2  : string "                                        "
setaDir3  : string "                                        "
setaDir4  : string "                                        "
setaDir5  : string "                                        "
setaDir6  : string "                                        "
setaDir7  : string "                           @            "
setaDir8  : string "                           @@           "
setaDir9  : string "                           @@@          "
setaDir10 : string "        @@@@@@@@@@@@@@@@@@@@@@@         "
setaDir11 : string "        @@@@@@@@@@@@@@@@@@@@@@@@        "
setaDir12 : string "        @@@@@@@@@@@@@@@@@@@@@@@@@       "
setaDir13 : string "        @@@@@@@@@@@@@@@@@@@@@@@@        "
setaDir14 : string "        @@@@@@@@@@@@@@@@@@@@@@@         "
setaDir15 : string "                           @@@          "
setaDir16 : string "                           @@           "
setaDir17 : string "                           @            "
setaDir18 : string "                                        "
setaDir19 : string "                                        "
setaDir20 : string "                                        "
setaDir21 : string "                                        "
setaDir22 : string "                                        "
setaDir23 : string "                                        "
setaDir24 : string "                                        "
setaDir25 : string "                                        "
setaDir26 : string "                                        "
setaDir27 : string "                                        "
setaDir28 : string "                                        "
setaDir29 : string "                                        "

;;---------------------------------- SETA DA ESQUERDA----------------------------------------------------------------
setaEsq0  : string "                                        "
setaEsq1  : string "                                        "
setaEsq2  : string "                                        "
setaEsq3  : string "                                        "
setaEsq4  : string "                                        "
setaEsq5  : string "                                        "
setaEsq6  : string "                                        "
setaEsq7  : string "             @                          "
setaEsq8  : string "            @@                          "
setaEsq9  : string "           @@@                          "
setaEsq10 : string "          @@@@@@@@@@@@@@@@@@@@@@@       "
setaEsq11 : string "         @@@@@@@@@@@@@@@@@@@@@@@@       "
setaEsq12 : string "        @@@@@@@@@@@@@@@@@@@@@@@@@       "
setaEsq13 : string "         @@@@@@@@@@@@@@@@@@@@@@@@       "
setaEsq14 : string "          @@@@@@@@@@@@@@@@@@@@@@@       "
setaEsq15 : string "           @@@                          "
setaEsq16 : string "            @@                          "
setaEsq17 : string "             @                          "
setaEsq18 : string "                                        "
setaEsq19 : string "                                        "
setaEsq20 : string "                                        "
setaEsq21 : string "                                        "
setaEsq22 : string "                                        "
setaEsq23 : string "                                        "
setaEsq24 : string "                                        "
setaEsq25 : string "                                        "
setaEsq26 : string "                                        "
setaEsq27 : string "                                        "
setaEsq28 : string "                                        "
setaEsq29 : string "                                        "

;;---------------------------------- SETA PARA BAIXO----------------------------------------------------------------
setaBaixo0   : string "                                        "
setaBaixo1   : string "                                        "
setaBaixo2   : string "                                        "
setaBaixo3   : string "                 @@@@@                  "
setaBaixo4   : string "                 @@@@@                  "
setaBaixo5   : string "                 @@@@@                  "
setaBaixo6   : string "                 @@@@@                  "
setaBaixo7   : string "                 @@@@@                  "
setaBaixo8   : string "                 @@@@@                  "
setaBaixo9   : string "                 @@@@@                  "
setaBaixo10  : string "                 @@@@@                  "
setaBaixo11  : string "                 @@@@@                  "
setaBaixo12  : string "                 @@@@@                  "
setaBaixo13  : string "                 @@@@@                  "
setaBaixo14  : string "                 @@@@@                  "
setaBaixo15  : string "                 @@@@@                  "
setaBaixo16  : string "                 @@@@@                  "
setaBaixo17  : string "                 @@@@@                  "
setaBaixo18  : string "                 @@@@@                  "
setaBaixo19  : string "              @@@@@@@@@@@               "
setaBaixo20  : string "               @@@@@@@@@                "
setaBaixo21  : string "                @@@@@@@                 "
setaBaixo22  : string "                 @@@@@                  "
setaBaixo23  : string "                  @@@                   "
setaBaixo24  : string "                   @                    "
setaBaixo25  : string "                                        "
setaBaixo26  : string "                                        "
setaBaixo27  : string "                                        "
setaBaixo28  : string "                                        "
setaBaixo29  : string "                                        "


;;---------------------------------- TELA INCIAL----------------------------------------------------------------
TelaInit0  : string "|''''''''''''''''''''''''''''''''''''''|"
TelaInit1  : string "|                                      |"
TelaInit2  : string "|                                      |"
TelaInit3  : string "|                                      |"
TelaInit4  : string "|      XXX XXX XXX XXX X X XXX  X      |"
TelaInit5  : string "|      X X X X X X X X X X X    X      |"
TelaInit6  : string "|      XXX XX  XX  X X X X XXX  X      |"
TelaInit7  : string "|      X X X X X X X X XXX   X         |"
TelaInit8  : string "|      X X X X X X XXX X X XXX  X      |"
TelaInit9  : string "|                                      |"
TelaInit10 : string "|                                      |"
TelaInit11 : string "|                                      |"
TelaInit12 : string "|                                      |"
TelaInit13 : string "|                                      |"
TelaInit14 : string "|                                      |"
TelaInit15 : string "|                                      |"
TelaInit16 : string "|                                      |"
TelaInit17 : string "|                                      |"
TelaInit18 : string "|                                      |"
TelaInit19 : string "|                                      |"
TelaInit20 : string "|                                      |"
TelaInit21 : string "|                                      |"
TelaInit22 : string "|                                      |"
TelaInit23 : string "|                                      |"
TelaInit24 : string "|         Press a key to start         |"
TelaInit25 : string "|         _____ _ ___ __ _____         |"
TelaInit26 : string "|                                      |"
TelaInit27 : string "|                                      |"
TelaInit28 : string "|                                      |"  
TelaInit29 : string "|,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,|"

;;---------------------------------- FIM DE JOGO ----------------------------------------------------------------
telaFim0  : string "|''''''''''''''''''''''''''''''''''''''|"
telaFim1  : string "|                                      |"
telaFim2  : string "|                                      |"
telaFim3  : string "|                                      |"
telaFim4  : string "|      X   XXX XXX XXX XXX XXX  X      |"
telaFim5  : string "|      X   X X X X X   X   X X  X      |"
telaFim6  : string "|      X   X X X X XXX XXX XX   X      |"
telaFim7  : string "|      X   X X X X   X X   X X         |"
telaFim8  : string "|      XXX XXX XXX XXX XXX X X  X      |"
telaFim9  : string "|                                      |"
telaFim10 : string "|      ==========================      |"
telaFim11 : string "|                                      |"
telaFim12 : string "|                                      |"
telaFim13 : string "|                                      |"
telaFim14 : string "|                                      |"
telaFim15 : string "|                                      |"
telaFim16 : string "|             SCORE:                   |"
telaFim17 : string "|                                      |"
telaFim18 : string "|                                      |"
telaFim19 : string "|                                      |"
telaFim20 : string "|                                      |"
telaFim21 : string "|       Press R Restart the Game       |"
telaFim22 : string "|           _______ ___ ____           |"
telaFim23 : string "|                                      |"
telaFim24 : string "|                                      |"
telaFim25 : string "|                                      |"
telaFim26 : string "|                                      |"
telaFim27 : string "|                                      |"
telaFim28 : string "|                                      |"
telaFim29 : string "|,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,|"


;;--------------------------------- COMANDOS ---------------------------------------------------------------
TelaReg0  : string "|''''''''''''''''''''''''''''''''''''''|"
TelaReg1  : string "|                                      |"
TelaReg2  : string "|                RULES!                |"
TelaReg3  : string "|                                      |"
TelaReg4  : string "|                                      |"
TelaReg5  : string "|    GREEN - Follow the direction      |"
TelaReg6  : string "|                                      |"
TelaReg7  : string "|    RED - Press the opposite          |"
TelaReg8  : string "|                                      |"
TelaReg9  : string "|    BLUE - Choose any other direction |"
TelaReg10 : string "|                                      |"
TelaReg11 : string "|                                      |"
TelaReg12 : string "|                                      |"
TelaReg13 : string "|             ___________              |"
TelaReg14 : string "|            |           |             |"
TelaReg15 : string "|            | UP    - I |             |"
TelaReg16 : string "|            |           |             |"
TelaReg17 : string "|            | DOWN  - K |             |"
TelaReg18 : string "|            |           |             |"
TelaReg19 : string "|            | RIGHT - L |             |"
TelaReg20 : string "|            |           |             |"
TelaReg21 : string "|            | LEFT  - J |             |"
TelaReg22 : string "|            |___________|             |"
TelaReg23 : string "|                                      |"
TelaReg24 : string "|                                      |"
TelaReg25 : string "|                                      |"
TelaReg26 : string "|                                      |"
TelaReg27 : string "|         Press a key to play!         |"
TelaReg28 : string "|                                      |"
TelaReg29 : string "|,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,|"