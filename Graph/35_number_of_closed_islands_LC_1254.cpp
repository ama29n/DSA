#include <bits/stdc++.h>
using namespace std;

// Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 
// 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

// Return the number of closed islands.

class Solution {
public:

    // We will make all the islands of 0s touching border 1
    // Then calculate the number of remaining islands

    void makeVisited(int i, int j, vector<vector<int>> &grid, int m, int n) {
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 1)
            return;
        grid[i][j] = 1;
        makeVisited(i + 1, j, grid, m, n);
        makeVisited(i - 1, j, grid, m, n);
        makeVisited(i, j + 1, grid, m, n);
        makeVisited(i, j - 1, grid, m, n);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < m; i++)
            if(grid[i][0] == 0)
                makeVisited(i, 0, grid, m , n);
        for(int i = 0; i < m; i++)
            if(grid[i][n - 1] == 0)
                makeVisited(i, n - 1, grid, m, n);
        for(int j = 0; j < n; j++)
            if(grid[0][j] == 0)
                makeVisited(0, j, grid, m, n);
        for(int j = 0; j < n; j++)
            if(grid[m - 1][j] == 0)
                makeVisited(m - 1, j, grid, m, n);
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    ans++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(q.size()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        if(x < 0 || y < 0 || x == m || y == n || grid[x][y] == 1)
                            continue;
                        grid[x][y] = 1;
                        q.push({x + 1, y});
                        q.push({x - 1, y});
                        q.push({x, y + 1});
                        q.push({x, y - 1});
                    }
                }
            }
        }
        return ans;
    }
};