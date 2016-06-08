#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int i;
	char *pointer = (char *) malloc(10 * sizeof(char));
	for (i = 0; i < 10; ++i)
	{
		pointer[i] = 97+i;
	}
	printf("%d\n",(int )(sizeof(size_t)) );
	pointer = realloc(pointer, 5); /* certo */
	for (i = 0; i < 5; ++i)
	{
		printf("%x ",pointer[i] );
	}
	printf("\n");
	return 0;
}