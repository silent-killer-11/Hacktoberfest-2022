#include<stdio.h>  
void completion_time_calc(int P_no[],int n,int at[],int bt[],int ct[])
{
  ct[0]=at[0]+bt[0];
  for(int i=1;i<n;i++)
  {
    ct[i]=ct[i-1]+bt[i];
  }
}
void Turnaround_time_calc( int P_no[], int n,int bt[], int wt[], int tat[])  
{  
  for (int  i = 0; i < n ; i++)  
    tat[i] = bt[i] + wt[i];  
}  
    
void Waiting_time_calc(int P_no[], int n,int bt[], int wt[],int rt[])  
{  
  wt[0]=rt[0]= 0;  
  for (int  i = 1; i < n ; i++ )  
    {
      wt[i] =  bt[i-1] + wt[i-1] ;
      rt[i] = wt[i];
    }  
}  
void Avg_time_calc( int P_no[], int n, int bt[],int at[])  
{  
  int wt[n],tat[n],rt[n],ct[n], WT_total = 0, TAT_total = 0;  
  Waiting_time_calc(P_no, n, bt, wt,rt);   
  Turnaround_time_calc(P_no, n, bt, wt, tat);  
  completion_time_calc(P_no,n,at,bt,ct);
  printf("  Pno   AT     BT     CT      WT     TAT     RT\n");  
  for (int  i=0; i<n; i++)  
  {  
    WT_total = WT_total + wt[i];  
    TAT_total = TAT_total + tat[i];  
    printf("   %d ",(i+1)); 
    printf("    %d",at[i]);
    printf("     %d", bt[i] ); 
    printf("      %d",ct[i]);
    printf("       %d",wt[i]); 
    printf("       %d",tat[i]);  
    printf("       %d\n",rt[i]);
  }  
  float s=(float)WT_total / (float)n; 
  float t=(float)TAT_total / (float)n;
  float r=s; 
  printf("Average turn around time = %f\n",t);
  printf("Average waiting time = %f",s); 
  printf("\n"); 
  printf("Average response time=%f\n",r);
}  
void main()  
{  
  int P_no[] = { 1, 2, 3, 4, 5};
  int  burst_time[] = { 4, 3, 1, 2, 5}; 
  int arrival_time[]={0,1,2,3,4};   
  int n = sizeof P_no / sizeof P_no[0];  
  Avg_time_calc(P_no, n,burst_time,arrival_time);    
}
