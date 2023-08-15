#include<bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998  

// -1E4 <= matrix[i][j] <= 1E4 

int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int m, int n) {
    if(i == m - 1) {
        return grid[i][j];
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = INT_MIN;
    for(int c = j - 1; c <= j + 1; c++) {
        if(c < 0 || c == n) {
            continue;
        }
        ans = max(ans, dfs(i + 1, c, grid, dp, m, n));
    }
    return dp[i][j] = ans + grid[i][j];
}
int getMaxPathSum(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int> (n, -1));
    int ans = INT_MIN;
    for(int j = 0; j < n; j++) {
        ans = max(ans, dfs(0, j, matrix, dp, m, n));
    }
    return ans;
}
