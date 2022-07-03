#include<bits/stdc++.h>
using namespace std;

int path(int row, int col, vector<vector<int>>& obstacleGrid) {
    if(row == 0 && col == 0)
        return 1;
    if(row < 0 || col < 0)
        return 0;
    if(obstacleGrid[row][col] == 1)
        return 0;
    int left = path(row, col - 1, obstacleGrid);
    int up = path(row - 1, col, obstacleGrid);
    return left + up;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    return path(row - 1, col - 1, obstacleGrid);
}


// Fixed ending and starting point



// Memoization

int path(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp) {
    if(row == 0 && col == 0)
        return 1;
    if(row < 0 || col < 0)
        return 0;
    if(obstacleGrid[row][col] == 1)
        return 0;
    if(dp[row][col] != -1)
        return dp[row][col];
    
    int left = path(row, col - 1, obstacleGrid, dp);
    int up = path(row - 1, col, obstacleGrid, dp);
    return dp[row][col] = left + up;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0] == 1) return 0;
    
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    vector<vector<int>> dp(row, vector<int> (col, -1));
    return path(row - 1, col - 1, obstacleGrid, dp);
}








int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0] == 1) return 0;
    
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    vector<vector<int>> dp(row, vector<int> (col, -1));
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i == 0 && j == 0) dp[i][j] = 1;
            else if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
            else {
                int left = 0, up = 0;
                if(i > 0) up = dp[i - 1][j];
                if(j > 0) left = dp[i][j - 1];
                dp[i][j] = left + up;
            }
        }
    }
    return dp[row - 1][col - 1];
}








int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0] == 1) return 0;
    
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    vector<int> prevRow(col, 0);
    
    for(int i = 0; i < row; i++) {
        vector<int> temp(col, 0);
        for(int j = 0; j < col; j++) {
            if(i == 0 && j == 0) temp[j] = 1;
            else if(obstacleGrid[i][j] == 1) temp[j] = 0;
            else {
                int left = 0, up = 0;
                if(i > 0) up = prevRow[j];
                if(j > 0) left = temp[j - 1];
                temp[j] = left + up;
            }
        }
        prevRow = temp;
    }
    return prevRow[col - 1];
}



// Best Solution
class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;
        if(obstacleGrid[m][n] == 1) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int up = solve(m - 1, n, obstacleGrid, dp);
        int left = solve(m, n - 1, obstacleGrid, dp);
        return dp[m][n] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        
        dp[1][1] = 1;
        for(int i = 0; i <= m; i++) dp[i][0] = 0;
        for(int j = 0; j <= n; j++) dp[0][j] = 0;
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(obstacleGrid[i - 1][j - 1] == 1) dp[i][j] = 0;
                else {
                    dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};