#include<bits/stdc++.h>
using namespace std;

// class Solution 
// {
//     public:
//     //Function to find if there is a celebrity in the party or not.
//     int celebrity(vector<vector<int> >& M, int n)  {
//         // code here 
//         map<int,int> celeb;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(M[i][j]==1) {
//                     celeb[j]++;
//                 }
//             }
//         }
//         for(auto x : celeb){
//             if(x.second == n-1) return x.first;
//         }
//         return -1;
//     }
// };


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n)  {
        stack<int> s;
        int size = n ;
        for(int i = 0;i<n;i++){
            s.push(i);
        }
        int count = 0;
        while(count < n - 1){
            int first = s.top();
            s.pop();
            int second = s.top();
            s.pop();
            if(M[first][second]==1){
                s.push(second);
            }
            else{
                s.push(first);
            }
            count++;
            size--;
        }
        int first = s.top();
        s.pop();
        for(int i = 0;i<n;i++){
            if(i!=first && (M[first][i] || !M[i][first])) return -1;
        }
        return first;
    }
};
int main(){
    
    return 0;
}