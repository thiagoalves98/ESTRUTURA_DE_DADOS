#ifndef _Complexo_h_
#define _Complexo_h_


typedef struct {
		double pReal;
		double pImaginaria;
	} tComplexo;


extern tComplexo CriaComplexo(double x, double y);
extern tComplexo SomaComplexos(tComplexo c1, tComplexo c2);
extern tComplexo SubtraiComplexos(tComplexo c1, tComplexo c2);
extern tComplexo MultiplicaComplexos(tComplexo c1, tComplexo c2);
extern tComplexo DivideComplexos(tComplexo c1, tComplexo c2);
extern void ExibeComplexo(tComplexo c);

#endif