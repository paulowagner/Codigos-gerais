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
int vet[10000];
int n,t,reposta,zeros;
vector<int> v;
void dfs(){
	bool seq;
	vector<int>::iterator it;
	for (int i = 0; i < n; ++i)
	{
		seq = false;
		zeros=0;
		for (int j = 0; j < v.size();j++)
		{
			it = find(v.begin(), v.end(), v[j]);
			if (seq)
			{
				if(v[j]!=0){
					reposta++;
					seq=false;
					v[j]--;
				}else
					zeros++;
			}else{
				if(v[j]==0){
					zeros++;
					seq=true;
				}
				else{
					v[j]--;
				}
			}
		}
		if (seq)
			reposta++;
		if (zeros==t)
		{
			reposta+=(n-i-1);
			break;
		}
	}
	
}
int main()
{
	scanf("%d %d",&n,&t);
	while(n!=0||t!=0){
		v.clear();
		reposta = 0;
		for (int i = 0; i < t; i++)
		{
			scanf("%d",&vet[0]);
			v.push_back(vet[0]);
		}
		dfs();
		printf("%d\n",reposta );
		scanf("%d %d",&n,&t);
	};
	return 0;
}