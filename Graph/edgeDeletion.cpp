#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
int subtree_sum[N];

void DFS(int current,int parent=-1){
    subtree_sum[current] += current;
    for(int child : g[current]){
        if(child==parent) continue;
        DFS(child,current);
        subtree_sum[current]+=subtree_sum[child];
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int ans = 0;
    for(int i=2;i<=n;i++){
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - part1;
        ans = max(ans,part1*part2);
    }
    cout<<ans<<endl;
    return 0;
}