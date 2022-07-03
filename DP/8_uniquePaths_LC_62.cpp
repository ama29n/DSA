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

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int> (n, -1));
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            
            if(i == 0 && j == 0) dp[i][j] = 1;
            
            else {
                int up = 0, left = 0;
                if(i > 0) up = dp[i - 1][j];
                if(j > 0) left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}





// Space Optimization

int uniquePaths(int m, int n) {
    vector<int> dp(n, 0);        
    for(int i = 0; i < m; i++) {
        vector<int> temp(n, 0);
        for(int j = 0; j < n; j++) {
            
            if(i == 0 && j == 0) temp[j] = 1;
            
            else {
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


// Best Solution 
class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i == m && j == n) return 1;
        if(i > m || j > n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int right = solve(i, j + 1, m, n, dp);
        int down = solve(i + 1, j, m, n, dp);
        return dp[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        dp[1][1] = 1;
        for(int i = 0; i < m; i++) dp[i][0] = 0;
        for(int j = 0; j < n; j++) dp[0][j] = 0;
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};