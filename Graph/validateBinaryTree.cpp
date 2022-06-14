#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int parentDSU[N];
int sizes[N];

void make(int v){
    parentDSU[v] = v;
    sizes[v] = 1;
}

int find(int v){
    if(v==parentDSU[v]) return v;
    return parentDSU[v] = find(parentDSU[v]);
}

void Union(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(sizes[a]<sizes[b])
            swap(a,b);
        parentDSU[b] = a;
        sizes[a]+=sizes[b];
    }
}
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n,-1);
        for(int i=0;i<n;i++) make(i);
        for(int i=0;i<n;i++){
            if(leftChild[i]==-1) continue;
            if(parent[leftChild[i]]!=-1) return false;
            parent[leftChild[i]] = i;
            Union(i,leftChild[i]);
        }
        for(int i=0;i<n;i++){
            if(rightChild[i]==-1) continue;
            if(parent[rightChild[i]]!=-1) return false; 
            parent[rightChild[i]] = i;
            Union(i,rightChild[i]);
        }
        int countParent = count(parent.begin(),parent.end(),-1);
        int connectedComponents = 0;
        for(int i=0;i<n;i++){
            if(find(i)==i) connectedComponents++;
        }
        if(countParent==1 && connectedComponents==1) return true;
        else return false;
    }
};

int main(){
    
    return 0;
}