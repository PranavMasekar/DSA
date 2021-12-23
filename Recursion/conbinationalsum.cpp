#include <bits/stdc++.h>
using namespace std;

void combination(vector<int>&candidates, int target, vector<vector<int>>& res, vector<int> temp, int index){
    if(target<0) return ;
    if(target==0){
        res.push_back(temp);
        return;
    }
    for(int i=index;i<candidates.size();i++){
        temp.push_back(candidates[i]);
        combination(candidates,target-candidates[i],res,temp,i);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if(target==0) return {{}};
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> res;
    vector<int> temp;
    combination(candidates,target,res,temp,0);
    return res;
}

int main(){
    
    return 0;
}