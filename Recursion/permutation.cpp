#include <bits/stdc++.h>
using namespace std;

void permutation(string ans , string main){
    // Same conditin as subset to print the values
    if(main.empty()) {
        cout<<ans<<endl;
        return ;
    }
    char ch = main.at(0);
    // In permutation the function calls are variable and they are ans.size + 1 times in each level
    for(int i=0;i<=ans.size();i++){
        // There are ans.size positions where the char can be added in string ans
        string first  = ans.substr(0,i);
        string second  = ans.substr(i,ans.size());
        permutation(first + ch  + second , main.substr(1));
    }
}

int permutationcount(string ans , string main){
    if(main.empty()) {
        return 1;
    }
    char ch = main.at(0);
    int count = 0;
    for(int i=0;i<=ans.size();i++){
        string first  = ans.substr(0,i);
        string second  = ans.substr(i,ans.size());
        // Get the count from the below recursive calls and add them to local count and return.
        count += permutationcount(first + ch  + second , main.substr(1));
    }
    return count;
}


vector<string> returnpermutation(string ans, string main)
{
    if(main.empty()) {
        vector<string> s;
        s.push_back(ans);
        return s;
    }
    char ch = main.at(0);
    vector<string> s2;
    for(int i=0;i<=ans.size();i++){
        string first  = ans.substr(0,i);
        string second  = ans.substr(i,ans.size());
        // Get all the strings from the below recursion calls and add it into the main ans
        vector<string> temp = returnpermutation(first + ch  + second , main.substr(1));
        s2.insert(s2.begin(),temp.begin(),temp.end());
    }
    return s2;
}

int main(){
    string s = "abc";
    // permutation("",s);
    cout<<permutationcount("",s);
    // vector<string> ans = returnpermutation("",s);
    //  for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << endl;
    // }
    return 0;
}