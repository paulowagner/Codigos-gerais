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

int visited[10001];
int T,N,M,A,B;
vector<int> g[10001];



int pathR(int v, int w)
{
	int t;
	if (v == w) return 1;
	visited[v] = 1;
	for (t = 0; t < g[v].size(); t++){
		if (visited[g[v][t]] == 0)
				if (pathR(g[v][t], w)) return 1;

	}
	return 0;
}

int main()
{
	int flag,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&N,&M);
		for(int i =1;i<=N;i++){
			visited[i] = 0;
			g[i].clear();
		}
		for(int i =0;i <M;i++){
			scanf("%d %d",&A,&B);
			g[A].push_back(B);
		}
		flag = 0;
		for(int i =1;i<=N&&!flag;i++){
			for(int j=0;!flag&&j<g[i].size();j++){
			
				if(pathR(g[i][j],i)) {
					printf("SIM\n");
					flag = 1;
				}

				for(int i =1;i<=N;i++){
					visited[i] = 0;
				}
			}
		}

		if(flag == 0) printf("NAO\n");

	}
	return 0;
}