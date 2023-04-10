#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> validBoards;
    bool validPos(vector<string>& board, int r, int c) {
        // Column Check
        for(int i = r - 1; i >= 0; i--)
            if(board[i][c] == 'Q')
                return false;
        // Upper Left Diagonal
        for(int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
            if(board[i][j] == 'Q')
                return false;
        // Upper Right Diagonal
        for(int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++)
            if(board[i][j] == 'Q')
                return false;
        return true;
    }
    void dfs(vector<string>& board, int row) {
        if(row == board.size()) {
            validBoards.push_back(board);
            return;
        }
        for(int col = 0; col < board[row].size(); col++) {
            if(validPos(board, row, col)) {
                board[row][col] = 'Q';
                dfs(board, row + 1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(board, 0);
        return validBoards;
    }
};