#include <stdio.h>
#include <stdlib.h>
#include "FilaEncadeada.h"

int main()
{
    tFila *filateste = NULL;

    CriaFila(&filateste);

    AcrescentaElemento(&filateste, 1);
    AcrescentaElemento(&filateste, 2);
    AcrescentaElemento(&filateste, 3);
    AcrescentaElemento(&filateste, 4);

    /*Exibe a lista antes de remover */
    ExibeLista(filateste);
    printf("Elemento da frente: %d", ElementoFrente(filateste));
    puts("\n");

    RetiraElemento(&filateste);

    /*exibe a lista depos de remover */
    ExibeLista(filateste);
    printf("Elemento da frente: %d", ElementoFrente(filateste));

}
