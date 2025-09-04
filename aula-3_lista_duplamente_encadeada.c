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
    lista->qtde++;

}

void imprimir(LDDE *lista){
    printf("[ ");
    Celula *atual = lista->primeiro;
    while(atual != NULL){
        printf("%d ", atual->valor);
    }


    printf("]");
    
}

int main(){
    LDDE *lista = malloc(sizeof(LDDE));
    lista->qtde = 0;
    lista->primeiro = NULL;
    printf("ÇLista duplamente encadeada");
    inserir(lista, 1);
    inserir(lista, 2);
    inserir(lista, 3);
    inserir(lista, 5);
    inserir(lista, 7);
    imprimir(lista);
    return 0;
}