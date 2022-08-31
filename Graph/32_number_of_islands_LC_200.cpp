#include <bits/stdc++.h>
using namespace std;

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
// You may assume all four edges of the grid are all surrounded by water.

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

// Bfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(q.size()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        if(x < 0 || y < 0 || x == m || y == n || grid[x][y] == '0')
                            continue;
                        grid[x][y] = '0';
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
