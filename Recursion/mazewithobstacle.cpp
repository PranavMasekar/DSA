#include <bits/stdc++.h>
using namespace std;

// We are using normal 0 base index in this code so we have to increment row and col in reecursive calls
void obstaclemaze(string ans , int row , int col , vector<vector<bool>> maze){
    if(row == maze.size()-1 && col == maze[0].size()-1){
        cout<<ans<<endl;
        return;
    }
    if(maze[row][col]==false) return ;
     if(row<maze.size()-1){
        obstaclemaze(ans + 'D',row+1,col,maze);
    }
    if(col<maze[0].size()-1){
        obstaclemaze(ans + 'R',row,col+1,maze);
    }
}

int main(){
     vector<vector<bool>> board = {
        {true,true,true},
        {true,false,true},
        {true,true,true},
    };
    obstaclemaze("",0,0,board);
    return 0;
}