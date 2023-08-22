#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths/ 

// Recusrion
class Solution {
public:
    int paths(int row, int col) {
        if(row == 0 && col == 0) {
            return 1;
        }
        if(row < 0 || col < 0) {
            return 0;
        }
        int left = paths(row, col - 1);
        int up = paths(row - 1, col);
        return left + up;
    }
    int uniquePaths(int m, int n) {
        return paths(m - 1, n - 1);
    }
};
// Time - 2 raised to power (m * n)
// space - o (m + n)

// Memoization 
class Solution {
private:
    int m, n;
    int dp[102][102];
    int dfs(int i, int j) {
        if(i == m || j == n) {
            return 0;
        }   
        if(i == m - 1 && j == n - 1) {
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int d = dfs(i + 1, j);
        int r = dfs(i, j + 1);
        return dp[i][j] = d + r;
    }
public:
    int uniquePaths(int _m, int _n) {
        m = _m; n = _n;
        memset(dp, -1, sizeof dp);
        return dfs(0, 0);
    }
};
// Time - O(m * n) 
// Space - O((m - 1) + (n - 1)) + dp[m][n]

// Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n]; memset(dp, 0, sizeof dp);
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n - 1) {
                    dp[i][j] = 1; continue;
                }
                int r = j + 1 < n ? dp[i][j + 1] : 0;
                int d = i + 1 < m ? dp[i + 1][j] : 0;
                dp[i][j] = r + d;
            }
        }
        return dp[0][0];
    }
};

// Space Optimization
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);        
        for(int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    temp[j] = 1;
                } else {
                    int up = 0, left = 0;
                    if(i > 0) {
                        up = dp[j];
                    }
                    if(j > 0) {
                        left = temp[j - 1];
                    }
                    temp[j] = up + left;
                }
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};
