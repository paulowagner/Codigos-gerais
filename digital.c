#include <stdio.h>
#include <string.h>
#define b(i)  resp[i]&1
#define c(i)  n1[i]&1
#define d(i)  n2[i]&1
#define a(i)  aux&1
char op;
void covertebin(int *num,int a)
{
	int i;
	for (i = 31; i >=0; --i)
	{
		num[i]=a&1;
		a>>=1;
	}
}
int coverteint(int *num)
{
	int resp=0,i;
	for (i = 0; i < 32; ++i)
	{
		resp|=(num[i]&1);
		if(i!=31)
			resp<<=1;
	}
	return resp;
}

void subtracao(int a,int b,int *resp)
{
	int i,carry,y,aux,carr[32];
	int n1[32],n2[32];
	covertebin(n1,a);
	covertebin(n2,b);
	memset(resp,0,4*32);
	for (i = 31; i >= 0; --i)
	{	
		carr[i]=resp[i];
		aux = resp[i];
		resp[i]= c(i)^d(i);          
		if (!c(i)&&d(i))
		{
			for (y = i-1; y >= 0; y--)
			{
				if (!c(y))
					n1[y]=1;
				else{
					n1[y]=0;
					break;
				}
			}
			if (y<0)
				carry=1;
		}
	}
	if (op=='-')
	{
		printf("\nNumero 1:\n");
		for (i = 0; i < 32; ++i)
		{
			printf("%d",n1[i]);
		}
		printf("\nNumero 2:\n");
		for (i = 0; i < 32; ++i)
		{
			printf("%d",n2[i]);
		}
		printf("\nResposta:\n");
		for (i = 0; i < 32; ++i)
		{
			printf("%d",resp[i]);
		}
		printf("\n");
		printf("A resposta é %d e o carry é %d\n",coverteint(resp),carry);
	}

}



void soma(int a,int b,int *resp)
{
	
	int i,carry,z,aux,carr[32];
	int n1[32],n2[32];
	covertebin(n1,a);
	covertebin(n2,b);
	memset(resp,0,4*32);
	for (i = 31; i >= 0; --i)
	{	
		carr[i]=resp[i];
		aux = resp[i];
		resp[i]=a(i)^c(i)^d(i);
		if(i>0)
			resp[i-1]= ((a(i))&(c(i)^d(i)))|(c(i)&d(i));
		else
			carry = ((a(i))&(c(i)^d(i)))|(c(i)&d(i));
	}
	if (op=='+')
	{
		
		printf("Carry:\n");
		for (i = 0; i < 32; ++i)
		{
			printf("%d",carr[i]);
		}
		printf("\nNumero 1:\n");
		for (i = 0; i < 32; ++i)
		{
			printf("%d",n1[i]);
		}
		printf("\nNumero 2:\n");
		for (i = 0; i < 32; ++i)
		{
			printf("%d",n2[i]);
		}
		printf("\nResposta:\n");
		for (i = 0; i < 32; ++i)
		{
			printf("%d",resp[i]);
		}
		printf("\n");
		printf("A resposta é %d e o carry é %d\n",coverteint(resp),carry);
	}
	
}

void desloca(int *num)
{
	int i;
	for (i = 0; i < 31; ++i)
	{
		num[i]=num[i+1];
	}
	num[i]=0;
}
void multiplicacao(int a,int b,int *resp)
{
	int i,carry=0,y,aux,carr[32];
	int n1[32],n2[32];
	covertebin(n1,a);
	covertebin(n2,b);
	memset(resp,0,4*32);
	for (i = 31; i >= 0; --i)
	{	
		if(d(i)^(carry&1))  // ALGORITMO BOOTH
		{
			if (d(i))
				subtracao(coverteint(resp),coverteint(n1),resp);
			else
				soma(coverteint(resp),coverteint(n1),resp);
		}

		desloca(n1);
		if(i>0)
			carry=d(i);
	}
	if(op=='*')
		printf("A resposta é %d\n",coverteint(resp) );

}
void divisao(int a,int b)
{
	int i,carry=0,sinal=0;
	int n1[32],n2[32],resp[32];
	memset(resp,0,4*32);
	covertebin(n1,a);
	if (n1[0]==1)
	{
		multiplicacao(coverteint(n1),-1,n1);
		sinal=1;
	}
	covertebin(n2,b);
	if (n2[0]==1)
	{
		multiplicacao(coverteint(n2),-1,n2);
		sinal=sinal^1;
	}
	printf("%d %d\n",coverteint(n1),coverteint(n2) );
	while(coverteint(n1)>=coverteint(n2)){
		subtracao(coverteint(n1),coverteint(n2),n1);
		soma(coverteint(resp),1,resp);
	}
	if (sinal)
	{
		multiplicacao(coverteint(resp),-1,resp);
		covertebin(n2,a);desloca(n1);
		if(n2[0])
			multiplicacao(coverteint(n1),-1,n1);
	}
	printf("A reposta é %d e o resto é %d\n",coverteint(resp),coverteint(n1));
}

void calculadora(int a, int b){
	int resp[32];
	if (op=='+')
		soma(a,b,resp);
	else if (op=='-')
		subtracao(a,b,resp);
	else if (op=='*')
		multiplicacao(a,b,resp);
	else if (op=='/')
		divisao(a,b);
	else 
		printf("Operador invalido\n");
}

int main(int argc, char const *argv[])
{
	int a,b;
	char operador;
	printf("Digite os operandos e o operador(* / + -):\n Ex.: 2 3 +\n");
	scanf("%d %d %c",&a,&b,&operador);
	op= operador;
	calculadora(a,b);
	return 0;
}

