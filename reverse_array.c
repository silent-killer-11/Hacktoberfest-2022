#include<stdio.h>
int main()
{
    int a[5], i,j,c;
    int *p1=a;

    printf("Enter array elements: ");
    for(i=0; i<5; i++)
    {
        scanf("%d", (p1+i));
    }
    printf("\nArray elements are as follows: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", *(p1+i));
    }
    for(i=0,j=5-1; i<j; i++, j--)
  {
    c=*(a+i);
    *(a+i)= *(a+j);
    *(a+j)=c;
  }
  printf("\n\nAfter reversing, Array elements are as follows: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", *(p1+i));
    }
}
