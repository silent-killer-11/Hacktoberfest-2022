#include <stdio.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void selectionsort(int arr[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(arr[j]<arr[k])
            {
                k=j;
            }
        }
        swap(&arr[k],&arr[i]);
    }

}
int main (void)
{
    int i;
    int arr[]={3,7,9,10,12,6,5,2,1,18};
    int n=10;
    selectionsort(arr,n);
    printf("After Sorting...\n");
    
    for(i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }

}