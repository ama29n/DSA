#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-path-sum/ 

// Memoization
class Solution {
public:
    int calculate(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(row == 0 && col == 0) {
            return grid[0][0];
        }
        if(row < 0 || col < 0) {
            return INT_MAX;
        }
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        int left = calculate(row, col - 1, grid, dp);
        int up = calculate(row - 1, col, grid, dp);
        return dp[row][col] = min(left, up) + grid[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> dp(row, vector<int> (col, -1));
        return calculate(row - 1, col - 1, grid, dp);
    }
};

// Custom Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        memset(dp, 0, sizeof dp);
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n - 1) {
                    dp[i][j] = grid[i][j];
                } else {
                    int d = i + 1 < m ? dp[i + 1][j] : INT_MAX;
                    int r = j + 1 < n ? dp[i][j + 1] : INT_MAX;
                    dp[i][j] = min(r, d) + grid[i][j];
                }
            }
        }
        return dp[0][0];
    }
};
