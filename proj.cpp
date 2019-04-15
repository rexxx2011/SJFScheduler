#include<stdio.h>
int main()
{
int i,n,pnum[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,b_time=0;
int bt[10],temp,j,at[10],wt[10],tt[10],ta=0,sum=0;
float wavg=0,tavg=0,tsum=0,wsum=0;
printf("**********************************\n");
printf(" Shortest Job First Scheduling \n");
printf("***********************************\n");
printf("\nPlease Enter the No. of Processes to be executed :");
scanf("%d",&n);
 
for(i=0;i<n;i++)
{
printf("\nEnter the arrival time of %d process :",i+1);
scanf(" %d",&at[i]);
bt[i]=2*at[i];
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(at[i]<at[j])
{
temp=pnum[j];
pnum[j]=pnum[i];
pnum[i]=temp;
temp=at[j];
at[j]=at[i];
at[i]=temp;
temp=bt[j];
bt[j]=bt[i];
bt[i]=temp;
}
}
}
wt[0]=0;
for(i=1;i<n;i++)
{
sum=sum+bt[i-1];
wt[i]=sum-at[i];
wsum=wsum+wt[i];
}
 
wavg=(wsum/n);
for(i=0;i<n;i++)
{
ta=ta+bt[i];
tt[i]=ta-at[i];
tsum=tsum+tt[i];
}
 
tavg=(tsum/n);
 
printf("________________________________________________________");
printf("\n \t\t Schedule");
printf("\nProcess\t Arrival\t Burst\t Waiting\t Turn-around" );
printf("\n----------------------------------------------------------------");
for(i=0;i<n;i++)
{
printf("\n P%d\t %d\t %d\t\t %d\t\t\t%d",pnum[i],at[i], bt[i],wt[i],tt[i]);
}
 
printf("\n\nAverage Waiting Time : %f",wavg);
printf("\nAverage turn around time  : %f",tavg);
return 0;
}
