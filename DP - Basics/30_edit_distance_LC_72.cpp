#include<bits/stdc++.h>
using namespace std;

// Memoization

int find(int i, string s, int j, string t, vector<vector<int>>& dp) {
    if(i < 0)
        return 1 + j;
    if(j < 0)
        return 1 + i;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(s[i] == t[j])
        return dp[i][j] = find(i - 1, s, j - 1, t, dp);

    else {
        int insert = 1 + find(i, s, j - 1, t, dp);
        int del = 1 + find(i - 1, s, j, t, dp);
        int replace = 1 + find(i - 1, s, j - 1, t, dp);
        return dp[i][j] = min({insert, del, replace});
    }
}
int minDistance(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    return find(n - 1, s, m - 1, t, dp);
}



// memoization

int minDistance(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    
    for(int i = 1; i <= n; i++)
        dp[i][0] = i;
    for(int j = 1; j <= m; j++)
        dp[0][j] = j;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            
            else {
                int insert = 1 + dp[i][j - 1];
                int del = 1 + dp[i - 1][j];
                int replace = 1 + dp[i - 1][j - 1];
                dp[i][j] = min({insert, del, replace});
            }
        }
    }
    return dp[n][m];
}