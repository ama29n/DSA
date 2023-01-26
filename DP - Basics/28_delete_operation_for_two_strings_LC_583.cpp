#include <bits/stdc++.h>
using namespace std;

// Given two strings s and t, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.

int minDistance(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i - 1] == t[j - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return n + m - (2 * dp[n][m]);
}