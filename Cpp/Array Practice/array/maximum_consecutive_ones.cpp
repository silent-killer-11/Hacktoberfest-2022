#include<iostream>
using namespace std;

void maximumConsecutiveOnes(int arr[],int n,int strart){
    int totalZero =0;
    int Zero=0;
    for(int i =strart;i<n;i++){
        if(arr[i]==1){
            
           Zero++;
            arr[i]=0;

        }
        else {
            
            maximumConsecutiveOnes(arr, n,i);

        }

        }
}





int main(){

return 0;
}