#include <stdio.h>
typedef struct Process{
	int Index;
	int BT;
	int AT;
	int TAT;
	int CT;
	int WT;
	} Process;
	
void FIFO_Scheduler(struct Process * p,int n){
	int j, i;
    for (i=1;i<n;i++){
        for(j=0;j<n-1;j++){
            if (p[i].AT<p[j].AT){
                Process t=p[i];
                p[i]=p[j];
                p[j]=t;
            }
        }
    }
}
void SJN_Scheduler(struct Process * p,int n){
	int i, j;
	
    for (i=1;i<n;i++){
        for(j=0;j<n-1;j++){
            if (p[i].BT<p[j].BT ){
                Process t=p[i];
                p[i]=p[j];
                p[j]=t;
            }
        }
    }
    for(i=0;i<n;i++){
        if (p[i].AT<p[0].AT){
            Process t=p[0];
            p[0]=p[i];
            p[i]=t;
        }
    }

    for(j=1;j<n-1;j++){
        int t1=p[j-1].AT;
        int t2=p[j-1].BT+t1;
        for(i=j+1;i<n;i++){
            if (p[i].AT<p[j].AT && t2>p[i].AT &&p[i].BT<p[j].BT){
                Process t=p[j];
                p[j]=p[i];
                p[i]=t;
            }
        }
    }

}

int main(){
	
    int N;
    printf("Enter Arrival and Burst time for each process:\n");
    scanf("%d",&N);
    Process P[N];
    int i;
    
    for(i=0;i<N;i++)
	{
        P[i].Index=i;
        printf("Arrival time of process[%d]: ", i);
        scanf("%d",&P[i].AT);
        printf("Burst time of process[%d]: ", i);
        scanf("%d",&P[i].BT);
    }
    
    SJN_Scheduler(P,N);
    int cmp_time=0;
    for(i=0;i<N;i++){
        if (P[i].AT-cmp_time>=0)
            cmp_time =cmp_time+ P[i].BT+(P[i].AT-cmp_time);
        else
            cmp_time =cmp_time+ P[i].BT;
        P[i].CT=cmp_time;
    }
    int TurnAroundTime=0;
    int WaitingTime=0;
    for(i=0;i<N;i++){
        P[i].TAT=P[i].CT-P[i].AT;
        TurnAroundTime+=P[i].TAT;
        P[i].WT=P[i].TAT-P[i].BT;
        WaitingTime+=P[i].WT;
    }
    printf("|Pr \t| AT \t| BT \t| CT \t| TAT \t| WT \t|\n");
    for(i=0;i<N;i++)
        printf("|%d \t| %d \t| %d \t| %d \t| %d \t| %d \t|\n",P[i].Index,P[i].AT,P[i].BT,P[i].CT,P[i].TAT,P[i].WT);
    
    printf("Average Turn-around time is: %d\n",TurnAroundTime/N);
    printf("Average Waiting time is: %d\n",WaitingTime/N);
}

