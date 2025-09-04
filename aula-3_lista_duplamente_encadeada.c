#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    int valor;
    struct Celula *proximo;
    struct Celula *anterior;
}Celula;

typedef struct{
    int qtde;
    Celula *primeiro;
    Celula *ultimo;
}LDDE;


void inserir(LDDE *lista, int dado){
    Celula *nova = malloc(sizeof(Celula));
    nova->valor = dado;
    nova->proximo = NULL;
    nova->anterior = NULL;

    //ponteiros auxiliares
    Celula *atual = lista->primeiro;
    Celula *anterior = NULL;

    while(atual != NULL && atual->valor <= dado){
        anterior = atual;
        atual = atual->proximo;
    }

    if(atual == NULL && anterior == NULL){  //lista vazia
        lista->primeiro = nova;
    }
    else if(atual == NULL && anterior != NULL){ //lista cheia
        anterior->proximo = nova;
        nova->anterior = anterior;
    }
    else if (atual != NULL && anterior != NULL){//inserir no meio
        anterior->proximo = nova;
        nova->proximo = atual;
        nova->anterior = anterior;
        atual->anterior = nova;
    }
    
    Celula *ultimo = atual;

    lista->qtde++;
}

void imprimir(LDDE *lista){
    printf("[ ");
    Celula *atual = lista->primeiro;
    int i = 0;
    while(atual != NULL && i < lista->qtde){
        printf("%d ", atual->valor);
        atual = atual->proximo;
        i++;
    }
    printf("]\n");
}

void imprimirInverso(LDDE *lista){
    printf("[ ");
    Celula *atual = lista->ultimo;
    int i = 0;
    while(atual != NULL && i < lista->qtde){
        printf("%d ", atual->valor);
        atual = atual->anterior;
        i++;
    }
    printf("]\n");
}

int main(){
    LDDE *lista = malloc(sizeof(LDDE));
    lista->qtde = 0;
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    printf("Lista duplamente encadeada\n");
    inserir(lista, 1);
    inserir(lista, 2);
    inserir(lista, 3);
    inserir(lista, 5);
    inserir(lista, 7);
    //imprimir(lista);
    imprimirInverso(lista);
    return 0;
}