#include <stdio.h>
#include <string.h>
int mod(int i){
	if(i<0)
		return -i;
	else
		return i;
}
int main(int argc, char const *argv[])
{
	int i,vet[7],M,N,y,z,j;
 	int aux,empate,carta;
 	scanf("%d %d",&N,&M);
 	while(N!=0&&M!=0)
 	{
 		memset(vet,0,7*sizeof(int));
 		for (z = 0; z < M; ++z)
 		{
 			scanf("%d",&vet[z]);
 		}
 		for (y = 0; y < N; ++y)
 		{
 			empate = 0;
 			carta = 0;
 			for (z = 0; z < M; ++z)
 			{
 				scanf("%d",&aux);
 				if (aux>carta)
 				{
 					carta = aux;
 					empate = 0;
 					j = z;
 				}
 				else if(aux==carta){
 					empate = 1;
 				}
 			}
 			if(empate==0)
 				vet[j]--;
 		}
 		for (z = 0; z < M; ++z)
 		{
 			if(z!=(M-1))
 				printf("%d ",mod(vet[z]) );
 			else
 				printf("%d\n",mod(vet[z]) );
 		}
 		scanf("%d %d",&N,&M);
 	}
	return 0;
}