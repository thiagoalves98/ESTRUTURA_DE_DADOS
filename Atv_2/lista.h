#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define MAX_ELEMENTOS 100

typedef struct {
        int nElementos;
        int elemento[MAX_ELEMENTOS];
    } tLista;

extern void IniciaLista(tLista *lista);
extern int TamanhoLista(tLista *lista);
extern int ElementoLista(tLista *lista, int indice);
extern int InsereElemento(tLista *lista, int indice, int valor);
extern int RemoveElemento(tLista *lista, int indice);
extern int EstaVazia(const tLista *lista);
extern int AcrescentaElemento(tLista *lista, int elemento);


#endif // LISTA_H_INCLUDED