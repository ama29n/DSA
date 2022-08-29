#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<char>> grid(m, vector<char> (n, 'X'));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    if(board[i][j] == 'O') {
                        queue<pair<int, int>> q;
                        q.push({i, j});
                        while(q.size()) {
                            int row = q.front().first, col = q.front().second;
                            q.pop();
                            if(row == m || col == n || row < 0 || col < 0)
                                continue;
                            if(board[row][col] == 'X')
                                continue;
                            grid[row][col] = 'O';
                            board[row][col] = 'X';
                            q.push({row + 1, col});
                            q.push({row - 1, col});
                            q.push({row, col + 1});
                            q.push({row, col - 1});
                        }
                    }
                }
            }
        }
        board = grid;
    }
};