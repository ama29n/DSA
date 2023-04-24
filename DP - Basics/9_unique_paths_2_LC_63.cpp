#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int path(int row, int col, vector<vector<int>>& obstacleGrid) {
        if(row == 0 && col == 0) {
            return 1;
        }
        if(row < 0 || col < 0) {
            return 0;
        }
        if(obstacleGrid[row][col] == 1) {
            return 0;
        }
        int left = path(row, col - 1, obstacleGrid);
        int up = path(row - 1, col, obstacleGrid);
        return left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        return path(row - 1, col - 1, obstacleGrid);
    }
};

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