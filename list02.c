#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846
float detorad(float num); //Letra A
double poli(void *base,double x,int grau); //Letra B
void bask(void *base); //Letra C
double mediapon(void *base,void *peso,int tam); //Letra D
float mediage(void *base,int tam); //Letra E
double mediahar(void *base,int tam); //Letra F 
float powbfei(float base,int expoente); //Letra G
double powbdei(double base,int expoente); //Letra H 
double powbdeis(double base,int expoente); //Letra I
float letraj(float base,float expoente); //Letra J

int main(int argc, char const *argv[])
{

	char a = 'A';
	printf("%c\n",a);
	a++;
	printf("%fPI\n",detorad(180)/M_PI );
	int i=2,n=2;
	
	float vet[15];
	double vetd[15],pesos[3];
	vetd[0]=7;
	vetd[1]=0;
	vetd[2]=2;
	vetd[3]=3;
	printf("\n%c\n",a);
	a++;
	printf("%lf\n",poli(vetd,4.5,3) );
	vet[0]=1;
	vet[1]=3;
	vet[2]=-4;
	bask(vet);
	printf("\n%c\n",a);
	a++;
	printf("%f %f\n",vet[0],vet[1]);
	vetd[0]=465;
	vetd[1]=930;
	vetd[2]=1395;
	pesos[0]=20;
	pesos[1]=15;
	pesos[2]=5;
	printf("\n%c\n",a);
	a++;
	printf("%lf\n",mediapon(vetd,pesos,3) );
	printf("\n%c\n",a);
	a++;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%f",&vet[i]);
	printf("%f\n",mediage(vet,n));
	vetd[0]=1;
	vetd[1]=2;
	vetd[2]=4;
	printf("\n%c\n",a);
	a++;
	printf("%lf\n",mediahar(vetd,3) );
	printf("\n%c\n",a);
	a++;
	for (i = 0; i < 4; ++i)
		printf("%f %d\n",powbdeis(2.5,i),i );
	printf("\n%c\n",a);
	a++;
	for (i = 0; i < 4; ++i)
		printf("%lf %d\n",powbdeis(2.5,i),i );
	printf("\n%c\n",a);
	a++;
	for (i = 0; i < 4; ++i)
		printf("%f %d\n",powbdeis(2.5,-i),-i );
	printf("\n%c\n",a);
	a++;
	printf("%f\n", letraj(-2.34,-5.67)); //124
	return 0;
}