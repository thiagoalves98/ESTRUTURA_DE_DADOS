#ifndef _Racional_h_
#define _Racional_h_

typedef struct {

    int Numerador;
    int Denominador;

} tRacionais;

extern tRacionais CriaRacional(int x, int y);
extern tRacionais SomaRacional(tRacionais r1, tRacionais r2);
extern tRacionais SubtraiRacional(tRacionais r1, tRacionais r2);
extern tRacionais MultiplicaRacional(tRacionais r1, tRacionais r2);
extern tRacionais DivideRacional(tRacionais r1, tRacionais r2);
extern void ExibeRacional(tRacionais r);

#endif