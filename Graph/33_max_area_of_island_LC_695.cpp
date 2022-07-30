#include <bits/stdc++.h>
using namespace std;

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