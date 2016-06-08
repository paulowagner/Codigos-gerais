#include <stdio.h>
/*
int busbin(int vet[],unsigned n,long elem);
int pos;
int buscalin(int vet[],unsigned n,long elem);
void mostra(int vet[],unsigned n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", vet[i]);
	}
	printf("\n");
}
*/
int main(int argc, char const *argv[])
{
	int c = -4;
	unsigned e =(unsigned)c;
	printf("%u\n", c);
	c = e;
	printf("%d\n",c );
/*
	int vet[9]= {0,3,3,3,3,3,3,5,5};	
	mostra(vet,9);
	printf("%x\n",buscalin(vet,9,3) );
	printf("%x\n",busbin(vet,9,3) );
	/*if (buscalin(vet,10,3)==busbin(vet,10,3))
	{
		printf("Iguais\n");
	}else
		printf("Diferentes\n");
	printf("%d\n",pos );*/

	return 0;
}