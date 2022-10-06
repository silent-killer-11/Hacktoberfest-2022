#include<iostream>
using namespace std;

int largestElementindex(int arr[],int n){
    int largest = arr[0];
    int largestIndex =0;
    for(int i =1;i<n;i++){
        if(largest<arr[i]){
            largest = arr[i];
          largestIndex = i;

        }

    }
    return largestIndex;
}

int secondLargest(int arr[],int n,int largestNoIndex){
    arr[largestNoIndex]=-1;
    int secondLargest = arr[0];
    for(int i =1;i<n;i++){
        if(secondLargest<arr[i]){
            secondLargest = arr[i];
        }

    }
    return secondLargest;
    
}


int main(){int arr[] ={10909,2,3,5,95,76,158};

int largestIndex = largestElementindex(arr,7);
cout<<largestIndex<<"yes"<<endl;

    
    cout<<"The second Largest number in the array is : "<<secondLargest(arr,7,largestElementindex(arr,7))<<endl;

return 0;
}