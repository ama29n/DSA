#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-increasing-paths-in-a-grid 

class Solution {
private:
    int m, n;
    const int MOD = 1E9 + 7;
    int dp[1001][1001];
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
        return dp[i][j] = (u + d + l + r + 1) % MOD;
    }
public:
    int countPaths(vector<vector<int>> &grid) {
        m = grid.size(); n = grid[0].size();
        memset(dp, -1, sizeof dp);
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = (ans + dfs(i, j, -1, grid)) % MOD;
            }
        }
        return ans;
    }
};