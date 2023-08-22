#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/edit-distance/ 

// Memoization
class Solution {
private:
    int m, n;
    int dp[500 + 1][500 + 1];
    int dfs(int i, int j, string &s, string &t) {
        // Base Cases: left characters need to be deleted
        if(i == m) { return n - j; }
        if(j == n) { return m - i; }
        // Memoization
        if(dp[i][j] != -1) { return dp[i][j]; }
        // If same characters
        if(s[i] == t[j]) {
            return dp[i][j] = dfs(i + 1, j + 1, s, t);
        }
        // Else
        int ins = 1 + dfs(i, j + 1, s, t);
        int del = 1 + dfs(i + 1, j, s, t);
        int rep = 1 + dfs(i + 1, j + 1, s, t);
        return dp[i][j] = min({ ins, del, rep });   
    }
public:
    int minDistance(string &s, string &t) {
        m = s.size(); n = t.size();
        memset(dp, -1, sizeof dp);
        return dfs(0, 0, s, t);
    }
};

// Tabulation

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
