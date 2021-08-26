#include <stdio.h>


int main(){
	char str[100];
	
	printf("Enter String: ");
	
	fgets(str, 100, stdin);
	
	int i;
	
	
	for (i=strlen(str); i--; i>0){
		printf("%c", str[i]);
	}
	
	
	return 0;
}
