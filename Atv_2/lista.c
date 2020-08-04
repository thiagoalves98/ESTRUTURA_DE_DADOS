#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void IniciaLista(tLista *lista){
    lista->nElementos = 0;
}

int TamanhoLista(tLista *lista){
    return lista->nElementos;
}

int ElementoLista(tLista *lista, int indice){
    if (indice < 0 || indice >= TamanhoLista(lista)){
        puts("indice invalido");
        exit(1);
    }
    return lista->elemento[indice];
}

int InsereElemento(tLista *lista, int indice, int valor){

    if (indice < 0 || indice > TamanhoLista(lista)){
        return 0;
    }
    if (lista->nElementos >= MAX_ELEMENTOS){
        return 0;
    }
    int i;
    for (i = lista->nElementos; i != indice; i--){
        lista->elemento[i] = lista->elemento[i-1];
    }
    lista->elemento[indice] = valor;
    lista->nElementos++;
    return 1;
}

int RemoveElemento(tLista *lista, int indice){

    if (indice < 0){
        return 0;
    }
    int posicao;
    for(posicao = indice; posicao != lista->nElementos-1 ; posicao ++){
        lista->elemento[posicao] = lista->elemento[posicao + 1];
    }
    lista->nElementos--;
}

int EstaVazia(const tLista *lista){
    if (lista->nElementos == 0){
        puts("Lista Vazia");
    }
}

int AcrescentaElemento(tLista *lista, int elemento){

    int qTotal = lista->nElementos; //armazena a quantidade total de elementos existentes na lista
    lista->elemento[qTotal] = elemento;
    lista->nElementos++;
}