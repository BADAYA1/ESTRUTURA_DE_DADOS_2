#include <stdio.h>
#include <stdlib.h>


typedef struct Celula{
    int valor;
    struct Celula *proximo;
}Celula;

typedef struct{
    int quantidade;
    Celula *primeira;
}Lista;

Lista *inicializa(){
    Lista *lista = malloc(sizeof(Lista));
    lista -> quantidade = 0;
    lista -> primeira = NULL;
    return lista;
}

void imprimir(Lista *lista){
    printf("\n[");
    Celula *atual = lista->primeira;
    while(atual != NULL){
        printf("%d (●´∀｀●)\n", atual->valor);
        atual = atual->proximo;//༼ つ ◕_◕ ༽つ
    }
    printf("] -> quantidade: %d\n", lista->quantidade);
}

void inserir(Lista *lista, int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->valor = valor;
    nova->proximo = NULL;

    Celula *atual = lista->primeira;
    Celula *anterior = NULL;

    while(atual != NULL && atual->valor < valor){
        anterior = atual;
        atual = atual->proximo;
    }

    if(atual == NULL && anterior == NULL){
        lista->primeira = nova;
        lista->quantidade++;        
    }
    if(atual == NULL && anterior != NULL){
        anterior->proximo = nova;
        lista->quantidade++;
    }
}

int main(){
    Lista *lista = inicializa();
    printf("Lista dinamica encadeada");
    inserir(lista, 3);
    inserir(lista, 5);
    inserir(lista, 9);
    inserir(lista, 67);
    inserir(lista, 200);
    inserir(lista, 650);
    imprimir(lista);

    
    return 0;
}