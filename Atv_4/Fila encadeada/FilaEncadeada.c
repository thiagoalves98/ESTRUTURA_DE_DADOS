#include "FilaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

tFila * getNo(tElemento v){
    tFila * n;
    n = malloc(sizeof(tFila));
    if (n != NULL){
        n->elemento = v;
        n->proximo = NULL;
    }
    return n;
}

void deleteNo(tFila * no){
    free(no);
}

void CriaFila(tFila **fila){
    *fila = NULL;
}

int FilaVazia(const tFila *fila){
    return fila == NULL;
}

int ElementoFrente(const tFila **fila){
    return (int)*fila;
}

int AcrescentaElemento(tFila **fila, tElemento elemento){

    tFila *novo = getNo(elemento);
    if (novo == NULL){
        puts("memoria cheia");
        return 1;
    }
    if (FilaVazia(*fila)){
        *fila = novo;
        return 0;
    }

    tFila * no = *fila;
    while(no->proximo != NULL){
        no = no->proximo;
    }
    no->proximo = novo;

    return 0;
}

int RetiraElemento(tFila **fila){
    int *i = &fila;
    *fila = (*fila)->proximo;
    deleteNo(i);
}

void ExibeLista(const tFila *fila){
    const tFila *no = fila;
    int c = 0;

    while (no != NULL ){
        printf("[%d]=%d ", c, no->elemento);
        no = no->proximo;
        c++;
    }
    puts("");
}
