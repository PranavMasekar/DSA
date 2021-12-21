#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<bool>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j])
            {
                cout << "K" << ' ';
            }
            else
            {
                cout << "X" << ' ';
            }
        }
        cout << endl;
    }
}

bool isValid(vector<vector<bool>> board, int row, int col)
{
    if (row >= 0 && row < board.size() && col >= 0 && col < board.size())
    {
        return true;
    }
    return false;
}

bool isSafe(vector<vector<bool>> board, int row, int col)
{
    if (isValid(board, row-2, col-1))
    {
        if (board[row - 2][col - 1]){
            return false;
        }
    }
    if (isValid(board, row-2, col+1))
    {
        if (board[row - 2][col + 1]){
            return false;
        }
    }
    if (isValid(board, row-1, col-2))
    {
        if (board[row - 1][col - 2]){
            return false;
        }
    }
    if (isValid(board, row-1, col+2))
    {
        if (board[row - 1][col + 2]){
            return false;
        }
    }
    return true;
}

void nknightscount(vector<vector<bool>> board, int row, int col, int targets)
{
    if (targets == 0)
    {
        display(board);
        cout << endl;
        return;
    }
    if (row == board.size()  && col == board.size())
    {
        return;
    }
    if (col == board.size())
    {
        nknightscount(board, row + 1, 0, targets);
        return;
    }
    if (isSafe(board, row, col))
    {
        board[row][col] = true;
        nknightscount(board, row, col + 1,targets-1);
        board[row][col] = false;
    }
    nknightscount(board, row, col + 1, targets);
}
int main()
{
    vector<vector<bool>> board = {
        {false, false, false, false},
        {false, false, false, false},
        {false, false, false, false},
        {false, false, false, false},
    };
    nknightscount(board, 0, 0, 4);
    return 0;
}