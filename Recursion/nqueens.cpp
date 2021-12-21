#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<bool>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if(board[i][j]){
                cout << "Q"<< ' ';
            }
            else{
                cout << "X"<< ' ';
            }
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<bool>>board,int row,int col){
    // Check Vertically if queen is being cancelled 
    for(int i=0;i<row;i++){
        if(board[i][col]){
            return false;
        }
    }
    // Check left Diagonally if queen is being cancelled
    int maxleft = min(row,col);
    for(int i=1;i<=maxleft;i++){
        if(board[row-i][col-i]){
            return false;
        }
    }
    // Check right Diagonally if queen is being cancelled
    int x = board.size()-1-col;
    int maxright = min(row,x);
    for(int i=1;i<=maxright;i++){
        if(board[row-i][col+i]){
            return false;
        }
    }
    return true;

}

int nqueenscount(vector<vector<bool>> board, int row)
{
    if (row == board.size())
    {
        display(board);
        cout<<endl;
        return 1;
    }
    int count = 0;
    // Placing the Queens on the board
    // Checking for every row and column that can is it possible to make a combination of N-Queens
    for(int col=0;col<board.size();col++){
        // Place the queen if it is safe
        if(isSafe(board,row,col)){
            board[row][col] = true;
            count += nqueenscount(board,row+1);
            board[row][col] = false;
        }
    }
    return count;
}

int main()
{
    vector<vector<bool>> board = {
        {false,false,false,false},
        {false,false,false,false},
        {false,false,false,false},
        {false,false,false,false},
    };
    cout<<nqueenscount(board,0);
    return 0;
}