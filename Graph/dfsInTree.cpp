#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int depth[N],height[N];
vector<int> g[N];

void DFS(int current,int parent){
    //Actions on current after entering
    cout<<current<<endl;
    for(int childs : g[current]){
        // Action on child node before visiting child node
        if(childs==parent) continue;
        DFS(childs,current);
        // Action on child node after visiting child node
    }
    //Action on current before leaving the current 
}


int main(){
    
    return 0;
}