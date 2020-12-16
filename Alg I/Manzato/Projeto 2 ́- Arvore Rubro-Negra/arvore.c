#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arvore.h"

arvore *criarArvore() {
    arvore *a = (arvore *)malloc(sizeof(arvore));
    a->raiz = NULL;
    return a;
}

int checarVerm(no *raiz) {
    if(raiz == NULL) return 0; //0 é Negro
    return(raiz->cor == 1); //1 é Vermelho
}

void trocarCor(no *no_1, no *no_2) {
    int aux = no_1->cor; //copiando a cor de no_1
    no_1->cor = no_2->cor; //atribuinda a cor de no_2 à no_1
    no_2->cor = aux; //atribuindo a cópia de no_1 anterior
}

//rodando a árvore no sentido anti-horário
no *girarEsq(no *raiz) {
    no *filho = raiz->dir;
    no *filhoEsq = filho->esq;
    filho->esq = raiz;
    raiz->dir = filhoEsq;
    return filho;
}

//rodando a árvore no sentido horário
no *girarDir(no *raiz) {
    no *filho = raiz->esq;
    no *filhoDir =  filho->dir;
    filho->dir = raiz;
    raiz->esq = filhoDir;
    return filho;
}

/*IMPLEMENTACAO DA INSERCAO DE MANEIRA RECURSIVA COM BALANCEAMENTO*/
no *inserir(no *raiz, elem x) {
    if(raiz == NULL) { //criar novo no se a raiz for nula
        no *aux = (no *)malloc(sizeof(no));
        aux->info = x;
        aux->esq = NULL;
        aux->dir = NULL;
        aux->cor = 1; //novo no sempre Vermelho
        
        return aux;
    }
    else if(x < raiz->info) { //inserindo à esquerda chamando a recursão
        raiz->esq = inserir(raiz->esq, x);
    }
    else if(x > raiz->info){ //inserindo à direita chamando a recursão
        raiz->dir = inserir(raiz->dir, x);
    }
    else{ //elemento já existente
        return raiz;
    }

    //para caso o filho à direita seja Vermelho e o filho à esquerda seja Negro
    if (checarVerm(raiz->dir) && !checarVerm(raiz->esq)) {

        //girar a árvore para a esquerda, no entanto, a raíz ficará vermelha e o filho à esquerda continuará Negro (por isso, ainda precisamos trocar de cor)
        raiz = girarEsq(raiz);

        //agora, trocar cor do filho que deveria ser Vermelho com a raiz que deveria ser Negra (pois ficou Vermelha durante a rotacao), assim, também evitaremos que algum novo nó seja Negro
        trocarCor(raiz, raiz->esq);
    }

    //quando há uma sequencia de um filho à esquerda e o filho desse filho à esquerda Vermelhos, isto é, o primeiro filho possui duas arestas vermelhas
    if (checarVerm(raiz->esq) && checarVerm(raiz->esq->esq)) {

        //girar a árvore para a direita, no entanto, a raiz ficará vermelha (por isso, ainda precisamos trocar de cor)
        raiz = girarDir(raiz);
        trocarCor(raiz, raiz->dir);
    }

    //quando o filho à esquerda e à direita são Vermelhos (acontece usualmente na interacao anterior)
    if (checarVerm(raiz->esq) && checarVerm(raiz->dir)) {

        //Inverte-se a cor da raíz
        raiz->cor = !raiz->cor;

        //mudar a cor dos seus filhos para Negro
        raiz->esq->cor = 0;
        raiz->dir->cor = 0;
    }
    return raiz;
}

/*IMPLEMENTACAO DAS IMPRESSÕES DE MANEIRA RECURSIVA*/
void preOrdem(no *raiz) {
    if(raiz != NULL){ //não imprimir se o no atual for nulo

        //assim que está no nó, já faz o print
        printf("%d ", raiz->info);

        //passa por todos os nós à esquerda antes de chamar raiz->dir
        preOrdem(raiz->esq);

        //chamada recursiva para nó à direita 
        preOrdem(raiz->dir);
    }
}

void emOrdem(no *raiz) {
    if(raiz != NULL){ //mesmo teste

        //varrer todos à esquerda
        emOrdem(raiz->esq);

        //ao chegar no último à esq, ou seja, quando raiz->esq for NULL, ele começa a imprimir, e vai imprimindo todos os nós por onde ele passou
        printf("%d ", raiz->info);

        //é chamado o nó raiz->dir, seguindo o fluxo
        emOrdem(raiz->dir);
    }
}

void posOrdem(no *raiz) { //mesmo teste
    if(raiz != NULL) {

        //varre a árvore inteira
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);

        //para imprimir tudo de uma vez 
        printf("%d ", raiz->info);
    }
}

