#include <stdio.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
      int k=partition(arr,low,high);  
      quicksort(arr,low,k-1);
      quicksort(arr,k+1,high);
    }
    
}
int  partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int start=low;
    int end=high;
    while(start<end)
    {

      while(arr[start]<=pivot)
      {
        start++;
      }
       while(arr[end]>pivot)
      {
        end--;
        }
     if(start<end)
     {
         swap(&arr[start],&arr[end]);
     }
    }
    swap(&arr[low],&arr[end]);
    return end;  
}

int main (void)
{
    int i;
    int arr[]={3,7,9,10,12,6,5,2,11,18};
    int n=10;
    quicksort(arr,0,n-1);
    printf("After Sorting...\n");
    
    for(i=0;i<n;i++)
    {
        printf(" %d ",arr[i]);
    }

}