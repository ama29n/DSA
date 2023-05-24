#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-bridge/

// Turn one island into island of 2s, then keep on increasing adjacent cells until 1s island is found

class Solution {
public:
    int n;
    vector<int> dir{0, 1, 0, -1, 0};
    queue<pair<int, int>> q;
    void dfs(int i, int j, vector<vector<int>> &grid) {
        if(i < 0 || j < 0 || i == n || j == n || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = 2;
        q.push({i, j});
        for(int idx = 0; idx < 4; idx++) {
            dfs(i + dir[idx], j + dir[idx + 1], grid);
        }
    }
    int shortestBridge(vector<vector<int>> &grid) {
        n = grid.size();
        int I, J;
        for(int i = 0; i < n; i++) {
            int flag = false;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) { I = i; J = j; flag = true; break; }
            }
            if(flag) break;
        }
        dfs(I, J, grid);
        vector<vector<int>> vis(n, vector<int> (n, 0));
        int ans = INT_MAX;
        while(!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            int i = p.first, j = p.second;
            for(int idx = 0; idx < 4; idx++) {
                int x = i + dir[idx], y = j + dir[idx + 1];
                if(x < 0 || y < 0 || x == n || y == n) continue;
                if(grid[x][y] == 1) return grid[i][j] - 2;
                if(grid[x][y] == 0) {
                    grid[x][y] = grid[i][j] + 1;
                    q.push({x, y});
                }
            } 
        }
        return ans;
    }
};