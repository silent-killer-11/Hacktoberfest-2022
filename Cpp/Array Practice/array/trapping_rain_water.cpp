#include<iostream>
using namespace std;
void  trapingRainWater(int arr[],int n){
    int lowest = min(arr[0],arr[n-1]);
    int totalBlocks = lowest*n;
    int occupiedBlocks=0;
    for(int i =1;i<n-1;i++){
      
     occupiedBlocks +=arr[i];
    }
 
    cout<<totalBlocks-occupiedBlocks-2*lowest<<endl;

}
int main(){
    int arr[]={3,0,1,2,5};
    trapingRainWater(arr,5);

return 0;
}