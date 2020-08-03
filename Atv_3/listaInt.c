#include "listaInt.h"
#include <stdio.h>
#include <stdlib.h>

tNo * getNo(tElemento v){
    tNo * n;
    n = malloc(sizeof(tNo));
    if (n != NULL){
        n->e = v;
        n->prox = NULL;
    }
    return n;
}

void deleteNo(tNo * no){
    free(no);
}

void IniciaLista(tNo **lista){
    *lista = NULL;
}

int Comprimento(const tNo *lista){
    int c = 0;
    const tNo * no = lista;

    while(no != NULL){
        c++;
        no = no->prox;
    }

    return c; /* Não há o que calcular */
}

tElemento ObtemElemento(const tNo *lista, int indice){
    int i;
    const tNo *no = lista;

    for(i = 0; i < indice; i++){
        if (no == NULL){
            puts("indice inexistente");
            exit(1);
        }
        no = no->prox;
    }
    return no->e;
}

int InsereElemento(tNo **lista, tElemento item, int indice){
    if (indice < 0) {
        printf("\nPosicao de insercao inexistente\n");
        return 1;
    }

    tNo * novo = getNo(item);
    if (novo == NULL){
        puts("sem memoria");
        return 1;
    }

    if (indice == 0){
        novo->prox = *lista;
        *lista = novo;
        return 0;
    }

    int i;
    tNo *no = *lista;

    for(i = 0; i < indice-1; i++){
        if (no == NULL){
            puts("indice inexistente");
            return 1;
        }
        no = no->prox; //
    }

    novo->prox = no->prox;
    no->prox = novo;

    return 0;
}

tElemento RemoveElemento(tNo **lista, int indice){
    tElemento itemRemovido;
    /* Verifica se o índice é válido */
    if (indice < 0) {
        printf("\nPosicao de remocao inexistente\n");
        exit(1);
    }

    if (indice == 0){
        tNo *deletar = *lista;
        itemRemovido = deletar->e;
        *lista = (*lista)->prox;
        free(deletar);
        return itemRemovido;
    }

    int i;
    tNo *no = *lista;

    for(i = 0; i < indice - 1; i++){
        if (no == NULL){
            puts("indice inexistente");
            exit(1);
        }
        no = no->prox;
    }

    tNo *deletar = no->prox;
    no->prox = no->prox->prox;

    itemRemovido = deletar->e;
    deleteNo(deletar);

    return itemRemovido;
}

int EstaVazia(const tNo *lista){
    return lista == NULL;
}

int AcrescentaElemento(tNo **lista, tElemento elemento){

    tNo *novo = getNo(elemento);
    if (novo == NULL){
        puts("memoria cheia");
        return 1;
    }
    if (EstaVazia(*lista)){
        *lista = novo;
        return 0;
    }

    tNo * no = *lista;
    while(no->prox != NULL){
        no = no->prox;
    }
    no->prox = novo;

    return 0;
}

int BuscaElemento(const tNo *lista, tElemento elemento){
    const tNo *no = lista;
    int c = 0;

    while (no != NULL && no->e != elemento){
        no = no->prox;
        c++;
    }

    return no != NULL ? c : -1;

}

void ExibeLista(const tNo *lista){
    const tNo *no = lista;
    int c = 0;

    while (no != NULL ){
        printf("[%d]=%d ", c, no->e);
        no = no->prox;
        c++;
    }
    puts("");

}

int CalculaMedia(const tNo *lista){

    const tNo *no = lista;
    int soma = 0, i = 0;

    while (no != NULL ){
        soma = soma + no->e;
        no = no->prox;
        i++;
    }
    return soma/i;
}

int InsereEmOrdem(tNo **lista, tElemento elemento){

    tNo *novo = getNo(elemento);
    tNo *no = *lista;

    if (novo == NULL){
        puts("memoria cheia");
        return 1;
    }
    if (no == NULL){
        novo->prox = *lista;
        *lista = novo;
    }
    while (no != NULL ){
        if(no->prox->e == NULL){
            novo->prox = no->prox;
            no->prox = novo;
            break;
        }

        if((elemento > no->e) && (elemento < no->prox->e)){
            novo->prox = no->prox;
            no->prox = novo;
            break;
        }
        no = no->prox;
     }
     return 0;
}


