#include<bits/stdc++.h>
using namespace std;

// Fixed ending and starting point


int calculate(int row, int col, vector<vector<int>> &grid) {
    if(row == 0 && col == 0) 
        return grid[0][0];
    if(row < 0 || col < 0)
        return 101;
    int left = calculate(row, col - 1, grid) + grid[row][col];
    int up = calculate(row - 1, col, grid) + grid[row][col];
    return min(left, up);
}

int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    return calculate(row - 1, col - 1, grid);
}








// Memoization
int calculate(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if(row == 0 && col == 0) 
        return grid[0][0];
    if(row < 0 || col < 0)
        return INT_MAX;
    if(dp[row][col] != -1)
        return dp[row][col];
    
    int left = calculate(row, col - 1, grid, dp);
    int up = calculate(row - 1, col, grid, dp);
    return dp[row][col] = min(left, up) + grid[row][col];
}

int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dp(row, vector<int> (col, -1));
    return calculate(row - 1, col - 1, grid, dp);
}








// Tabulation

// This solution is derived from memoization solution
int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    vector<vector<int>> dp(row, vector<int> (col, -1));
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i == 0 && j == 0) { 
                dp[i][j] = grid[i][j];
            }
            else {
                int left = INT_MAX, up = INT_MAX;
                if(i > 0) up = min(up, dp[i - 1][j]);
                if(j > 0) left = min(left, dp[i][j - 1]);
                
                dp[i][j] = min(up, left) + grid[i][j];
            }
        }
    }
    return dp[row - 1][col - 1];
}

// This solution is generic in terms of the idea that we start from the bottom right corner and we 
// come at the top left corner making the smallest possible path
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n - 1) {
                    dp[i][j] = grid[i][j];
                } else {
                    int down = INT_MAX, right = INT_MAX;
                    if(i < m - 1)
                        down = dp[i + 1][j];
                    if(j < n - 1)
                        right = dp[i][j + 1];
                    dp[i][j] = min(down, right) + grid[i][j];
                }
            }
        }
        return dp[0][0];
    }
};
