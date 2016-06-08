#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef enum {LIVRE, CONSTANTE, FUNCAO} Amarracao;
typedef enum {VOID, CHAR, INT, FLOAT, DOUBLE, POINTER} Tipo;

typedef union
{
	char   vChar;
	int    vInt;
	float  vFloat;
	double vDouble;
	void  *vPointer;
} Valor;

typedef struct
{
	Amarracao amarracao;
	Tipo tipo;
	Valor valor;
} Parametro;

float multiplicar (float x,float y) {					
	return x * y;
}


void *create (void *f, Tipo ret, unsigned n, Parametro *params); //assinatura da funcao
typedef float (*mult) (float);


int main()
{
	float a=9;
	Parametro f1[2];
	f1[0].amarracao =  LIVRE;
	f1[0].tipo = FLOAT;
	f1[1].amarracao =  CONSTANTE;
	f1[1].tipo = FLOAT;
	f1[1].valor.vFloat = 2;

	mult mult2 = (mult)create(multiplicar,FLOAT,2,f1);
	printf("o dobro de %.2f e: %.2f\n",a, mult2(a));

	return 0;
}
