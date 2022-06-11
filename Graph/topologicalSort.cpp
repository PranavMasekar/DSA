#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

void TopoSort(vector<int> G[N],int n,int source,vector<int> &indegree){
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> result;
    while(!q.empty()){
        int val = q.front();
        q.pop();
        for(auto child : G[val]){
            indegree[child]--;
            if(indegree[child]==0) q.push(child);
        }
        result.push_back(val);
    }
    for(int val : result){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> G[n];
    vector<int> indegree(n,0);
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        G[v1].push_back(v2);
        indegree[v2]++;
    }
    TopoSort(G,n,0,indegree);
    return 0;
}