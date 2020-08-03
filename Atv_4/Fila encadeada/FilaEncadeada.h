#ifndef FILAENCADEADA_H_INCLUDED
#define FILAENCADEADA_H_INCLUDED

typedef int tElemento;

typedef struct{
    tElemento elemento;
    struct no *proximo;
}tFila;

extern void CriaFila(tFila **fila);
extern int FilaVazia(const tFila *fila);
extern int ElementoFrente(const tFila **fila);
extern int AcrescentaElemento(tFila **fila, tElemento elemento);
extern int RetiraElemento();
extern void ExibeLista(const tFila *fila);


#endif // FILAENCADEADA_H_INCLUDED
