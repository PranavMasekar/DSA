#include <bits/stdc++.h>
using namespace std;

int length(char *s){
    if(*s=='\0'){
        return 0;
    }
    else{
        return 1 + length(s+1);
    }
}

int main(){
    string s = "pranav";
    cout<<length(&s[0]);
    return 0;
}