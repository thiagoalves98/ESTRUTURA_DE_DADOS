#include "Estrutura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tElementos *getElementos(char *nom){
    tElementos * n;
    n = malloc(sizeof(tElementos));
    if (n != NULL){
        strcpy(n->nome, nom);
        n->comp = NULL;
        n->prox = NULL;
    }
    return n;
}

tComponente *getComponente(char *caract, int quant, char *local){
    tComponente * n;
    n = malloc(sizeof(tComponente));

    if (n != NULL){

        strcpy(n->desc.caracteristica, caract);
        n->desc.quantidade = quant;
        strcpy(n->desc.localizacao, local);
        n->prox = NULL;
    }
    return n;
}

void IniciaElementos(tElementos **lista){
    *lista = NULL;
}

void IniciaComponente(tComponente **lista){
    *lista = NULL;
}

int CadastraElementos(tElementos **lista, char *nome){
    const tElementos *aux = *lista;

    while(aux != NULL){
        if(strcmp(aux->nome, nome) == 0){ //VERIFICA SE O ELEMENTO JA EXISTE
            return 0;
        }
        aux = aux->prox;
    }

    tElementos *novo = getElementos(nome);

    if (novo == NULL){
        printf("Memoria Cheia\n");
        return 1;
    }

    if(*lista == NULL){ //INSERE O NOVO ELEMENTO NO INICIO DA LISTA DE ELEMENTOS
        *lista = novo;
        return 0;
    }

    tElementos * no = *lista;

    while(no->prox != NULL){ //PERCORRE ATE O ELEMENTO-1 DA LISTA
        no = no->prox;
    }
    no->prox = novo;
    return 0;
}

int CadastraComponentes(tElementos **lista, char *nome, char *caract, int quant, char *local){
    const tElementos *aux2 = *lista;

    while(aux2 != NULL){
        if(strcmp(aux2->nome, nome) == 0){ //VERIFICA SE O ELEMENTO JA EXISTE
            break;
        }
        if(aux2->prox ==NULL){
            puts("Tipo de componente nao cadastrado");
            return -1;
        }
        aux2 = aux2->prox;
    }

    tElementos *no = *lista;

    while(strcmp(no->nome, nome) != 0){ //PROCURAR O NO EM QUE O COMPONENTE VAI SER INSERIDO
        if(no == NULL){
            return -1;
        }
        no = no->prox;
    }

    tComponente *novo = getComponente(caract, quant, local); //ALOCA ESPACO PARA O NOVO COMPONENTE

    if(novo == NULL){
            printf("Memoria Cheia\n");
            return 1;
    }

    if(no->comp == NULL){ //INSERE O NOVO COMPONENTE NO INICIO DA LISTA DE COMPONENTES QUE ESTA DENTRO DO NO ELEMENTO
        no->comp = novo;
        return 0;
    }

    tComponente *aux = no->comp;

    if(!strcmp(aux->desc.caracteristica,caract)){
            aux->desc.quantidade = aux->desc.quantidade + quant;
            return 0;
        }

    while(aux->prox != NULL){
        if(!strcmp(aux->desc.caracteristica,caract)){
            aux->desc.quantidade = aux->desc.quantidade + quant;
            break;
        }
        aux = aux->prox;
    }

    aux->prox = novo; //INSERE O NOVO COMPONENTE NO FINAL DA LISTA DE COMPONENTES
    return 0;
}

void ExibeElementos(const tElementos *elemento){
    const tElementos *e = elemento;
    int i = 0;
    while(e != NULL){
        printf("[%d] - %s\n", i, e->nome);
        e = e->prox;
        i++;
    }
}

void ExibeComponentes(const tElementos *elemento, char *nome){
    const tElementos *aux = elemento;
    int i = 0;

    while(strcmp(aux->nome, nome) != 0){
        if(aux == NULL){
            return -1;
        }
        aux = aux->prox;
    }

    tComponente *no = aux->comp;

    while(no != NULL){
        if(i == 0){
            printf("%s\n", aux->nome);
        }
        printf("[%d] - |Caractetistica: %s |Quantidade: %i |Localizacao: %s|\n\n", i, no->desc.caracteristica, no->desc.quantidade, no->desc.localizacao);
        no = no->prox;
        i++;
    }
}

int SolicitaComponente(tElementos **lista, char *nome, char *caract, int quant){
    const tElementos *aux2 = *lista;

    while(aux2 != NULL){
        if(strcmp(aux2->nome, nome) == 0){ //VERIFICA SE O ELEMENTO JA EXISTE
            break;
        }
        if(aux2->prox ==NULL){
            puts("Tipo de componente nao cadastrado");
            return -1;
        }
        aux2 = aux2->prox;
    }

    tElementos *no = *lista;

    while(strcmp(no->nome, nome) != 0){ //PROCURAR O NO EM QUE O COMPONENTE VAI SER REMOVIDO
        if(no == NULL){
            return -1;
        }
        no = no->prox;
    }

    tComponente *aux = no->comp;

    if(!strcmp(aux->desc.caracteristica,caract)){
            (aux)->desc.quantidade = aux->desc.quantidade - quant;
            return 0;
        }

    while(aux->prox != NULL){
        if(!strcmp(aux->desc.caracteristica,caract)){
            (aux)->desc.quantidade = aux->desc.quantidade - quant;
            break;
        }
        aux = aux->prox;
    }

    return 0;
}
