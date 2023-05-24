#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/pacific-atlantic-water-flow/ 

// DFS
class Solution {
public:
    void dfs(int i, int j, int prev, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;
        
        if(visited[i][j] == true)
            return;
        
        if(grid[i][j] < prev)
            return;
        
        visited[i][j] = true;
        
        dfs(i + 1, j, grid[i][j], grid, visited);
        dfs(i - 1, j, grid[i][j], grid, visited);
        dfs(i, j + 1, grid[i][j], grid, visited);
        dfs(i, j - 1, grid[i][j], grid, visited);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool> (n, false));
        vector<vector<bool>> atlantic(m, vector<bool> (n, false));
        
        // Start from borders and make cells visited if they can reach their respecitve oceans
        
        for(int i = 0; i < m; i++) {
            dfs(i, 0, -1, grid, pacific);
            dfs(i, n - 1, -1, grid, atlantic);
        }
        
        for(int j = 0; j < n; j++) {
            dfs(0, j, -1, grid, pacific);
            dfs(m - 1, j, -1, grid, atlantic);
        }
        
        // Cells which can reach both oceans will be the part of final answer
        
        vector<vector<int>> pairs;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(pacific[i][j] && atlantic[i][j])
                    pairs.push_back({i, j});
        
        return pairs;
    }
};