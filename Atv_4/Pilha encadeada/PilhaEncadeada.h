#ifndef PILHAENCADEADA_H_INCLUDED
#define PILHAENCADEADA_H_INCLUDED

typedef int tElemento;

typedef struct{
    tElemento elemento;
    struct no *proximo;
}tPilha;

extern void CriaPilha(tPilha **pilha);
extern int PilhaVazia(const tPilha *pilha);
extern int ElementoTopo(tPilha **pilha);
extern int Empilha(tPilha **pilha, tElemento elemento);
extern int Desempilha(tPilha **pilha);

#endif // PILHAENCADEADA_H_INCLUDED
