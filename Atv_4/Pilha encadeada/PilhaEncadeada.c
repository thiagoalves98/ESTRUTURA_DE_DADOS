#include "PilhaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

tPilha *getNo(tElemento v){
    tPilha * n;
    n = malloc(sizeof(tPilha));
    if (n != NULL){
        n->elemento = v;
        n->proximo = NULL;
    }
    return n;
}

void deleteNo(tPilha *no){
    free(no);
}

void CriaPilha(tPilha **pilha){
    *pilha = NULL;
}

int PilhaVazia(const tPilha *pilha){
    return pilha == NULL;
}

int ElementoTopo(tPilha **pilha){
    return (int)*pilha;
}

int Empilha(tPilha **pilha, tElemento elemento){

    tPilha *novo = getNo(elemento);
    if (novo == NULL){
        puts("memoria cheia");
        return 1;
    }
    
    novo->proximo = *pilha;
    *pilha = novo;
    printf("%d\n", novo->elemento);

    return 0;
}

int Desempilha(tPilha **pilha){

    tPilha *no = *pilha;
    *pilha = no->proximo;
    deleteNo(no);
}
