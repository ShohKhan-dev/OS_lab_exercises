#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

void *my_thread(void* arg)
{
	int n = (int)(intptr_t)(arg);
    printf("   -> This is test Message from Thread Number %d!\n", n);
    pthread_exit(NULL);
}

int main(void) 
{

  	printf("Enter number of threads to create.\n");
  	printf("N >");
  	int N;
  	scanf("%d",&N);
  	int c;
  	pthread_t thread;
  	
  	for(c=1; c<=N; c++)
  	{
  	  printf("Creating Thread Number %d ...\n", c);
  	  if(pthread_create(&thread, NULL, my_thread,(void*)(intptr_t)c))
  	  {
  	    printf("ERROR IN CREATING Thread Number %d!!!\n",c);
  	    pthread_exit(NULL);
  	    return 0;
  	  }
  	  else
  	  {
  	    printf("Thread Number %d is successfully created!\n", c);
  	  }
  	}
  	pthread_exit(NULL);
  	return 0;
}
