#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/ 


// Steps to make string palindrome; Only 1 charcater can be inserted at a time

// total length - LPS

class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return n - dp[n][n];
    }
};
