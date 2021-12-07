#include <bits/stdc++.h>
using namespace std;

int naturalsum(int n,int i){
    if(i>n) return 0;
    return i + naturalsum(n,i+1);
}

int main(){
    int n=5;
    cout<<naturalsum(n,1);
    return 0;
}