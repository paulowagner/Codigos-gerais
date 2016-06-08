#include <stdio.h>

int main() 
{
  int mul=1;
  for(int i=2;i<vet[n-1];i++)
  {
    int cont
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