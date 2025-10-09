#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    char valor;
    struct Celula *proximo;
    struct Celula *anterior;
}Celula;

typedef struct{
    int qtde;
    struct Celula *topo;
}Pilha;

void imprimir(Pilha *pilha){
    printf("[ ");
    Celula *atual = pilha->topo;
    while(atual != NULL){
        printf("%c ", atual->valor);
        atual = atual->anterior;
    }
    printf("] \nqtde: %d\n", pilha->qtde);
}

void inserir(Pilha *pilha, char valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->valor = valor;
    nova->anterior = NULL;
    nova->proximo = NULL;
    if(pilha->qtde > 0){
        nova->anterior = pilha->topo;
        pilha->topo->proximo = nova;
    }

    pilha->topo = nova;
    pilha->qtde++;
}

char remover(Pilha *pilha){
    char valor;
    if(pilha->qtde > 1){
        valor = pilha->topo->valor;
        pilha->topo = pilha->topo->anterior;
        free(pilha->topo->proximo);
        pilha->topo->proximo = NULL;
    } else if(pilha->qtde ==1){
        valor = pilha->topo->valor;
        free(pilha->topo);
        pilha->topo = NULL;
    } else {
        return -1;
    }
    pilha->qtde--;
    return valor;
}

int main(){
    printf("Pilha dinamica\n");
    Pilha *pilha = malloc(sizeof(pilha));
    pilha ->qtde = 0;
    pilha->topo = NULL;
    inserir(pilha, 'c');
    inserir(pilha, 'c');
   // inserir(pilha, 'c');
   // inserir(pilha, 'c');
    remover(pilha);
    imprimir(pilha);

    return 0;

}