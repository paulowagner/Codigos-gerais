#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fabrica.h"

double convGrausRad (double x) {
	return x * M_PI / 180;
}
double c(double x){
	return 1.0/(x*x);
}

typedef double (*fptr) (double);
typedef double (*dfptr) (double);
int main () {
	Parametro param;
	param.amarracao = LIVRE;
	param.tipo = DOUBLE;
	param.valor.vDouble = 90.0;
	
	fptr h = (fptr) create (convGrausRad, DOUBLE, 1, &param);
	printf("90 graus em radiano é %.2f \n",h(90) );
	param.amarracao = FUNCAO;
	param.valor.vPointer = h;
	fptr g = (fptr) create (sin, DOUBLE, 1, &param);
	printf ("O seno de 90 graus é %.2f.\n", g (90));
	param.amarracao = FUNCAO;
	param.valor.vPointer = g;

	fptr cossec2 = (fptr) create (c, DOUBLE, 1, &param);
	printf("%f\n",cossec2(30));
	destroy (g,0);
	return 0;
}