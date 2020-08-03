#include <stdio.h>
#include <stdlib.h>
#include "PilhaEncadeada.h"

int main()
{
    tPilha *pilha = NULL;

    CriaPilha(&pilha);

    Empilha(&pilha, 1);
    Empilha(&pilha, 2);
    Empilha(&pilha, 3);
    Empilha(&pilha, 4);
    Empilha(&pilha, 5);
    Empilha(&pilha, 6);

    printf("Elemento topo: %d\n", ElementoTopo(pilha));
    Desempilha(&pilha);
    printf("Elemento topo: %d\n", ElementoTopo(pilha));

    Empilha(&pilha, 7);

    printf("Elemento topo: %d\n", ElementoTopo(pilha));
    Desempilha(&pilha);
    printf("Elemento topo: %d", ElementoTopo(pilha));

}
