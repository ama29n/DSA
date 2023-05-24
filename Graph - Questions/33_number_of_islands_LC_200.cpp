#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-islands/ 

// Dfs Approach
class Solution {
public:
    int n, m;
    vector<int> dir { 0, 1, 0, -1, 0 };
    void dfs(int i, int j, vector<vector<char>> &grid) {
        if(i < 0 || j < 0 || i == n || j == m || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        for(int d = 0; d < 4; d++) {
            dfs(i + dir[d], j + dir[d + 1], grid);
        }
    }
    int numIslands(vector<vector<char>> &grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};

// Bfs
class Solution {
public:
    vector<int> dir { 0, 1, 0, -1, 0 };
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()) {
                        pair<int, int> p = q.front(); q.pop();
                        int x = p.first, y = p.second;
                        if(x < 0 || y < 0 || x == n || y == m || grid[x][y] == '0') {
                            continue;
                        }
                        grid[x][y] = '0';
                        for(int d = 0; d < 4; d++) {
                            q.push({x + dir[d], y + dir[d + 1]});
                        }
                    }
                }
            }
        }
        return ans;
    }
};
