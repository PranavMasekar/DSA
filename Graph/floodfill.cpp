#include<bits/stdc++.h>
using namespace std;

class Solution {
    void DFS(int i, int j, int initialColor, int newColor,vector<vector<int>>& image){
        int n = image.size();
        int m = image[0].size();
        // Index underflow and overflow
        if(i<0 || j<0) return;
        if(i>=n || j>=m) return;
        // Adjacent should have same color
        if(image[i][j]!=initialColor) return;

        image[i][j] = newColor;

        DFS(i-1,j,initialColor,newColor,image);
        DFS(i+1,j,initialColor,newColor,image);
        DFS(i,j-1,initialColor,newColor,image);
        DFS(i,j+1,initialColor,newColor,image);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialColor = image[sr][sc];
        if(initialColor!=newColor) DFS(sr,sc,initialColor,newColor,image);
        return image;
    }
};

int main(){
     
    return 0;
} 