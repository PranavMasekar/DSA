#include <bits/stdc++.h>
using namespace std;

void mazeallpaths(string ans , int row , int col , vector<vector<bool>> maze){
    if(row == maze.size()-1 && col == maze[0].size()-1){
        cout<<ans<<endl;
        return;
    }
    if(maze[row][col]==false) return ;
    maze[row][col] = false;
    if(row<maze.size()-1){
        mazeallpaths(ans + 'D',row+1,col,maze);
    }
    if(col<maze[0].size()-1){
        mazeallpaths(ans + 'R',row,col+1,maze);
    }
    // It cant go out of bound
    if(row>0){
        mazeallpaths(ans + 'U' , row-1, col ,maze);
    }
    // It cant go out of bound
    if(col>0){
        mazeallpaths(ans + 'L' , row, col-1 ,maze);
    }
    // Backtracking Bolte 
    // Mark the cells which the function has visited as they were before 
    maze[row][col] = true;
}
void mazeallpathsprint(string ans , int row , int col , vector<vector<bool>> maze , vector<vector<int>> path , int step){
    if(row == maze.size()-1 && col == maze[0].size()-1){
        path[row][col] = step;
        for(int i=0;i<path.size();i++){
            for(int j = 0;j<path[i].size();j++){
                cout<<path[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<ans<<endl;
        return;
    }
    if(maze[row][col]==false) return ;
    maze[row][col] = false;
    path[row][col] = step;
    if(row<maze.size()-1){
        mazeallpathsprint(ans + 'D',row+1,col,maze,path,step + 1);
    }
    if(col<maze[0].size()-1){
        mazeallpathsprint(ans + 'R',row,col+1,maze,path,step + 1);
    }
    // It cant go out of bound
    if(row>0){
        mazeallpathsprint(ans + 'U' , row-1, col ,maze,path,step + 1);
    }
    // It cant go out of bound
    if(col>0){
        mazeallpathsprint(ans + 'L' , row, col-1 ,maze,path,step + 1);
    }
    // Backtracking Bolte 
    // Mark the cells which the function has visited as they were before 
    maze[row][col] = true;
     path[row][col] = 0;
}

int main(){
     vector<vector<bool>> board = {
        {true,true,true},
        {true,true,true},
        {true,true,true},
    };
    // mazeallpaths("",0,0,board);
      vector<vector<int>> path = {
        {0,0,0},
        {0,0,0},
        {0,0,0},
      };
    mazeallpathsprint("",0,0,board,path,1);  
    return 0;
}
