#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(void)
{
	int mg = 10;
	int byte = 1000000;
	
    	for (int i = 0; i < 10; i++)
    	{
		memset(calloc(mg * byte, 1), 0, mg * byte);
		printf("10MB memory were allocated!\n");
		sleep(10);
    	}
    	return 0;
}
