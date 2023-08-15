#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/ 

class Solution {
private:
    int m, n;
    int dp[200 + 1][200 + 1];
    int dfs(int i, int j, int prev, vector<vector<int>> &grid) {
        if(i == m || j == n || i < 0 || j < 0 || grid[i][j] <= prev) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int u = dfs(i - 1, j, grid[i][j], grid);
        int d = dfs(i + 1, j, grid[i][j], grid);
        int l = dfs(i, j - 1, grid[i][j], grid);
        int r = dfs(i, j + 1, grid[i][j], grid);
        return dp[i][j] = max({ u, d, l, r }) + 1;
    }   
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        m = matrix.size(); n = matrix[0].size();
        memset(dp, -1, sizeof dp);
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j, -1, matrix));
            }
        }
        return ans;
    }
};
