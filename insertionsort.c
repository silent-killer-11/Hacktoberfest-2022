#include <stdio.h>

void insertionsort(int arr[],int n)
{
    int i,j,x;
    for(i=1;i<n;i++)
    {
        j=i-1;
        x=arr[i];
        while(j>-1 && arr[j]>x)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}
int main (void)
{
    int i;
    int arr[]={3,7,9,10,12,6,5,2,1,18};
    int n=10;
    insertionsort(arr,n);
    printf("After Sorting...\n");
    
    for(i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }

}