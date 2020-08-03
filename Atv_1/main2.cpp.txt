#include <stdio.h>
#include "Racional.h"

int main(void){
	tRacionais a, b, c;

	a = CriaRacional(10, 5);
	b = CriaRacional(8, 3);

	c = SomaRacional(a, b);
	puts("Soma: ");
	ExibeRacional(c);
	puts("");
	c = SubtraiRacional(a, b);
	puts("Subtracao: ");
	ExibeRacional(c);
	puts("");
	c = MultiplicaRacional(a, b);
	puts("Multiplicacao: ");
	ExibeRacional(c);
	puts("");
	c = DivideRacional(a, b);
	puts("Divisao: ");
	ExibeRacional(c);
	puts("");

	return 0;
}