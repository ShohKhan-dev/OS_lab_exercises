#include <stdio.h>

typedef struct Process{
	int processIndex;
	int BT;
	int AT;
	int TAT;
	int CT;
	int WT;
} Process;


int main(){

    int N;
    printf("Enter Arrival and Burst time for each process:\n");
    scanf("%d",&N);
    Process P[N];
    int i;
    
    for(i=0;i<N;i++)
	{
        P[i].processIndex=i;
        printf("Arrival time of process[%d]: ", i);
        scanf("%d",&P[i].AT);
        printf("Burst time of process[%d]: ", i);
        scanf("%d",&P[i].BT);
    }
    
    int cmp_time=0;
    for(i=0;i<N;i++)
	{
        if (P[i].AT-cmp_time>=0)
            cmp_time =cmp_time+ P[i].BT+(P[i].AT-cmp_time);
        else
            cmp_time =cmp_time+ P[i].BT;
        P[i].CT=cmp_time;
    }
    
    int TurnAroundTime=0;
    int WaitingTime=0;
    
    for(i=0;i<N;i++)
    {
        P[i].TAT=P[i].CT-P[i].AT;
        TurnAroundTime+=P[i].TAT;
        P[i].WT=P[i].TAT-P[i].BT;
        WaitingTime+=P[i].WT;
    }
    
    printf("|Pr \t| AT \t| BT \t| CT \t| TAT \t| WT \t|\n");
    for(i=0;i<N;i++)
        printf("|%d \t| %d \t| %d \t| %d \t| %d \t| %d \t|\n",P[i].processIndex,P[i].AT,P[i].BT,P[i].CT,P[i].TAT,P[i].WT);
    
    printf("Average Turn-around time is: %d\n",TurnAroundTime/N);
    printf("Average Waiting time is: %d\n",WaitingTime/N);
}

