#include <stdio.h>
#include <stdlib.h>

union{
	float f;
	unsigned long int l;
}u;
int main(int argc, char const *argv[])
{
	union u um;
	um.f = 10.99;
	printf("%x\n",um.l);
	return 0;
}