#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class Help {
        public:
        int i, j, k, d;
        Help(int i, int j, int k, int d) {
            this->i = i;
            this->j = j;
            this->k = k;
            this->d = d;
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
            int i = h.i, j = h.j, k = h.k, d = h.d;
            
            if(i < 0 || j < 0 || i == m || j == n)
                continue;
            if(i == m - 1 && j == n - 1) {
                ans = min(ans, d);
            }
            if(grid[i][j] == 1) {
                if(k < 1)
                    continue;
                k--;
            }
            if(vis[i][j] != -1 && vis[i][j] >= k)
                continue;
            vis[i][j] = k;
            
            Help up(i - 1, j, k, d + 1); q.push(up);
            Help down(i + 1, j, k, d + 1); q.push(down);
            Help left(i, j - 1, k, d + 1); q.push(left);
            Help right(i, j + 1, k, d + 1);
            q.push(right);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};