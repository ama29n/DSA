#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/cherry-pickup-ii 

class Solution {
private:
    int m, n;
    int dp[80][80][80];
    int dfs(int r, int c1, int c2, vector<vector<int>> &grid) {
        if(c1 < 0 || c2 < 0 || c1 == n || c2 == n) {
            return 0;
        }
        if(r == m) {
            return 0;
        }
        if(dp[r][c1][c2] != -1) {
            return dp[r][c1][c2];
        }
        // When at same column, take cherries only once
        int x = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        int y = 0;
        for(int i = c1 - 1; i <= c1 + 1; i++) {
            for(int j = c2 - 1; j <= c2 + 1; j++) {
                y = max(y, dfs(r + 1, i, j, grid));
            }
        }
        return dp[r][c1][c2] = x + y;
    }
public:
    int cherryPickup(vector<vector<int>> &grid) {
        m = grid.size(); n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, n - 1, grid);
    }
};
