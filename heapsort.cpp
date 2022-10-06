#include<bits/stdc++.h>
using namespace std;
#define INF 1e18
#define MOD 100000007
void solve();

void heapify(int a[],int n,int i)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;
    if(left<n&&a[left]>a[largest])
    {
        largest = left;
    }
    if(right<n&&a[right]>a[largest])
    {
        largest = right;
    }
    
    if(largest!=i)
    {
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}
void deleteRoot(int a[],int &n)
{
    int leaf = a[n-1];
    a[0] = leaf;
    n--;
    heapify(a,n,0);
}
void heapifybottomup(int a[],int n,int i)
{
    int parent = (i-1)/2;
    if(a[parent]>0)
    {
        if(a[i]>a[parent])
        {
            swap(a[i],a[parent]);
            heapifybottomup(a,n,parent);
        }
    }
}
void insertnode(int a[],int n,int key)
{
    n = n+1;
    a[n-1] = key;
    heapifybottomup(a,n,n-1);
}
void heapsort(int a[],int n)
{
    //first of all we have to build max heap 
    // we are using 0 based indexing 
    for(int i = n/2 - 1;i>0;i--)
    {
        heapify(a,n,i);
    }
    /*
        5 4 3 2 1
        5
       4 3
      2 1
        1 2 3 4 5
        1
       2 3
      4 5

    */
   for (int i = n-1; i > 0; i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
    

}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";

    }
    cout<<"\n";
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    heapsort(a,n);
    print(a,n);
    insertnode(a,n,10);
    print(a,n);

    
}