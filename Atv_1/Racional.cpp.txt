#include <stdio.h>
#include "Racional.h"

tRacionais CriaRacional(int x, int y)
{
	tRacionais r;
	r.Numerador = x;
	r.Denominador = y;
	if (y == 0){
		printf("Numero invalido\n");
	}

	return r;
}

tRacionais MultiplicaRacional (tRacionais r1, tRacionais r2)
{
	tRacionais r;
	r.Numerador = r1.Numerador * r2.Numerador;
	r.Denominador = r1.Denominador * r2.Denominador;
	return r;
}

tRacionais DivideRacional (tRacionais r1, tRacionais r2)
{
	tRacionais r;
	r.Numerador = r1.Numerador * r2.Denominador;
	r.Denominador = r1.Denominador * r2.Numerador;
	return r;
}

tRacionais SomaRacional (tRacionais r1, tRacionais r2)
{
	tRacionais r;
	r.Numerador = (r1.Numerador * r2.Denominador) + (r2.Numerador * r1.Denominador);
	r.Denominador = (r1.Denominador * r2.Denominador);
	return r;
}

tRacionais SubtraiRacional (tRacionais r1, tRacionais r2)
{
	tRacionais r;
	r.Numerador = (r1.Numerador * r2.Denominador) - (r2.Numerador * r1.Denominador);
	r.Denominador = (r1.Denominador * r2.Denominador);
	return r;
}

void ExibeRacional(tRacionais r)
{
	printf("%d / %d", r.Numerador, r.Denominador);
}