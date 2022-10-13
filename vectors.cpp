#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cout<<"How many numbers do you want to enter: ";
    cin>>num;

    vector<int> v;
    for(int i = 0; i < num; i++){
        int val;
        cin>>val;
        v.push_back(val);
    }
    cout<<"\n";
    for(auto x: v){
        cout<<x<<" ";
    }
    for (int i = 1; i <num; i++)
        v.push_back(i * 10);
 
    cout << "\nReference operator [v] : v[2] = " << v[2];
 
    cout << "\nat : v.at(4) = " << v.at(3);
 
    cout << "\nfront() : v.front() = " << v.front();
 
    
 
    // pointer to the first element
    int* pos = v.data();
 
    cout << "\nThe first element is " << *pos;
    return 0;
}
