#include <bits/stdc++.h>
using namespace std;

// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the 
// boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.



// Dfs solution
class Solution {
public:
    void makeVisited(int i, int j, vector<vector<int>> &grid, int m, int n) {
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        makeVisited(i + 1, j, grid, m, n);
        makeVisited(i - 1, j, grid, m, n);
        makeVisited(i, j + 1, grid, m, n);
        makeVisited(i, j - 1, grid, m, n);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < m; i++)
            if(grid[i][0] == 1)
                makeVisited(i, 0, grid, m , n);
        for(int i = 0; i < m; i++)
            if(grid[i][n - 1] == 1)
                makeVisited(i, n - 1, grid, m, n);
        for(int j = 0; j < n; j++)
            if(grid[0][j] == 1)
                makeVisited(0, j, grid, m, n);
        for(int j = 0; j < n; j++)
            if(grid[m - 1][j] == 1)
                makeVisited(m - 1, j, grid, m, n);
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1)
                    ans += 1;
        return ans;
    }
}; 

// Bfs solution
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans += grid[i][j];
                if(i * j == 0 || i == m - 1 || j == n - 1)
                    q.push({i, j});
            }
        }
        while(q.size()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if(i < 0 || j < 0 || i == m || j == n || grid[i][j] == 0)
                continue;
            grid[i][j] = 0;
            ans--;
            q.push({i + 1, j});
            q.push({i - 1, j});
            q.push({i, j + 1});
            q.push({i, j - 1});
        }
        return ans;
    }
};