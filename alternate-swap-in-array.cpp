#include <iostream>
using namespace std;
void inputarray(int arr[], int k)
{
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
}

void alternateswap(int arr[], int n)
{
    int i =0;
    while (i<n)
    {

    if (i+1<n)
    {
        swap(arr[i],arr[i+1]);
       
    }
     i = i+2; 
    }
    
}
void printarray(int arr[],int k){
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
    
}
int main()
{
    int n;
    cout << "size of array" << endl;
    cin >> n;
    int arr[100];
    cout << "enter the element of array" << endl;
    inputarray(arr, n);
    alternateswap(arr, n);
    printarray(arr,n);
    return 0;
}
