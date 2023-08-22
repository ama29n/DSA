#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-enclaves/ 

class Solution {
public:
    int n, m;
    vector<int> dir { 0, 1, 0, -1, 0 };
    void dfs(int i, int j, vector<vector<int>> &grid) {
        if(i < 0 || j < 0 || i == n || j == m || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        for(int d = 0; d < 4; d++) {
            dfs(i + dir[d], j + dir[d + 1], grid);
        }
    }
    int numEnclaves(vector<vector<int>> &grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    dfs(i, j, grid);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};