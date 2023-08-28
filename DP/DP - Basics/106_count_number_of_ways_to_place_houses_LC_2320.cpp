#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-number-of-ways-to-place-houses/

class Solution {
public:
    const int mod = 1e9 + 7;
    int countHousePlacements(int n) {
        // dp[i][0] -> number of ways till ith pos not considering the current house
        // dp[i][1] -> number of ways till ith pos considering the current house
        vector<vector<int>> dp(n, vector<int> (2, 0));
        dp[0][0] = dp[0][1] = 1;
        for(int i = 1; i < n; i++) {
            dp[i][1] = dp[i - 1][0];
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
        }
        long long ans = (dp[n - 1][0] + dp[n - 1][1]) % mod;
        return (ans * ans) % mod;
    }
};

class Solution {
public:
    const int mod = 1e9 + 7;
    int countHousePlacements(int n) {
        int take = 1, not_take = 1;
        for(int i = 1; i < n; i++) {
            int cur_take = not_take;
            int cur_not_take = (take + not_take) % mod;
            take = cur_take;
            not_take = cur_not_take;
        }
        long long ans = (take + not_take) % mod;
        return (ans * ans) % mod;
    }
};
