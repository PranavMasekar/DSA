#include <bits/stdc++.h>
using namespace std;
bool print = false;
void display(vector<vector<int>> board)
{
    for(vector<int> row : board){
        for(int num : row){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<int>> board , int row, int col , int num){
    // Checking row 
    for(int i=0;i<board.size();i++){
        if(board[row][col]==num) return false;
    }
    // Checking column 
    for(vector<int> x : board){
        if(x[col]==num) return false;
    }
    // Checking for each 3X3 matrix
    int squrt = (int) sqrt(board.size());
    int rowstart = row - (row % squrt);
    int colstart = col - (col % squrt);
    for(int i=rowstart;i<rowstart+squrt;i++){
        for(int j = colstart;j<colstart+squrt;j++){
            if(board[i][j]==num) return false;
        }
    }
    return true;
}

bool sudokuSolve(vector<vector<int>> board){
    int n = board.size();
    int row = -1;
    int col = -1;
    bool empty = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==0){
                row = i;
                col = j;
                empty = false;
                break;
            }
        }
        // if I found an empty element in row then break out of the loop
        if(empty==false) break;
    }
    if(empty) return true;

    // Backtrack Now
    for(int num = 1;num<10;num++){
        if(isSafe(board,row,col,num)){
            board[row][col] = num;
            // I place one element in sudoku and check for other places 
            if(sudokuSolve(board)) {
                if(print==false) {
                    display(board);
                    print = true;
                    }
                return true;
            }
            else{
                 board[row][col] = 0;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> board = {
         {3, 0, 6, 5, 0, 8, 4, 0, 0},
         {5, 2, 0, 0, 0, 0, 0, 0, 0},
         {0, 8, 7, 0, 0, 0, 0, 3, 1},
         {0, 0, 3, 0, 1, 0, 0, 8, 0},
         {9, 0, 0, 8, 6, 3, 0, 0, 5},
         {0, 5, 0, 0, 9, 0, 6, 0, 0},
         {1, 3, 0, 0, 0, 0, 2, 5, 0},
         {0, 0, 0, 0, 0, 0, 0, 7, 4},
         {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    if(sudokuSolve(board)){
    }
    else cout<<"Cant solve the sodoku";
    return 0;
}