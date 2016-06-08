#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fabrica.h"


double convGrausRad (double x) {
	return x * M_PI / 180;
}
int fatorial (int n)
{
    if(n==0) 
        return 1;
    return fatorial(n-1) * n;          
}
int teste(int a,int b,int c)
{
	return a+b+c;
}
int fatorialDoMaiorDos10(int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8,int n9,int n10){
	int maior = n1;
	if(n2 > maior) maior = n2;
	if(n3 > maior) maior = n3;
	if(n4 > maior) maior = n4;
	if(n5 > maior) maior = n5;
	if(n6 > maior) maior = n6;
	if(n7 > maior) maior = n7;
	if(n8 > maior) maior = n8;
	if(n9 > maior) maior = n9;
	if(n10 > maior) maior = n10;
	if(maior == 0) return 1;
	else return maior*fatorialDoMaiorDos10(maior-1,0,0,0,0,0,0,0,0,0);
}
int somadois(int a,int b){
	return a+b;
}
char toup(char c)
{
	return toupper(c);
}

typedef int (*trint) (int , int , int);
typedef int (*vints) (int , int , int , int , int , int , int , int , int , int);
typedef int (*vints15) (int , int , int , int , int , int , int , int , int , int,int , int , int , int , int);
typedef char (*testechar) (char);
typedef int (*fptr) (int , int , int , int , int );
typedef void* (*mem)(void*,int);
typedef double (*dfptr) (double);

int main () {
	Parametro params[15];
	params[0].amarracao = LIVRE;
	params[0].tipo = INT;
	params[1].amarracao = LIVRE;
	params[1].tipo = INT;
	params[1].valor.vDouble = 2;
	params[2].amarracao = LIVRE;
	params[2].tipo = INT;
	params[2].valor.vDouble = 2;
	params[3].amarracao = LIVRE;
	params[3].tipo = INT;
	params[3].valor.vDouble = 2;	
	params[4].amarracao = FUNCAO;
	params[4].tipo = INT;	
	params[5].amarracao = LIVRE;
	params[5].tipo = INT;
	params[5].valor.vDouble = 2;	
	trint quadrado = (trint)	create(teste, INT,3,params	);
	printf("O valor de 5 elevado ao quadrado é %d \n",quadrado(5,6,7) );
	params[4].valor.vPointer = quadrado	;
	fptr fat = (fptr) create(teste,INT,3,&params[3]);
	printf("%d\n",fat(1,2,3,4,5));
	//destroy(quadrado,0);
	params[0].amarracao = LIVRE;
	params[0].tipo = CHAR;
	testechar ch = (testechar)create(toup,CHAR,1,params);
	printf("%c\n",ch('a') );
	params[0].amarracao = LIVRE;
	params[0].tipo = POINTER;
	params[1].amarracao = CONSTANTE;
	params[1].tipo = CHAR;
	params[1].valor.vChar = 0x7f;
	params[2].amarracao = LIVRE;
	params[2].tipo = INT;
	mem teee = (mem)create(memset,POINTER,3,params);
	int i,vet[10],n=10;
	for(i=0;i<n;i++)
		scanf("%d",&vet[i]);
	for(i=0;i<n;i++)
		printf("%2d ",vet[i]);
	printf("\n");
	teee(vet,10*sizeof(int));
	for(i=0;i<n;i++)
		printf("%x ",vet[i]);
	printf("\n");
	params[0].amarracao = LIVRE;
	params[0].tipo = INT;
	params[1].amarracao = LIVRE;
	params[1].tipo = INT;
	params[2].amarracao = LIVRE;
	params[2].tipo = INT;
	params[3].amarracao = LIVRE;
	params[3].tipo = INT;
	params[4].amarracao = LIVRE;
	params[4].tipo = INT;
	params[5].amarracao = LIVRE;
	params[5].tipo = INT;
	params[6].amarracao = LIVRE;
	params[6].tipo = INT;
	params[7].amarracao = LIVRE;
	params[7].tipo = INT;
	params[8].amarracao = LIVRE;
	params[8].tipo = INT;
	params[9].amarracao = LIVRE;
	params[9].tipo = INT;
	vints fatdez = (vints)create(fatorialDoMaiorDos10,INT,10,params);
	printf("fat10: %d\n",fatdez(1,5,8,9,4,10,5,6,3,1));
	params[0].amarracao = FUNCAO;
	params[0].tipo = INT;
	params[0].valor.vPointer = fat;
	params[1].amarracao = FUNCAO;
	params[1].tipo = INT;
	params[1].valor.vPointer = fatdez;
	vints15 teste15 = (vints15)create(somadois,INT,2,params);
	printf("%d\n",teste15(1,2,3,4,5,1,5,8,9,4,10,5,6,3,1) );
	return 0;
}
