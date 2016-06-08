#include <stdio.h>
#include <string.h>
int calc(void *vet);

int main(int argc, char const *argv[])
{
	char vet[20];
	strcpy(vet,"4 + 7\0");
	printf("%d\n", calc(vet));
	strcpy(vet,"4 - 7\0");
	printf("%d\n", calc(vet));
	strcpy(vet,"4 * 7\0");
	printf("%d\n", calc(vet));
	strcpy(vet,"4 / 7\0");
	printf("%d\n", calc(vet));
	return 0;
}