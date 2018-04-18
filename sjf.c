#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
 int main()
{
	int i,j,n,d;
   int at[20],bt[20],wt[20],tat[20],total=0,pos,temp;
    float avg_wt,avg_tat;
    char p[30];

   
   printf("sorting of shortest job first Scheduing:\n");
    printf("\nEnter number of process:");
    scanf("%d",&n);
    printf("\n arrival time should be greater than** 3**\n");
	printf("\nas system is in sleep for first  3 sec\n");
    printf("\n enter the arrival time ");
    for(i=0;i<n;i++)
    {
    	
        printf("  \nfor process p%d:",i+1);
        scanf("%d",&d);
        if(d>3)
        {
        at[i]=d;
        p[i]=i+1;                  }
        else     {
		printf("\n the arrival time is lessthan 3\n");
        exit(0); }
    }
    printf("\nEnter Burst Time\n");
     for(i=0;i<n;i++)
    {   printf("  for process p%d:",i+1);
        scanf("%d",&bt[i]);//inputs the burst time 
               p[i]=i+1;           //contains process number
    }//sjf sorting
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        
        {
        	    if(bt[j]<bt[pos])
                pos=j;
        }
            
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
        
          temp=at[i];
        at[i]=at[pos];
        at[pos]=temp;
    
    }
 
    wt[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //average waiting time
    total=0;
 printf("the gant chart is as follows:\n");
for(i=0;i<n;i++)
    {
printf("\t%d",p[i]);
}

    printf("\nProcess\t	 Arrival time   Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\np%d\t\t   %d\t\t    %d\t\t   %d\t\t\t%d",p[i],at[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);}
