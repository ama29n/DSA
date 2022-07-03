#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool check(vector<vector<char>> &board, int r, int c, char num){
        
        int row = r - r % 3, col = c - c % 3;
        
        for(int i = 0; i < 9; i++)
            if(board[i][c] == num || board[r][i] == num)
                return false;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(board[i + row][j + col] == num)
                    return false;
        return true;
    }
    
    bool fill(vector<vector<char>> &board, int r, int c){
        if(r == 9){
            return true;
        }
        if(c == 9) return fill(board, r+1, 0);
        
        if(board[r][c] != '.') return fill(board, r, c+1);
        
        for(char i = '1'; i <= '9'; i++){
            
            if(check(board, r, c, i))
            {
                board[r][c] = i;
                if(fill(board, r, c+1)) return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        fill(board, 0, 0);
    }
};