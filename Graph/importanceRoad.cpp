#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.first > b.first;
    }
public:
    long long maximumImportance(int n, vector<vector<int>> &roads) {
       vector<pair<int,int>> map;
       vector<int> degree(n,0);
       vector<int> importance(n,0);
        for(auto edge : roads){
            int i = edge[0];
            int j = edge[1];
            degree[i]++;
            degree[j]++;
        }
        for(int i=0;i<degree.size();i++){
            map.push_back({degree[i],i});
        }
        sort(map.begin(),map.end(),cmp);
        
        for(int i=0;i<map.size();i++){
            importance[map[i].second] = n;
            n--;
        }
        long long ans = 0;
        for(int i=0;i<roads.size();i++){
            int j = roads[i][0];
            int k = roads[i][1];
            ans += importance[j] + importance[k];
        }
        return ans;
    }
};

int main() {

    return 0;
}