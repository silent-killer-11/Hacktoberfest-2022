#include<stdio.h>
#include <stdlib.h>
#include <limits.h>
int findmax(int arr[],int n)
{
    int max=INT_MIN;
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }
    return max;

}
void countsort(int arr[],int n)
{
   int max,i,j;
   int *c;
   max=findmax(arr,n);
   c=(int*)malloc(sizeof(int)*(max+1));
   for(i=0;i<max+1;i++)
   {
       c[i]=0;
   }
   for(i=0;i<n;i++)
   {
       c[arr[i]]++;
   }

i=0;
j=0;
while(i<(max+1))
{
  if(c[i]>0)
  {
      arr[j++]=i;
      c[i]--;
  }
  else
  {
      i++;
  }
}
}
int main (void)
{
    int i;
    int arr[]={3,7,9,10,12,6,5,2,1,18};
    int n=10;
    countsort(arr,n);
    printf("After Sorting...\n");
    
    for(i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }

}