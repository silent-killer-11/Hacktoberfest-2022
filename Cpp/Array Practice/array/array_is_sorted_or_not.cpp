#include<iostream>
using namespace std;
void sortedOrNot(int arr[],int n){
    for(int i = 0; i<n-1 ;i++){
     if(arr[i]>arr[i+1]){
         cout<<"Unsorted"<<endl;
        return;
     }
    }
    cout<<"sorted"<<endl;
};


int main(){
    int arr[]= {1,3,51,33};
    sortedOrNot(arr,4);

return 0;
}