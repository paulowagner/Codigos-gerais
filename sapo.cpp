#include <stdio.h>
int vet[50][50];
int passou[50][50];
int m,n;
int posy=0,posx=0;
void pos(int v)
{
	if(v==1)
	{
		posy--;
	}
	if(v==2)
	{
		posy--;
		posx++;
	}
	if(v==3)
	{
		posx++;
	}
	if(v==4)
	{
		posx++;
		posy++;
	}
	if(v==5)
	{
		posy++;
	}
	if(v==6)
	{
		posy++;
		posx--;
	}
	if(v==7)
	{
		posx--;	
	}
	if(v==8)
	{
		posy--;
		posx--;
	}
}
bool pode()
{
	if(posx<0||posx>=n)
		return false;
	if(posy<0||posy>=m)
		return false;
	if(passou[posy][posx]==1)
		return false;
	return true;
}

int main(int argc, char const *argv[])
{
	int t=0;
	while(1)
	{
		t++;
		scanf("%d %d",&m,&n);
		if(m==n&&m==0)
			break;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d",&vet[i][j]);
			}	
		}
		int cont=0;
		do
		{
			cont++;
			passou[posy][posx]=1;
			pos(vet[posy][posx]);
		}while(pode());
		if(cont==(m*n))
			printf("Instancia %d\nsim\n\n",t);
		else
			printf("Instancia %d\nnao\n\n",t);
	}
	return 0;
}