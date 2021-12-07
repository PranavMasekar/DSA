#include <bits/stdc++.h>
using namespace std;

bool check(int n , int i) {
    if(pow(2,i)>n) return false;
    else if(pow(2,i)==n) return true;
    else return check(n,i+1);
}

int main(){
    int n=16;
    cout<<check(n,0);
    return 0;
}