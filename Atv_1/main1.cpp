#include <stdio.h>
#include "Complexo.h"

int main(void){

	tComplexo a,b,c;

	a = CriaComplexo(4, 3);
	b = CriaComplexo(8, 6);

	c = SomaComplexos(a, b);
	puts("Soma:");
	ExibeComplexo(c);
    puts("");
	c = SubtraiComplexos(a, b);
	puts("Subtracao:");
	ExibeComplexo(c);
    puts("");
	c = MultiplicaComplexos(a, b);
	puts("Multiplicacao:");
	ExibeComplexo(c);
    puts("");
	c = DivideComplexos(a, b);
	puts("Divisao:");
	ExibeComplexo(c);
    puts("");

	return 0;
}