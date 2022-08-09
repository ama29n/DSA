#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cal(int i, string &s, int num, int k, vector<vector<int>>& dp) {
        if(i < 0) {
            return 0;
        }
        if(dp[i][num] != -1)
            return dp[i][num];
        int notTake = cal(i - 1, s, num, k, dp);
        int take = 0;
        if(pow(2, num) * (s[i] - '0') <= k)
            take = 1 + cal(i - 1, s, num + 1, k - pow(2, num) * (s[i] - '0'), dp);
        return dp[i][num] = max(take, notTake);
    }
    int longestSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return cal(n - 1, s, 0, k, dp);
    }
};