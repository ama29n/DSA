#include<bits/stdc++.h>
using namespace std;


// Here dp[i][j] will represent the minimum path from grid[i][j] to grid[m - 1][n - 1]
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n - 1) {
                    dp[i][j] = grid[i][j];
                } else {
                    int down = INT_MAX, right = INT_MAX;
                    if(i < m - 1)
                        down = dp[i + 1][j];
                    if(j < n - 1)
                        right = dp[i][j + 1];
                    dp[i][j] = min(down, right) + grid[i][j];
                }
            }
        }
        return dp[0][0];
    }
};