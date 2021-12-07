#include <bits/stdc++.h>
using namespace std;

bool check(int n , int i) {
    long long x = pow(4,i);
    if(x==n) return true; 
    else if(x>n) return false;
    else return check(n,i+1);
}

int main(){
    int n=1;
    cout<<check(n,0);
    return 0;
}