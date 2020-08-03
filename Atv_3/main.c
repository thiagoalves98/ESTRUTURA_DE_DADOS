#include <stdio.h>
#include <stdlib.h>
#include "listaInt.h"

int main()
{
    tNo *minhaLista = NULL;

    IniciaLista(&minhaLista);

    printf("Comprimento inicial: %d\n", Comprimento(minhaLista));

    InsereEmOrdem(&minhaLista, 5);
    AcrescentaElemento(&minhaLista, 10);
    AcrescentaElemento(&minhaLista, 11);
    AcrescentaElemento(&minhaLista, 30);
    ExibeLista(minhaLista);
    InsereEmOrdem(&minhaLista, 20);
    ExibeLista(minhaLista);



    return 0;
}
