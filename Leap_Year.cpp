#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=2020;
    if(n%100!=0 && n%4==0 || n%400==0){
        cout<<n<<" ";
    }
    return 0;
}
