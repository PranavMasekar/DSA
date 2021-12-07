#include <bits/stdc++.h>
using namespace std;

void print(int n){
    if(n<1) return ;
    else{
        print(n-1);
        cout<<n<<' ';
    }
}

int main(){
    int n = 5;
    print(n);
    return 0;
}