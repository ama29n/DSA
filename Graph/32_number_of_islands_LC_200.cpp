#include <bits/stdc++.h>
using namespace std;

// Dfs Approach
class Solution {
public:
    void makeVisited(int i, int j, vector<vector<char>> &grid, int m, int n) {
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        makeVisited(i + 1, j, grid, m, n);
        makeVisited(i - 1, j, grid, m, n);
        makeVisited(i, j + 1, grid, m, n);
        makeVisited(i, j - 1, grid, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    makeVisited(i, j, grid, m, n);
                }
            }
        }
        return ans;
    }
};
