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

void divisores_t(){
	for (int i = 2; i <= t/2; ++i)
	{
		if(t%i==0)
			divisores.push_back(i);
	}
}
int mdcrr() 
{
  int mul=1;
  int lim = vet[n-2];
  memcpy(vet,&vet[100],(n-1)*sizeof(int));
  for(int i=2;i<lim;i++)
  {
    int cont=0;
    bool mult = false;
    for (int j = 0; j < n; ++j)
    {
      if(vet[j]%i==0){
        mult = true;
        vet[j]/=i;
      }
      if (vet[j]==1)
      {
        cont++;
      }

    }
    if (mult)
    {
      mul*=i;
      i--;
    }
    if (cont==n)
    {
      break;
    }
  }
  
  return mul;
}
int main()
{
	scanf("%d %d",&n,&t);
	bool a;
	while(n!=0||t!=0){
		a=true;
		divisores.clear();
		divisores_t();
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&vet[i]);
			vet[i+100] = vet[i];
			vector<int>::iterator it;
  			it = find(divisores.begin(), divisores.end(), vet[i]);
	  		if (it != divisores.end())
	    	{
	    		divisores.erase(it);
	    	}
	    	else{
	    		a=false;
		    }
		}
		if(a){
			n++;
			a=false;
			for (std::vector<int>::iterator i = divisores.begin(); i != divisores.end(); ++i)
			{
				vet[n-1]=*i;
				if (mdcrr()==t)
				{
						a=true;
						printf("%d\n",*i);
						break;
				}	
			}
		}if(!a){
			printf("impossivel\n");
		}
		scanf("%d %d",&n,&t);
	};
	return 0;
}