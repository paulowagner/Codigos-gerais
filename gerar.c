#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <string.h>


 int main(int argc, char const *argv[])
 {
 	int i,vet[54],M,N,y,z,j;
 	for ( i = 0; i < 20; ++i)
 	{
 		memset(vet,0,54*sizeof(int));
 		M = rand() % 5;
 		M+=2;
 		N = 54/M;
 		N = rand() % N;
 		N++;
 		printf("%d %d\n",N,M);
 		for (z = 0; z < M; ++z)
		{
			j = rand() % (N+1);
			if (z!=M-1)
			{
				printf("%2d ",j);
			}else{
				printf("%2d\n",j);
			}
		}
 		for (y = 0; y < N; ++y)
 		{
 			for (z = 0; z < M; ++z)
 			{
 				do{
 					j = rand() % 54;
 				}while(vet[j]);
 				vet[j]=1;
 				if (z!=M-1)
 				{
 					if (j==52||j==53)
 					{
 						printf("14 ");
 					}else{
 						printf("%2d ",(j%13)+1);
 					}
 				}else{
 					if (j==52||j==53)
 					{
 						printf("14\n");
 					}else{
 						printf("%2d\n",(j%13)+1);
 					}
 				}
 			}
 		}
 	}
 	printf("0 0\n");
 	return 0;
 }