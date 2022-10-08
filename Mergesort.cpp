#include <iostream>
using namespace std;
void merge(int arr[], int s, int e)
{
    int mid = (s + e) / 2;
    int leftlength = mid - s + 1;
    int rightlength = e - mid;

    // creating left and right parts
    int *left = new int[leftlength];
    int *right = new int[rightlength];

    // copy into left array
    int originalindex = s;
    for (int i = 0; i < leftlength; i++)
    {
        left[i] = arr[originalindex++];
    }

    // copy into right array
    originalindex = mid + 1;

    for (int i = 0; i < rightlength; i++)
    {
        right[i] = arr[originalindex++];
    }

    // now we have two sorted array and
    // we have to merge them
    int leftindex = 0;
    int rightindex = 0;
    originalindex = s;

    // compare elements from left and right and copy in original array
    while (leftindex < leftlength && rightindex < rightlength)
    {
        if (left[leftindex] <= right[rightindex])
        {
            arr[originalindex++] = left[leftindex++];
        }
        else
        {
            arr[originalindex++] = right[rightindex++];
        }
    }

    // check if any more element present in left array and put all the remaining element of array
    while (leftindex < leftlength)
    {
        arr[originalindex++] = left[leftindex++];
    }

    while (rightindex < rightlength)
    {
        arr[originalindex++] = right[rightindex++];
    }
}

void mergesort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    // left part

    mergesort(arr, s, mid);

    // right part
    mergesort(arr, mid + 1, e);

    // merge two sorted array

    merge(arr, s, e);
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = 6;
  
    mergesort(arr, 0, size - 1);
  
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " ;
    }

    return 0;
}
