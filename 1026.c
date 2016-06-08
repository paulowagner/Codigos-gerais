#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	
	int a,b;
	long long x;
	while(scanf("%d %d",&a,&b) != EOF){
		x = 0;
		for(int i =0;i<32;i++){
			x = x | ((a&(1<<i))^(b&(1<<i)));
		}
		printf("%ll",x\n);
	}
	return 0;
}
