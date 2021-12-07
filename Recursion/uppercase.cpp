#include <bits/stdc++.h>
using namespace std;

void uppercase(string s,int size,int index){
    if(index>size) return ;
    if(s[index]<=90){
        cout<<s[index]<<" ";
        uppercase(s,size,index+1);
    }
    else{
        uppercase(s,size,index+1);
    }
}

int main(){
    string s = "geeksforGeeKS";
    uppercase(s,12,0);
    return 0;
}