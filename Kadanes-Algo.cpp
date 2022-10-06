//
// Created by amodraper
//
#include <iostream>
using namespace std;

int main() {
    int n = 8;
    int arr[8] = {-1 , 2 , 4  , -3 , 5 , 2 , -5 , 2 };

    int best = 0 , sum = 0;
    for(int i = 0 ; i < n ; i++) {
        sum = max(arr[i], sum+arr[i]);
        best = max(sum , best);
    }

    cout<<best;
}