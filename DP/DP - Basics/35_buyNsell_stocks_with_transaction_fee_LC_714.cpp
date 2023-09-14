#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/ 

// Memoization
class Solution {
private:
    int n, fee;
    vector<vector<int>> dp;
    int dfs(int i, int buy, vector<int> &prices) {
        if(i == n) {
            return 0;
        }
        if(dp[i][buy] != -1) {
            return dp[i][buy];
        }
        if(buy) {
            int pick = -prices[i] + dfs(i + 1, 0, prices);
            int skip = dfs(i + 1, 1, prices);
            return dp[i][buy] = max(pick, skip);
        } else {
            int pick = prices[i] + dfs(i + 1, 1, prices);
            int skip = dfs(i + 1, 0, prices);
            return dp[i][buy] = max(pick, skip);
        }
    }
public:
    int maxProfit(vector<int> &prices, int _fee) {
        n = prices.size(); fee = _fee;
        dp.resize(n, vector<int> (2, -1));
        return dfs(0, 1, prices);
    }
};

// Direct Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, 0));
        dp[0][0] = 0 - prices[0];
        for(int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + prices[i] - fee, dp[i - 1][1]);
        }
        return dp[n - 1][1];
    }
};
