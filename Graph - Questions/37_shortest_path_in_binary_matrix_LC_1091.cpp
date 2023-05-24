#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-path-in-binary-matrix/ 

// Dijkstra's Algorithm - with queue<> and not pq<>

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        vector<vector<int>> dp(n, vector<int> (n, 100000));
        // < count, i, j >
        queue<vector<int>> q;                                 
        q.push({0, 0, 0});
        while(!q.empty()) {
            vector<int> v = q.front(); q.pop();
            int i = v[1], j = v[2], count = v[0];
            if(i < 0 || j < 0 || i == n || j == n || count >= dp[i][j] || grid[i][j] == 1) {
                continue;
            }
            if(i == n - 1 && j == n - 1) {
                return count + 1;
            }
            dp[i][j] = count;
            q.push({count + 1, i, j + 1});
            q.push({count + 1, i, j - 1});
            q.push({count + 1, i + 1, j});
            q.push({count + 1, i - 1, j});
            q.push({count + 1, i + 1, j + 1});
            q.push({count + 1, i + 1, j - 1});
            q.push({count + 1, i - 1, j + 1});
            q.push({count + 1, i - 1, j - 1});
        }
        return -1;
    }
};