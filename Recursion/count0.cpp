#include <bits/stdc++.h>
using namespace std;

int count(int n){
    if(n==1) return 1;
    if(n%2==0){
        return 1 + count(n/2);
    }
    else{
        return 1 + count(n-1);
    }
}

int main(){
    int n;
    n = 123;
    cout<<count(n);
    return 0;
}