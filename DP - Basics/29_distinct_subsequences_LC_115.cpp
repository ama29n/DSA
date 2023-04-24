#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/distinct-subsequences/

// Memoization
class Solution {
public:
    int m, n;
    string s, t;
    vector<vector<int>> dp;
    int dfs(int i, int j) {
        if((i == m && j == n) || j == n) {
            return 1;
        }
        if(i == m) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s[i] == t[j]) {
            dp[i][j] = dfs(i + 1, j + 1) + dfs(i + 1, j);
        } else {
            dp[i][j] = dfs(i + 1, j);
        }
        return dp[i][j];
    }
    int numDistinct(string S, string T) {
        s = S; t = T;
        m = s.size(); n = t.size();
        dp.resize(m + 1, vector<int> (n + 1, -1));
        return dfs(0, 0);
    }
};

// Tabulation
int numDistinct(string s, string t) {
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    int mod = 1e9 + 7;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j] % mod;
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] += dp[i - 1][j - 1] % mod;
            }
        }
    }
    return dp[n][m];
}