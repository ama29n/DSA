#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

class Solution {
public:
    class Help {
        public:
        int i, j, k, steps;
        Help(int i, int j, int k, int steps) {
            this->i = i; this->j = j; this->k = k; this->steps = steps;
        }
    };
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, -1));
        int ans = INT_MAX;
        Help h(0, 0, k, 0);
        queue<Help> q;
        q.push(h);
        while(q.size()) {
            Help h = q.front();
            q.pop();
            int i = h.i, j = h.j, k = h.k, steps = h.steps;
            if(i < 0 || j < 0 || i == m || j == n)
                continue;
            if(i == m - 1 && j == n - 1) {
                ans = min(ans, steps);
                continue;
            }
            if(grid[i][j] == 1) {
                if(k < 1)
                    continue;
                k--;
            }
            if(vis[i][j] != -1 && vis[i][j] >= k)
                continue;
            vis[i][j] = k;
            Help u(i - 1, j, k, steps + 1); q.push(u);
            Help d(i + 1, j, k, steps + 1); q.push(d);
            Help l(i, j - 1, k, steps + 1); q.push(l);
            Help r(i, j + 1, k, steps + 1); q.push(r);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};