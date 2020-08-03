#ifndef LISTAINT_H_INCLUDED
#define LISTAINT_H_INCLUDED

typedef int tElemento;

typedef struct no{
    tElemento e;
    struct no *prox;
} tNo;

/* operacoes basicas */
extern tNo * getNo(tElemento v);
extern void deleteNo(tNo * no);

/* operacoes essenciais */
extern void IniciaLista(tNo **lista);
extern int Comprimento(const tNo *lista);
extern tElemento ObtemElemento(const tNo *lista, int indice);
extern int InsereElemento(tNo **lista, tElemento item, int indice);
extern tElemento RemoveElemento(tNo **lista, int indice);

/* operacoes adicionais */
extern int EstaVazia(const tNo *lista);
extern int AcrescentaElemento(tNo **lista, tElemento elemento);
extern int BuscaElemento(const tNo *lista, tElemento elemento);
extern void ExibeLista(const tNo *lista);
extern int CalculaMedia(const tNo *lista);
extern int InsereEmOrdem(tNo **lista, tElemento elemento);

#endif // LISTAINT_H_INCLUDED
