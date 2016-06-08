#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float letraj(float base,float expoente); //Letra J
int floatint(float a);
int main(int argc, char const *argv[])
{
	float a;
	scanf("%f",&a);
	printf("%x\n", floatint(a));
    printf("%lf\n",pow(2.34,5.67) );
	printf("%f\n", letraj(2.34,0)); //124
	printf("%lf\n",pow(-2.34,5.67) );
	printf("%f\n", letraj(-2.34,0)); //124
	printf("%lf\n",pow(2.34,-5.67) );
	printf("%f\n", letraj(2.34,0)); //124
	printf("%lf\n",pow(-2.34,-5.67) );
	printf("%f\n", letraj(-2.34,0)); //124
	return 0;
}

//6,95
//110,1 1110 1000 1001 1010 0111
