#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int x : asteroids){
           bool toPush = true;
           while(!ans.empty() && ans.back() > 0 && x < 0){
               if(-x>ans.back()) ans.pop_back();
               else if(-x<ans.back()){
                   toPush = false;
                   break;
               }
               else{
                   toPush = false;
                   ans.pop_back();
                   break;
               }
           }
           if(toPush) ans.push_back(x);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}