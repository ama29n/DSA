#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/delete-operation-for-two-strings/ 

// Steps to make strings same; Only 1 charcater can be deleted at a time

class Solution {
public:
    int minDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        int dp[m + 1][n + 1]; memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return (m + n) - (2 * dp[m][n]);
    }
};