/*IMPLEMENTACAO RECURSIVA DE PREDECESSOR E SUCESSOR*/
no * busca(no *raiz, elem x) {

    //não existe
	if(raiz == NULL) return NULL;

    //achou
	else if(raiz->info == x) return raiz; 

    //se o valor do nó enviado(raíz) é menor que o x(valor do nó desejado), o nó desejado estará à direita, e precisaremos chamar a funcao recursivamente até que cheguemos à este.
	else if(raiz->info < x) return busca(raiz->dir,x);

    //caso contrário, à esquerda
	else return busca(raiz->esq,x); 
}

//os predecessores sempre estarão à primeira esquerda do nó caso a Árvore esteja descrita em-ordem, pois será o maior valor menor que o atual
no *buscaPredecessor(no *raiz, elem x) {

	//fazendo a busca por x dentro da árvore
	no * atual = busca(raiz, x); //no atual pra percorrer a árvore

    //caso o nó desejado não seja encontrado
	if(atual == NULL) return NULL;

    //caso haja filhos à esquerda
	if(atual->esq != NULL) {

        //percorrer até o ultimo filho à direita a partir do filho encontrado à esquerda  
		return max(atual->esq);
	}

    //caso não haja mais filhos à esquerda, procurar nos ancestrais
	else { 
		no * pre = NULL; //nó auxiliar
		no * parente = raiz; //comecando pela raiz

        //a partir das propriedades desse tipo de árvore, todos valores à esquerda são menores  e todos valores à direita são maiores (se comparados ao atual)
		while(parente != atual) {

            //o nó atual está à direita do nó parente, então o parente ancestral pode ser o predecessor
			if(atual->info > parente->info) {

                //ir pegando os valores do parente antes de ir mais à direita
				pre = parente;

                //tentar ir mais à direita ainda
				parente = parente->dir;
			}

            //se o atual for menor, buscar parentes à esquerda para conseguir o menor dentre os maiores
			else {
                //portanto, é so percorrer à esquerda
				parente = parente->esq;
            }
		}
		return pre;
	}
}

//os sucessores sempre estarão à primeira direita do nó caso a Árvore esteja descrita em-ordem, pois será o menor valor maior que o atual
no *buscaSucessor(no *raiz, elem x) {

	//fazendo a busca por x dentro da árvore
	no * atual = busca(raiz, x); //no atual para percorrer a árvore

    //caso o nó desejado não seja encontrado
	if(atual == NULL) return NULL;

    //caso haja filhos à direita 
	if(atual->dir != NULL) {

        //percorrer até o ultimo filho à esquerda a partir do filho encontrado à direita
		return min(atual->dir);
	}

    //caso não haja mais filhos à direita, procurar nos ancestrais
	else { 
		no * suc = NULL; //nó auxiliar
		no * parente = raiz; //comecando pela raiz
       
        //abusando da mesma propriedade
		while(parente != atual) { 

            //o nó atual está à esquerda do nó parente, então o parente ancestral pode ser o sucessor
			if(atual->info < parente->info) {

                //ir pegando os valores do parente antes de ir mais à esquerda
				suc = parente;

                //tentar ir mais à esquerda ainda
				parente = parente->esq; 
			}

            //se o atual for maior, buscar parentes à direita para conseguir o maior dentre os menores
			else{
                //portanto, é so percorrer à direita
				parente = parente->dir;
            }
		}
		return suc;
	}
}

//implementacao recursiva, o valor máximo será a folha localizada á máxima esquerda
no *min(no* raiz) {
    if (raiz != NULL) {

        //quando não houver mais nenhum valor à esquerda de atual, significa que chegamos no menor
        if(raiz->esq == NULL) return raiz;

        //chamando min para pegar os valores à esquerda do atual
        else return min(raiz->esq); 
    }

    //se o atual for nulo, ja se encerra a funcao retornando nulo (caso base)
    else return NULL; 
}


//implementacao recursiva, o valor máximo será a folha localizada á máxima direita
no *max(no* raiz) {
    if (raiz != NULL) {

        //quando não houver mais nenhum valor à direita de atual, significa que chegamos no maior
        if(raiz->dir == NULL) return raiz;

        //chamando max para pegar os valores à direita do atual
        else return max(raiz->dir);
    }

    //se o atual for nulo, ja se encerra a funcao retornando nulo (caso base)
    else return NULL; 
}

/*IMPLEMENTACAO DA LIBERACAO DA MEMÓRIA DE FORMA RECURSIVA*/
void destruirArvore(no *raiz) {
    //garantir que não reste nada na árvore (e ir destruindo nó por nó, comecando pela raiz)
    if(raiz != NULL){ 
        destruirArvore(raiz->esq);
        destruirArvore(raiz->dir);
        free(raiz);
    }
}
