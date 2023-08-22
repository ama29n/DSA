#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-area-of-island/ 

class Solution {
public:
    int n, m;
    vector<int> dir{ 0, 1, 0, -1, 0 };
    int dfs(int i, int j, vector<vector<int>> &grid) {
        if(i < 0 || j < 0 || i == n || j == m || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        int ans = 1;
        for(int d = 0; d < 4; d++) {
            ans += dfs(i + dir[d], j + dir[d + 1], grid);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        n = grid.size(); m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int x = dfs(i, j, grid);
                    ans = max(ans, x);
                }
            }
        }
        return ans;
    }
};