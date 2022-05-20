#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int depth[N],height[N];
vector<int> g[N];

void DFS(int vertex,int parent){
    //Actions on vertex after entering
    cout<<vertex<<endl;
    for(int childs : g[vertex]){
        // Action on child node before visiting child node
        if(childs==parent) continue;
        DFS(childs,vertex);
        // Action on child node after visiting child node
    }
    //Action on vertex before leaving the vertex 
}


int main(){
    
    return 0;
}