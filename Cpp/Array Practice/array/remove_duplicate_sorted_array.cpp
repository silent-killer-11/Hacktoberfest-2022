#include<iostream>
using namespace std;


void deleteDupS(int arr [],int n){
    int temp[n];
    temp[0]=arr[0];
    int count =1;
    for(int i =0;i<n;i++){
        if(temp[count-1]!=arr[i]){
            temp[count]=arr[i];
            count++;
        }
     
    }
 
    for(int i= 0;i<count;i++){
        cout<<temp[i]<<" ";

    }
    cout<<endl;
    cout<<count;
}

int main(){
int arr[]={10,10,10,20,20,20,30};
deleteDupS(arr,7);
return 0;
}