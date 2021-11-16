#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_PROC 100
#define MAX_RES 100
#define MAX_LINE 300

int main(int argc, char *argv[])
{
	// Reading file
	
	char *input_file;
	char *output_file;
	
	
	char inp[25];
	
	if(argc >= 2)
		input_file = argv[1];
	
	if(argc >= 3)
		output_file = argv[2];
		
	
	
	FILE *input = fopen(input_file, "r");
	if(input == NULL)
	{
		printf("Cannot open input file!!!\n");
		return 2;
	}
	char buffer[MAX_LINE];
	
	int processes[MAX_PROC], existing_resources[MAX_RES], available_resources[MAX_RES];
	int current_allocation[MAX_PROC][MAX_RES], request[MAX_PROC][MAX_RES];
	
	// Getting inputs
	
	// line 1 - existing resources (E)
	
	fgets(buffer, MAX_LINE, input);
	char *p = buffer;
	int existing_cnt=0;
	while(*p != '\n')
	{
		int temp = strtol(p, &p, 10);
		existing_resources[existing_cnt++] = temp;
	}
	if(getc(input) != '\n')	
	{
		printf("Invalid input in file!!!\n");
		return 1;
	}
	// line 2 - Available resources (A)
	
	fgets(buffer, MAX_LINE, input);
	p = buffer;
	int available_cnt=0;
	while(*p != '\n')
	{
		int temp = strtol(p, &p, 10);
		available_resources[available_cnt++] = temp;
	}
	int temp;
	if(existing_cnt != available_cnt || getc(input) != '\n')
	{
		printf("Invalid input in file!!!\n");
		return 1;
	}
	
	// from line 3 - Current allocation matrix (C)
	
	int process_cnt=0;
	while(strcmp(fgets(buffer, MAX_LINE, input), "\n") != 0)
	{
		p=buffer;
		for(int i=0; i<existing_cnt; i++)
		{
			temp = strtol(p, &p, 10);
			current_allocation[process_cnt][i] = temp;
		}
		process_cnt++;
	}
	
	// from line 4 - Request Matrix
	
	for(int i=0; i<process_cnt; i++)
	{
		fgets(buffer, MAX_LINE, input);
		p=buffer;
		for(int j=0; j<existing_cnt; j++)
		{
			temp = strtol(p, &p, 10);
			request[i][j] = temp;
		}
	}
		
	
	
	// Bankers algorithm
	
	int process_ok[MAX_PROC] = {};
	
	while(1)
	{
		int satisfied = 0;
		for(int i=0; i<process_cnt; i++)
		{
			if(process_ok[i])
				continue;
			int j;
			for(j=0; j<available_cnt; j++)
			{
				if(request[i][j] > available_resources[j])
				{
					break;
				}	
			}
			if(j != available_cnt)	
				continue;				
			
			for(j=0; j<available_cnt; j++)
			{
				available_resources[j] += request[i][j] + current_allocation[i][j];
			}
			satisfied = 1;
			process_ok[i] = 1;
		}
		if(satisfied == 0)
			break;
	}
	
	FILE *output = fopen(output_file, "w");
	
	int deadlock = 0;
	for(int i=0; i<process_cnt; i++)
	{
		if(!process_ok[i])
		{
			deadlock = 1;
			break;
		}
	}
	
	if(deadlock)
	{
		fprintf(output, "Deadlocked processes: ");
		printf("Deadlocked processes: ");
		for(int i=0; i<process_cnt; i++)
		{
			if(!process_ok[i])
			{
				fprintf(output, "%d, ", i);
				printf("%d ", i);
				
			}
		}
		
		fprintf(output, "\n");
	}
	else
	{
		fprintf(output, "No deadlock found!\n");
		printf("No deadlock found!");
	}
	
	printf(" on %s", argv[1]);
	printf("\n");
	return 0;
}
