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

int n,m;
vector<int> v;
int cont;


//1 6 11 16 4 9 14
bool dfs(){
	int i = 0;
	while(1){
		if(v[i] == 13 && v.size() == 1) return true;
		if(v[i] == 13 && v.size() != 1) return false;
		vector<int>::iterator it;
  		it = find(v.begin(), v.end(), v[i]);
	  	if (it != v.end()){
	    		v.erase(it);
				i--;
	    }
		i+=m;
		while(i >= v.size()){ 
			i = i- v.size();
		}
	}
}

int main(){
	scanf("%d",&n);
	while(n !=0){
		m = 1;
		v.clear();
		for(int i=1;i<=n;i++){
			v.push_back(i);
		}
		while(!dfs()){
			v.clear();
			for(int i=1;i<=n;i++){
				v.push_back(i);
			}	
			m++;
		}
		printf("%d\n",m);
		scanf("%d",&n);
	}	
	return 0;
}






