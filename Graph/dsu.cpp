#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int parent[N];
int sizes[N];

void make(int v){
    parent[v] = v;
    sizes[v] = 1;
}

int find(int v){
    if(v==parent[v]) return v;
    return parent[v] = find(parent[v]);
}

void Union(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(sizes[a]<sizes[b])
            swap(a,b);
        parent[b] = a;
        sizes[a]+=sizes[b];
    }
}
int main(){
    
    return 0;
}