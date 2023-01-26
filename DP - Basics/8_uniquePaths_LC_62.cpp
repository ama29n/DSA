#include<bits/stdc++.h>
using namespace std;


// Fixed ending and starting point

int paths(int row, int col) {
    if(row == 0 && col == 0)
        return 1;
    if(row < 0) return 0;
    if(col < 0) return 0;
    
    int left = paths(row, col - 1);
    int up = paths(row - 1, col);
    
    return left + up;
}
    
int uniquePaths(int m, int n) {
    return paths(m - 1, n - 1);
}

// Time - 2 raised to power m*n
// space - o (m + n)





// Memoization 
int paths(int row, int col, vector<vector<int>> &dp) {
    if(row == 0 && col == 0)
        return 1;
    if(row < 0) return 0;
    if(col < 0) return 0;
    
    if(dp[row][col] != -1)
        return dp[row][col];
    
    int left = paths(row, col - 1, dp);
    int up = paths(row - 1, col, dp);
    
    return dp[row][col] = left + up;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int> (n, -1));
    return paths(m - 1, n - 1, dp);
}

// Time - O(m * n) 
// Space - O((m - 1) + (n - 1)) + dp[m][n]






// Tabulation 


// This solution is derived from memoization solution
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int> (n, -1));
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
            } else {
                int up = 0, left = 0;
                if(i > 0) up = dp[i - 1][j];
                if(j > 0) left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}

// This solution is generic in terms of the idea that we start from the bottom right corner and we 
// come at the top left corner by counting the number of ways
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n - 1) {
                    dp[i][j] = 1;
                } else {
                    int down = 0, right = 0;
                    if(i < m - 1)
                        down = dp[i + 1][j];
                    if(j < n - 1)
                        right = dp[i][j + 1];
                    dp[i][j] = down + right;
                }
            }
        }
        return dp[0][0];
    }
};


// Space Optimization

int uniquePaths(int m, int n) {
    vector<int> dp(n, 0);        
    for(int i = 0; i < m; i++) {
        vector<int> temp(n, 0);
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                temp[j] = 1;
            } else {
                int up = 0, left = 0;
                if(i > 0) up = dp[j];
                if(j > 0) left = temp[j - 1];
                temp[j] = up + left;
            }
        }
        dp = temp;
    }
    return dp[n - 1];
}