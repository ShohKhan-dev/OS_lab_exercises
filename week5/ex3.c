#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include  <time.h>

#define INIT 10
#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE] = {[0]= INIT};
int item=0;
int producerLock=1;
int consumerLock=0;

void* producer(void *arg)
{
    while(1)
	{
        for(;!producerLock;);
        if (item == BUFFER_SIZE)
		{
            producerLock=0;
            consumerLock=1;
            printf("BUFFER IS FULL!\n");
            continue;
            }
        buffer[item] = item + INIT;
        printf(" -> PRODUCER: New data is produced in buffer[INDEX #%d: %d]\n",item,buffer[item]);
        item++;
    }
    pthread_exit(NULL);
    return 0;
    }
void * consumer(void *arg)
{
    while(1)
	{
        for(;!consumerLock;);
        if (item==0){
            producerLock=1;
            consumerLock=0;
            printf("WARNING! NO DATA TO CONSUME!\n");
            continue;
        }
        int data = buffer[--item];
        buffer[item]=0;
        printf(" -> CONSUMER: data is consumed in buffer[INDEX #%d: FINISHED]\n",item);
        sleep(1);
    }
    pthread_exit(NULL);
    return 0;
}
int main()
{
    
    printf("STARTING THE PROGRAMM... \n");
    sleep(1);
    printf("...");
    sleep(1);
    printf("\n...");
    sleep(1);
    pthread_t consumer_thread;
    pthread_t producer_thread;
    pthread_create(&producer_thread,NULL,producer,NULL);
    pthread_create(&consumer_thread,NULL,consumer,NULL);
    pthread_join(consumer_thread,NULL);
    pthread_join(producer_thread,NULL);
    pthread_exit(NULL);
    return 0;
}
