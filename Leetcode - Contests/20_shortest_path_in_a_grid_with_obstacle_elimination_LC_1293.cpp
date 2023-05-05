#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

class Solution {
public:
    class Node {
    public:
        int x, y, k, steps;
        Node(int _x, int _y, int _k, int _steps) {
            x = _x; y = _y; k = _k; steps = _steps;
        }
    };
    int shortestPath(vector<vector<int>> &grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, -1));
        queue<Node> q;
        Node base(0, 0, k, 0);
        q.push(base);
        int ans = INT_MAX;
        while(!q.empty()) {
            int x = q.front().x, y = q.front().y, k = q.front().k;
            int steps = q.front().steps;
            q.pop();
            if(x == m || y == n || x < 0 || y < 0) {
                continue;
            }
            if(x == m - 1 && y == n - 1) {
                ans = min(ans, steps);
                continue;
            }
            if(grid[x][y] == 1) {
                if(k == 0) continue;
                k--;
            }
            if(vis[x][y] != -1 && vis[x][y] >= k) {
                continue;
            }
            vis[x][y] = k;
            Node l(x - 1, y, k, steps + 1);
            Node r(x + 1, y, k, steps + 1);
            Node u(x, y + 1, k, steps + 1);
            Node d(x, y - 1, k, steps + 1);
            q.push(l); q.push(r); q.push(u); q.push(d);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};