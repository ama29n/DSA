#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/coin-change/ 

// https://practice.geeksforgeeks.org/problems/coin-change2448/1

class Solution {
private:
    int n;
    int dp[13][10000 + 1];
    int dfs(int i, int amount, vector<int> &coins) {
        if(i == n) {
            return amount == 0 ? 0 : 1E9;
        }
        if(dp[i][amount] != -1) {
            return dp[i][amount];
        }
        int skip = dfs(i + 1, amount, coins);
        int pick = 1E9;
        if(coins[i] <= amount) {
            pick = 1 + dfs(i, amount - coins[i], coins);
        }
        return dp[i][amount] = min(skip, pick);
    }
public:
    int coinChange(vector<int> &coins, int amount) {
        n = coins.size();
        memset(dp, -1, sizeof dp);
        int ans = dfs(0, amount, coins);
        return ans >= 1E9 ? -1 : ans;
    }
};

// Tabulation
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
