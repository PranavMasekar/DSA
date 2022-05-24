#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
void BFS(int source,vector<bool>& visit){
    queue<int> q;
    q.push(source);
    visit[source] = true;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        cout<<current<<" ";
        for(int child : g[current]){
            if(!visit[child]) {
                q.push(child);
                visit[child] = true;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<bool> visit = {false};
    for(int i=0;i<n-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    BFS(1,visit);
    return 0;
}