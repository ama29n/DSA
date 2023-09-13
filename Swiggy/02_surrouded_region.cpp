#include <bits/stdc++.h> 
using namespace std;

// https://leetcode.com/problems/surrounded-regions/description/

class Solution {
public:
    int n, m;
    vector<int> dir { 0, 1, 0, -1, 0 };
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<char>> &board) {
        if(i < 0 || j < 0 || i == n || j == m || board[i][j] == 'X') {
            return;
        }
        board[i][j] = 'X'; grid[i][j] = 'O';
        for(int d = 0; d < 4; d++) {
            dfs(i + dir[d], j + dir[d + 1], grid, board);
        }
    }
    void solve(vector<vector<char>> &board) {
        n = board.size(), m = board[0].size();
        vector<vector<char>> grid(n, vector<char> (m, 'X'));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    dfs(i, j, grid, board);
                }
            }
        }
        board = grid;
    }
};