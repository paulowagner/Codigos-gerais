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
int vet[202];
int n,t;
vector< int> divisores;
map<string, string> nomes;

int main()
{
	int troca;
	int falsa;
	scanf("%d",&n);
	while(n!=0){
		falsa = 0;
		string nome,assinatura;
		for (int i = 0; i < n; ++i)
		{
			cin>>nome;
			cin>>assinatura;
			nomes[nome] = assinatura;
		}
		scanf("%d",&t);
		for (int i = 0; i < t; ++i)
		{
			troca=0;
			cin>>nome;
			cin>>assinatura;
			for (int i = 0; i <nomes[nome].size(); ++i)
			{
				if(nomes[nome].at(i)!=assinatura.at(i))
					troca++;
			}
			if (troca>1)
			{
				falsa++;
			}
		}
		printf("%d\n",falsa );
		scanf("%d",&n);
	};
	return 0;
}