#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

vector< pair<int, int> > g[200000];
int p[200000];
int dist[200000];
int O,D,K;

void dijkstra(int st, int n) {
	for (int i = 1; i <= n; i++)
		dist[i] = 1e+9;
	int u, v, d;
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > Q;
	Q.push(make_pair(0, st)), dist[st] = 0;

	while (!Q.empty()) {
		u = Q.top().second, d = Q.top().first;
		Q.pop();
		if (dist[u] < d)	continue;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].first, w = g[u][i].second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				Q.push(make_pair(dist[v], v));
			}
		}
	}
}


int main(){
    int pezinho;


    scanf("%d %d %d",&O,&D,&K);
    while(O !=0 || K !=0 || D !=0 ){
        for(int i = 0;i < K;i++){
            scanf("%d",&pezinho);
            p[pezinho] = 1;

        }

        for(int i=1; i<= 100000;i++){
            if(((i-1) > 0) && (p[i-1] ==0)) g[i].push_back(make_pair(i-1,1));
            if(((i+1) <= 100000) && (p[i+1]==0))g[i].push_back(make_pair(i+1,1));
            if(((i*2) <= 100000) && (p[i*2]==0)) g[i].push_back(make_pair(i*2,1));
            if(((i*3) <= 100000) && (p[i*3]==0)) g[i].push_back(make_pair(i*3,1));
            if((i%2 == 0) && (p[1/2] == 0)) g[i].push_back(make_pair(i/2,1));
        }
        dijkstra(O,100000);
        if(dist[D] == 1e+9) printf("-1\n");
        else printf("%d\n",dist[D]);
        scanf("%d %d %d",&O,&D,&K);
        for(int i =0;i<100000;i++) dist[i] = 1e+9;
        for(int i =0 ;i<100000;i++) p[i] = 0;
        for(int i =0;i<10000;i++) g[i].clear();
    }
    return 0;
}
