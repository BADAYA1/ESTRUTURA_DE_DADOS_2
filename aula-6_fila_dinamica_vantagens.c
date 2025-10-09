/*#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    int valor;
    struct Celula *proximo;
    struct Celula *anterior;
}Celula;

typedef struct{
    int qtde;
    struct Celula *head;
    struct Celula *tail;
}Fila;

void imprimir(Fila *fila){
    printf("[ ");
    Celula *atual = fila->head;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("] qtde: %d\n", fila->qtde);  
}

Fila *inicializa_lista(){
	Fila *lista = malloc(sizeof(Fila));
	lista->head=NULL;
    lista->tail=NULL;    
	lista->qtde = 0;
	return lista;
}

int main(){
    printf("Fila dinamica \n");

    imprimir(fila);
    return 0;    
}*/