#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-common-subsequence/ 

// Recursive 
// exponential time complexity - 2 raised to power m * 2 raised to power n

// Memoization
class Solution {
public:
    int m, n;
    int dp[1002][1002];
    int dfs(int i, int j, string &s, string &t) {
        if(i == m || j == n) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s[i] == t[j]) {
            return dp[i][j] = 1 + dfs(i + 1, j + 1, s, t);
        }
        dp[i][j] = max(dfs(i + 1, j, s, t), dfs(i, j + 1, s, t));
        return dp[i][j];
    }
    int longestCommonSubsequence(string s, string t) {
        m = s.size(); n = t.size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, s, t);
    }
};
// Time - O(m * n)
// Space - O(m * n) (dp array) + O(m + n) stack

// Tabulation
int longestCommonSubsequence(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}