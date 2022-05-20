#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int depth[N],height[N];
vector<int> g[N];

int subtree_sum[N];
int even_count[N];

// Precomputing subtree sum for every node and no of even nodes in that subtree.
void DFS(int current,int parent=0){
    if(current%2==0) even_count[current]++;
    subtree_sum[current] += current;
    for(int child : g[current]){
        if(child==parent) continue;
        DFS(child,current);
        subtree_sum[current] += subtree_sum[child];
        even_count[current] += even_count[child];
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
    DFS(1);
    for(int i=1;i<=n;i++){
        cout<<subtree_sum[i]<<"  "<<even_count[i]<<endl;
    }
    return 0;
}