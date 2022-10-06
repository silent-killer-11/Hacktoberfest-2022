#include<iostream>
using namespace std;
void reversed(int arr[],int n){
    int reversed_arr[n];

    for(int i =n-1;i>=0;i--){
        reversed_arr[n-1-i] = arr[i];
    }
for(int i=0;i<n;i++){
    cout<<reversed_arr[i]<<endl;
}
}
int main(){
    int arr [] ={1,2,3,4,5,6,7,8,9};
    reversed(arr,9)
;
return 0;
}