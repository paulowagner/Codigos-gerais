#include <stdio.h>
#include <stdlib.h>
double hypot(double x, double y);
float media(void *vet,unsigned n);
double	area(double a,double b,double c);
union{
	float f;
	unsigned int l;
}u;

void p(){
	float pi=3.2;
}
void c(){
	#define pi 3.1413112

}
int main(int argc, char const *argv[])
{
	int i=0;
	float vet[10];
	printf("%lf\n",area(30,40,50) );
	for (i = 0; i < 10; ++i)
	{
		scanf("%f",&vet[i]);
	}
	double a,b;
	printf("%f\n",media(vet,10) );
	scanf("%lf %lf",&a,&b);
	printf("%lf\n",hypot(a,b) );
	u.f = 11.99;
	printf("%x\n",u.l);
	return 0;
}
/*
1011
127+3
130
0100 0001 0011 0111 0011 0011 0011
  4    1    3    7    3    3    3

0.45
0.9  0
1.8  1
1.6  1
1.2  1
0.4  0
0.8  0
1.6  1
1.2  1
0.4  0
0.8  0
*/