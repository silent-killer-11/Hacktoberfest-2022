#include<iostream>
using namespace std;

void frequency(int arr[],int n){
    int var;
    for(int i =0;i<n-1;i++){
         var =1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==-1)
            {
                break;
             
            }
             
               else if(arr[i]==arr[j]){
                    var++;
                    arr[j]=-1;
                }


            }
            if(arr[i]!=-1){
                cout<<arr[i]<<" "<<var<<endl;
            }
        }
 
}
 

int main(){
    int arr[]={10,10,10,20,20,15,15};
    frequency(arr,7);
     


return 0;
}