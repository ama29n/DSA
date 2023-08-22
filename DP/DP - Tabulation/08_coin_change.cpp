#include <bits/stdc++.h>
using namespace std;

// here dp[i] will represent the number of ways to make the target (0 <= target <= sum), with each coin

// https://practice.geeksforgeeks.org/problems/coin-change2448/1

class Solution {
  public:
    typedef long long ll;
    ll count(int coins[], int n, int sum) {
        vector<ll> dp(sum + 1);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = coins[i]; j < dp.size(); j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[sum];
    }
};