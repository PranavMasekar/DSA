#include <bits/stdc++.h>
using namespace std;

int mazecount(int row , int col){
    if(row==1 || col==1) return 1;
    return mazecount(row-1,col) + mazecount(row , col-1);
}

void printmaze(string ans , int row , int col){
    if(row==1 && col==1) {
        cout<<ans<<endl;
        return ;
    }
    // Stop going down if it is already at the last row
    if(row>1) printmaze(ans + 'D',row-1,col);
    // Stop going right if it is already at the last col
    if(col>1)  printmaze(ans + 'R',row , col-1);
}

vector<string> returnmaze(string ans , int row , int col){
    if(row==1 && col==1) {
        vector<string> s;
        s.push_back(ans);
        return s;
    }
    vector<string> left;
    vector<string> right;
    if(row>1) left = returnmaze(ans + 'D',row-1,col);
    if(col>1) right = returnmaze(ans + 'R',row , col-1);
    // Add both recursion calls and return 
    left.insert(left.begin(),right.begin(),right.end());
    return left;
}

vector<string> returnmazediagonal(string ans , int row , int col){
    if(row==1 && col==1) {
        vector<string> s;
        s.push_back(ans);
        return s;
    }
    vector<string> left;
    vector<string> right;
    vector<string> mid;
    if(row>1) left = returnmazediagonal(ans + 'V',row-1,col);
    if(col>1) right = returnmazediagonal(ans + 'H',row , col-1);
    if(row>1 && col>1) mid = returnmazediagonal(ans + 'D' , row-1 , col-1);
    // Add both recursion calls and return 
    left.insert(left.begin(),right.begin(),right.end());
    left.insert(left.begin(),mid.begin(),mid.end());
    return left;
}

int main(){
    // cout<<mazecount(3,3);
    // printmaze("",3,3);
    // vector<string> ans = returnmaze("", 3,3);
    // cout<<"[ ";
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout<<']';
    vector<string> ans = returnmazediagonal("", 3,3);
    cout<<"[ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout<<']';
    return 0;
}