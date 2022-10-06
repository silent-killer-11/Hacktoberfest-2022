#include<iostream>
using namespace std;
void maximumDifference(int arr[],int n){
    int res = arr[1]-arr[0];
    for(int i =0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            res =max(res ,arr[j]-arr[i]);
        }
    }
    cout<<res<<endl;
}



int main(){
    int arr[]={2,3,10,6,4,8,1};
    maximumDifference(arr,7);
//

return 0;
}