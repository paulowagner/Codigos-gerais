#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int campo[10][10];
int campovisto[10][10];

void prenchenumeros()
{
	int i,j;
	for( i = 0 ; i < 10 ; i++ ) 
	{
		for( j = 0 ; j < 10 ; j++ )
		{
			if(campo[i][j]==-1)
				continue;
			else{
				if(i>0)
				{
					if(j>=1&&campo[i-1][j-1]==-1)
						campo[i][j]++;
					if(j<9&&campo[i-1][j+1]==-1)
						campo[i][j]++;
					if(campo[i-1][j]==-1)
						campo[i][j]++;
				}
				if(j>=1&&campo[i][j-1]==-1)
					campo[i][j]++;
				if(j<9&&campo[i][j+1]==-1)
					campo[i][j]++;
				if(i<9)
				{
					if(j>=1&&campo[i+1][j-1]==-1)
						campo[i][j]++;
					if(j<9&&campo[i+1][j+1]==-1)
						campo[i][j]++;
					if(j<9&&campo[i+1][j]==-1)
						campo[i][j]++;
				}
			}
		}
	}	
}

void preencheCampo()
{
	int i,pos;
	time_t t; 
   	srand((unsigned) time(&t));
	memset(campo,0,100*sizeof(int));
	for( i = 0 ; i < 20 ; i++ ) 
	{
		pos = rand() % 100;
		if(campo[pos/10][pos%10]==0)
			campo[pos/10][pos%10]=-1;
		else
			i--;
	}
	
}

void mudacampo(int i,int j)
{
	campovisto[i][j]=0;
	if(i>0)
	{
		if(j>0&&campovisto[i-1][j-1]!=0)
		{			
			campovisto[i-1][j-1]=0;
			if (campo[i-1][j-1]==0)
				mudacampo(i-1,j-1);
		}
		if(j<9&&campovisto[i-1][j+1]!=0)
		{
			campovisto[i-1][j+1]=0;
			if (campo[i-1][j+1]==0)
				mudacampo(i-1,j+1);
		}
		if (campovisto[i-1][j]!=0)
		{
			campovisto[i-1][j]=0;
			if (campo[i-1][j]==0)
				mudacampo(i-1,j);
		}
	}
	if(j>0&&campovisto[i][j-1]!=0)
	{
		campovisto[i][j-1]=0;
		if (campo[i][j-1]==0)
			mudacampo(i,j-1);
	}
	if(j<9&&campovisto[i][j+1]!=0)
	{
		campovisto[i][j+1]=0;
		if (campo[i][j+1]==0)
			mudacampo(i,j-1);
	}
	if(i<9)
	{ 	
		if(j>=1&&campovisto[i+1][j-1]!=0)
		{
			campovisto[i+1][j-1]=0;
			if (campo[i+1][j-1]==0)
				mudacampo(i+1,j-1);
		}
		if(j<9&&campovisto[i+1][j+1]!=0)
		{
			campovisto[i+1][j+1]=0;
			if (campo[i+1][j+1]==0)
				mudacampo(i+1,j+1);
		}
		if (campovisto[i+1][j]!=0)
		{
			campovisto[i+1][j]=0;
			if (campo[i+1][j]==0)
				mudacampo(i+1,j);
		}
	}
}

void mostracampo()
{
	int i,j;
	for( i = 0 ; i < 10 ; i++ ) 
	{
		for( j = 0 ; j < 10 ; j++ )
		{
			if(campovisto[i][j]!=0)
				printf("# ");
			else{
				printf("%d ", campo[i][j]);
			}
		}
		printf("\n");
	}
}

void mostracampo2()
{
	int i,j;
	for( i = 0 ; i < 10 ; i++ ) 
	{
		for( j = 0 ; j < 10 ; j++ )
		{	
			if (campo[i][j]<0)
				printf("%d ", campo[i][j]);
			else
				printf(" %d ", campo[i][j]);
		}
		printf("\n");
	}
	
}

int main()
{
	int i,j;
	preencheCampo();	
	prenchenumeros();
	for( i = 0 ; i < 10 ; i++ ) 
	{
		for( j = 0 ; j < 10 ; j++ )
		{
			campovisto[i][j]='#';
		}
	}
	while(1)
	{
		mostracampo();
		printf("\n Escolha uma casa: \n");
		//mostracampo2();
		scanf("%d %d",&i,&j);
		system("clear");
		if(campo[i][j]==-1)
		{
			printf("Perdeu\n");
			return 0;
		}
		else if(campo[i][j]==0)
			mudacampo(i,j);
		else
			campovisto[i][j]=0;
	}
	return 0;
}
