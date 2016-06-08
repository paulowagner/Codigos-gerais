#include <stdio.h>
#include <string.h>
int strlenn(char *s);

int main(){
	char teste[100];
	teste[0] = 0;

	strcat(teste,"hoje");
	printf("%s %d\n",teste,sizeof(char) );
	printf("%d\n",teste[4] );
	printf("%s %d\n",teste,strlenn(teste) );
	return 0;
}
