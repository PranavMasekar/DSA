#include<bits/stdc++.h>
using namespace std;

// Find the two nodes with highest degree 
// return a + b if not connected else return a + b - 1
// Not Completed
class Solution {
    int getMaxIndex(vector<int> degree){
        int val = 0;
        int ans = 0;
        for(int i=0;i<degree.size();i++){
            if(degree[i]>val) ans = i;
        }
        return ans;
    }
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);
        vector<int> G[n];
        for(auto edge : roads){
            int i = edge[0] , j = edge[1];
            G[i].push_back(j);
            G[j].push_back(i);
        }
        for(int i=0;i<n;i++){
            degree[i] = G[i].size();
        }
        int maxIndex = 0, secondMaxIndex = 0;
        maxIndex = getMaxIndex(degree);
        degree.erase(degree.begin() + maxIndex - 1);
        secondMaxIndex = getMaxIndex(degree);
        // int current = 0;
        // for(int i=0;i<degree.size();i++){
        //     if(degree[i]>=current){
        //         int temp = maxIndex;
        //         current = degree[i];
        //         maxIndex = i;
        //         secondMaxIndex = temp;
        //     }
        // }
        int ans = degree[maxIndex] + degree[secondMaxIndex];
        for(int val : G[maxIndex]){
            if(val==secondMaxIndex) return ans - 1;
        }
        return ans;
        // sort(degree.begin(),degree.end());
        // int last = distance(degree.begin(),max_element(degree.begin(),degree.end()));
        // degree.erase(degree.begin() + last);
        // int secondLast = distance(degree.begin(),max_element(degree.begin(),degree.end()));
        // int ans = degree[last] + degree[secondLast];
        // for(int val : G[last]){
        //     if(val==secondLast) return ans -1;
        // }
        // return ans;
    }
};
int main(){
    
    return 0;
}