#include <bits/stdc++.h>
using namespace std;

int geek(int a,int b,int c , int n){
    if(n<=3) return c;
    else geek(b,c,a+b+c,n-1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,n;
        cin>>a>>b>>c>>n;
        cout<<geek(a,b,c,n);
    }
    return 0;
}