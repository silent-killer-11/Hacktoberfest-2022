//
// Created by amodraper on 10/6/22.
//
#include<bits/stdc++.h>
using namespace std;

bool prime(int n) {
    for(int i = 2 ; i*i < n ; i++) {
        if(n%i == 0) return false;
    }
    return true;
}

void sieve(int n) {
    vector<bool> isPrime(n+1 , true);
    for(int i = 2 ; i*i < n+1 ; i++){
        if(prime(i)) {
            for(int j = i*2 ; j < n+1 ; j+=i) {
                isPrime[j] = false;
            }
        }
    }
    for(int i = 2 ; i < n+1 ; i++) {
        if(isPrime[i]) cout<<i<<'\t';
    }
}

int main() {

    sieve(50);
    return 0;
}