#include <bits/stdc++.h>
using namespace std;

void printingCombinations(string ans , string main){
    if(main.empty()){
        cout<<ans<<endl;
        return ;
    }
    //  Converting string to integer
    int digit = main.at(0)-'0';

    for(int i = (digit-1)*3 ; i<digit*3;i++){
        char ch = 'a' + i;
        printingCombinations(ans + ch , main.substr(1));
    }
}

vector<string> returnCombination(string ans , string main){
    if(main.empty()){
        vector<string> s;
        s.push_back(ans);
        return s;
    }
    //  Converting string to integer
    int digit = main.at(0)-'0';
    vector<string> s;
    for(int i = (digit-1)*3 ; i<digit*3;i++){
        char ch = 'a' + i;
        vector<string> temp = returnCombination(ans + ch , main.substr(1));
        s.insert(s.begin(),temp.begin(),temp.end());
    }
    return s;
}

int main(){
    string s = "12";
    // printingCombinations("",s);
     vector<string> ans = returnCombination("", s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}