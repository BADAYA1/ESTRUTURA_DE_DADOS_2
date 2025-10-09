#include <stdio.h>

#define SIZE 11

typedef struct{
    char data[SIZE];
    int head;
    int tail;
    int qtde;

}Fila;

void inicializa(Fila *fila){
    fila->head = 0;
    fila->tail = 0;
    fila->qtde = 0;
}

void imprimir(Fila *fila){
    if(isEmpty(fila)){ printf("[ta tudo vazio]\n"); return -1;}
    printf("[");
    for(int i = fila->head; i != fila->tail; i = (i+1)%SIZE){
        printf("%c", fila->data[i]);
    }
    printf("]\n");
}

int isEmpty(Fila *fila){
    return fila->head == fila->tail;
}

int isFull(Fila *fila){
    return fila->head ==(fila->tail + 1) % SIZE;
}

void enfileirar(Fila *fila, char valor){
    if(isFull(fila)) return;
    fila->data[fila->tail] = valor;
    fila->tail = (fila->tail + 1) % SIZE;
    fila->qtde++;
}

char desenfileirar(Fila *fila){
    if(isEmpty(fila)){ printf("deu errado parsa"); return -1;}
    char letra = fila->data[fila->head];
    fila->head = (fila->head + 1) % SIZE;
    fila->qtde--;
    printf("sua letra :\n %cヾ(•ω•`)o\n\n", letra);
}

int main(){
    printf("fila estatica\n");
    Fila fila;
    inicializa(&fila);
    enfileirar(&fila, 'a');
    desenfileirar(&fila);
    imprimir(&fila);
    printf("\n\n\n\n\n\n\n");
    return 0;
}
