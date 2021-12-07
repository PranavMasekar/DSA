#include <bits/stdc++.h>
using namespace std;

void reverse(string s,int size,int index){
    if(index>size) return ;
    else{
        reverse(s,size,index+1);
        cout<<s[index]<<" ";
    }
}

int main(){
    string s = "Pranav";
    reverse(s,6,0);
    return 0;
}