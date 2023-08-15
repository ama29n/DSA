#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/distinct-subsequences/

// Memoization
class Solution {
private:
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
public:
    int numDistinct(string S, string T) {
        s = S; t = T;
        m = s.size(); n = t.size();
        dp.resize(m + 1, vector<int> (n + 1, -1));
        return dfs(0, 0);
    }
};

// Tabulation
class Solution {
private:
    typedef long long ll;
    const int MOD = 1E9 + 7;
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<ll>> dp(m + 1, vector<ll> (n + 1, 0));
        // Base Case
        for(int i = 0; i <= m; i++) { 
            dp[i][0] = 1; 
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};
