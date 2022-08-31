#include <bits/stdc++.h>
using namespace std;

// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally 
// (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

class Solution {
public:
    int makeVisited(int i, int j, vector<vector<int>> &grid, int m, int n) {
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0)
            return 0;
        
        int gridVal = grid[i][j];
        grid[i][j] = 0;
        
        int u = makeVisited(i + 1, j, grid, m, n);
        int d = makeVisited(i - 1, j, grid, m, n);
        int r = makeVisited(i, j + 1, grid, m, n);
        int l = makeVisited(i, j - 1, grid, m, n);
        
        return l + r + u + d + gridVal;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0)
                    ans = max(ans, makeVisited(i, j, grid, m, n));
            }
        }
        return ans;
    }
};