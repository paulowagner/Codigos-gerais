#include <stdio.h>
#include <stdlib.h>

union{
	float f;
	unsigned long int l;
}u;
int main(int argc, char const *argv[])
{
	u.f = 10.99;
	printf("%x\n",u.l);
	return 0;
}