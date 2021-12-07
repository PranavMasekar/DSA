#include <bits/stdc++.h>
using namespace std;

void removeA(string s , string ans){
    if(s=="\0"){
        cout<<ans<<endl;
        return ;
    }
    char ch = s.at(0);
    if(ch=='a'){
        removeA(s.substr(1),ans);
    }
    else{
        removeA(s.substr(1),ans + ch);
    }
}

int main(){
    string s = "asdfasda";
    string ans;
    removeA(s,ans);
    return 0;
}