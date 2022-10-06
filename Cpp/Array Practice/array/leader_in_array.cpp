#include<iostream>
using namespace std;
void leaderInArray(int arr[],int n){
    for (int i =0;i<n;i++){
        int var =0;
        for(int j =i+1;j<=n;j++)
        {
            
            if(arr[i]>arr[j]){
                var++;
            }
            
            

        }

          if(var==n-i){
                cout<<arr[i]<<endl;
            }
             
    }
    
}





int main(){
    int arr[]={10,2,5,4,30,1};
    leaderInArray(arr,6);

return 0;
}