#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/edit-distance/ 

// Memoization
class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int dfs(int i, int j, string &s, string &t) {
        // Base case for left elements
        if(i == m) {
            return n - j;
        }
        if(j == n) {
            return m - i;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s[i] == t[j]) {
            return dp[i][j] = dfs(i + 1, j + 1, s, t);
        }
        int ins = dfs(i + 1, j, s, t) + 1;
        int del = dfs(i, j + 1, s, t) + 1;
        int rep = dfs(i + 1, j + 1, s, t) + 1;
        return dp[i][j] = min({ins, del, rep});
    }
    int minDistance(string s, string t) {
        m = s.size(); n = t.size();
        dp.resize(m, vector<int> (n, -1));
        return dfs(0, 0, s, t);
    }
};

// Tabulation
int minDistance(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 1; i <= n; i++) {
        dp[i][0] = i;
    }
    for(int j = 1; j <= m; j++) {
        dp[0][j] = j;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int insert = 1 + dp[i][j - 1];
                int del = 1 + dp[i - 1][j];
                int replace = 1 + dp[i - 1][j - 1];
                dp[i][j] = min({insert, del, replace});
            }
        }
    }
    return dp[n][m];
}

class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int minDistance(string s, string t) {
        m = s.size(); n = t.size();
        dp.resize(m + 1, vector<int> (n + 1, 0));
        for(int j = 0; j <= n; j++) {
            dp[m][j] = n - j;
        }
        for(int i = 0; i <= m; i++) {
            dp[i][n] = m - i;
        }
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int ins = dp[i + 1][j] + 1;
                    int del = dp[i][j + 1] + 1;
                    int rep = dp[i + 1][j + 1] + 1;
                    dp[i][j] = min({ins, del, rep});
                }
            }
        }
        return dp[0][0];
    }
};