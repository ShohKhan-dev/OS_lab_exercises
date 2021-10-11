#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <bits/types.h>

int main(void)
{
	int mg = 10;
	int byte = 1000000;
	struct rusage data;
	
    	for (int i = 0; i < 10; i++)
    	{
		memset(calloc(mg * byte, 1), 0, mg * byte);
		printf("10MB memory were allocated!\n");
		getrusage(0, &data);
		printf("|USER    \t|PROCESS|TIME   |MAX RSS|IX RSS |ID RSS |IS RSS |IDS RSS|\n");
		printf("|shohjahon\t|ex4\t|%ld \t|%ld\t|%ld\t|%ld\t|%ld\t|%ld\t|\n",
		       data.ru_stime, data.ru_maxrss, data.ru_ixrss, data.ru_idrss, data.ru_isrss, data.ru_idrss);
		sleep(1);
    	}
    	return 0;
}

