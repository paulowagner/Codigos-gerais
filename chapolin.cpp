#include <iostream>
#include <fstream>
#include <cmath>
#include <string.h>
#include <map>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
long double vet[100000];
int n,t;

void preenche()
{
	vet[0] = 0;
	vet[1] = 1; 
	for (int i = 2; i < 100000; ++i)
	{
		vet[i] = vet[i-1]+vet[i-2];
		cout<<vet[i]<<endl;
	}
}
int main()
{
	int troca;
	int falsa;
	preenche();
	scanf("%d %d",&n,&t);
	while(n!=0||t!=0){		
		cout<<(long double)(((2*vet[t]) + vet[t-1])*n)<<endl;
		scanf("%d %d",&n,&t);
	};
	return 0;
}