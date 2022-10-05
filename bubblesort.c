#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void bubblesort(int arr[],int n)
{
    int i,j;
    for( i=0;i<n-1;i++)
    {
        for( j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
int main (void)
{
    int i;
    int arr[]={3,7,9,10,12,6,5,2,1,18};
    int n=10;
    bubblesort(arr,10);
    printf("After Sorting..\n");
    for(i=0;i<10;i++)
    {
        printf(" %d ",arr[i]);
        
    }
}