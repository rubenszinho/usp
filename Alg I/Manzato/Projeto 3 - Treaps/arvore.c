#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arvore.h"

arvore *criarArvore() {
    arvore *a = (arvore *)malloc(sizeof(arvore));
    a->raiz = NULL;
    return a;
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

/*IMPLEMENTACAO DA INSERCAO DE MANEIRA RECURSIVA*/
no *inserir(no *raiz, elem x, elem priori) {
    if(raiz == NULL) { //criar novo no se a raiz for nula
        no *aux = (no *)malloc(sizeof(no));
        aux->info = x;
        aux->esq = NULL;
        aux->dir = NULL;
        aux->priori = priori;
        return aux;
    }
    else if(x < raiz->info) { //inserindo à esquerda chamando a recursão
        raiz->esq = inserir(raiz->esq, x, priori);

            // Cumprir uma das propriedades da HEAP (hierarquia de prioridades)
            if (raiz->esq->priori > raiz->priori) {
                raiz = girarDir(raiz);        
            }
    }
    else if(x > raiz->info){ //inserindo à direita chamando a recursão
        raiz->dir = inserir(raiz->dir, x, priori);

           // Cumprir uma das propriedades da HEAP (hierarquia de prioridades)
            if (raiz->dir->priori > raiz->priori){
                raiz = girarEsq(raiz);
            }
    }
    else{ // se raiz == x
        printf("Elemento ja existente\n");
        return raiz;
    }
    return raiz;
}

/*IMPLEMENTACAO DA REMOCAO DE MANEIRA RECURSIVA GIRANDO SOMENTE PARA A ESQUERDA*/
no *remover(no* raiz, elem x) {
    
    // caso base
    if (raiz == NULL){
        printf("Chave nao localizada\n");
        return raiz;
    }

    // se o "x" não for localizado na raíz, utilizar a propriedade das ABBs para procurar nas subárvores, menor valor à esquerda e maior à direita
    if (x < raiz->info)
        raiz->esq = remover(raiz->esq, x);

    else if (x > raiz->info)
        raiz->dir = remover(raiz->dir, x);

    else{// se o "x" for localizado
        no *aux;

        // para caso o filho à esquerda ser nulo (encontrou uma folha/semi-folha)
        if (raiz->esq == NULL) {
            // aux serve para fazer a mudanca da referencia
            aux = raiz->dir; 

            // para não haver memory leak no antigo nó correspondente da raiz e desalocá-lo antes de perder sua referencia
            free(raiz);

            // mudar a referencia para o filho (fazendo com que o nó anterior da seja excluido da árvore)
            raiz = aux;  
        }

        // para caso o filho à direita ser nulo (encontrou uma folha/semi-folha)
        else if (raiz->dir == NULL) {
            aux = raiz->esq;// mesma coisa
            free(raiz); // mesma coisa
            raiz = aux;  // mesma coisa
        }

        else {
            //rotacionar até encontrar uma folha ou semi-folha que possa ser removida
            raiz = girarEsq(raiz);
            raiz->esq = remover(raiz->esq, x);
        }
    }
    return raiz;
}

/*IMPLEMENTACAO DA BUSCA DE MANEIRA RECURSIVA*/
void *busca(no *raiz, elem x) {

    //não existe
	if(raiz == NULL) {
        printf("0\n");
        return NULL;
    }

    //achou
	else if(raiz->info == x) {
        printf("1\n");
        return raiz;
    } 

    //se o valor do nó enviado(raíz) é menor que o x(valor do nó desejado), o nó desejado estará à direita, e precisaremos chamar a funcao recursivamente até que cheguemos à este.
	else if(raiz->info < x) return busca(raiz->dir,x);

    //caso contrário, à esquerda
	else return busca(raiz->esq, x); 
}

int calcularAltura(no *raiz) {
	if(raiz == NULL || raiz->info == -1)
		return 0;

    // buscando recursivamente a altura das subárvores da esquerda e da direita
	int alt_esq = 1 + calcularAltura(raiz->esq);
	int alt_dir = 1 + calcularAltura(raiz->dir);

	if(alt_esq > alt_dir)
		return alt_esq;
	else
		return alt_dir;
}

/*IMPLEMENTACAO DAS IMPRESSÕES DE MANEIRA RECURSIVA*/
void impressaoNoNivel(no *raiz, int nivel){
    // a variavel auxiliar "nível" corresponde ao nível de cada subárvore que será percorrida, permitindo 
    //assim que imprimamos sua respectiva raíz (topo da subárvore)
    // esse "nível" nada mais é que a altura de cada nó da árvore que será calculada subsequentemente
	if(raiz == NULL) return;
	else {
		if(nivel == 0) {

            // imprimindo o valor do nó cujo nível corresponderá ao topo da subárvore
			printf("(%d, %d) ", raiz->info, raiz->priori);
		}
		else {
            // chamando recursivamente para percorrer tanto as subárvores à esquerda como à direita no sentido topo à folha da árvore
			impressaoNoNivel(raiz->esq, nivel - 1);
			impressaoNoNivel(raiz->dir, nivel - 1);
		}
	}
}

void largura(no *raiz) {
	int altura = calcularAltura(raiz);

    //seguir a impressao ate que se percorra todas a árvore (descendo nível a nível)
	for(int i = 0; i < altura; i++) {
        impressaoNoNivel(raiz, i);
	}
}

void preOrdem(no *raiz) {
    if(raiz != NULL){ //não imprimir se o a raiz for nula

        //assim que está no nó, já faz a impressao
        printf("(%d, %d) ", raiz->info, raiz->priori);

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
        printf("(%d, %d) ", raiz->info, raiz->priori);

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
        printf("(%d, %d) ", raiz->info, raiz->priori);
    }
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