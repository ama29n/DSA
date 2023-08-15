#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths-ii/

// Memoization
class Solution {
public:
    int path(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp) {
        if(row == 0 && col == 0) {
            return 1;
        }
        if(row < 0 || col < 0) {
            return 0;
        }
        if(obstacleGrid[row][col] == 1) {
            return 0;
        }
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        int left = path(row, col - 1, obstacleGrid, dp);
        int up = path(row - 1, col, obstacleGrid, dp);
        return dp[row][col] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int> (col, -1));
        return path(row - 1, col - 1, obstacleGrid, dp);
    }
};

// Tabulation
class Solution {
private:
    typedef long long ll;
public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[m - 1][n - 1] == 1) {
            return 0;
        }
        vector<vector<ll>> dp(m, vector<ll> (n, 0));
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n - 1) {
                    dp[i][j] = 1;
                } else if(grid[i][j] == 1) {
                    dp[i][j] = 0; 
                } else {
                    ll d = i + 1 < m ? dp[i + 1][j] : 0;
                    ll r = j + 1 < n ? dp[i][j + 1] : 0;
                    dp[i][j] = d + r;
                }
            }
        }
        return dp[0][0];
    }
};
