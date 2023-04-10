#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void cal(int i, int j, vector<vector<int>> &grid, string str, vector<string>& ans) {
            int n = grid.size();
            if(i < 0 || j < 0 || i == n || j == n || grid[i][j] == 0) 
                return;
            if(i == n - 1 && j == n - 1) {
                ans.push_back(str);
            }
            grid[i][j] = 0;
            cal(i - 1, j, grid, str + "U", ans);
            cal(i + 1, j, grid, str + "D", ans);
            cal(i, j - 1, grid, str + "L", ans);
            cal(i, j + 1, grid, str + "R", ans);
            grid[i][j] = 1;
        }
        vector<string> findPath(vector<vector<int>> &grid, int n) {
            if(grid[0][0] == 0 || grid[n - 1][n - 1] == 0)
                return {};
            vector<string> ans;
            cal(0, 0, grid, "", ans);
            return ans;
        }
};