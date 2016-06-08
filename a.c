#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int a=1,b=2,c=3,k;
	k= (a++)*(++b)+ (++a) - --c;
	printf("%d\n",k );
	return 0;
}