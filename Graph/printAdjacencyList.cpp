#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

map<int,vector<int>> g;

int main(){
    vector<bool> visit = {false};
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    for(auto ele :g ){
        cout<<ele.first<<": ";
        for(auto i: ele.second){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}