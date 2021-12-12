#include <bits/stdc++.h>
using namespace std;

// We are using normal 0 base index in this code so we have to increment row and col in reecursive calls
void obstaclemaze(string ans , int row , int col , bool maze[][3]){
    if(row == sizeof(maze[0]) -1 && col == sizeof(maze[0])-1){
        cout<<ans<<endl;
        return ;
    }
    if(maze[row][col]==false) return ;
    if(row<sizeof(maze) -1){
        obstaclemaze(ans + 'D',row+1,col,maze);
    }
    if(col<sizeof(maze[0]) -1){
        obstaclemaze(ans + 'R',row,col+1,maze);
    }
}

int main(){
    bool board[][3] = {
        {true,true,true},
        {true,false,true},
        {true,true,true},
    };
    obstaclemaze("",0,0,board);
    return 0;
}