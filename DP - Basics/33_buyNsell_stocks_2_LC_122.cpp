#include<bits/stdc++.h>
using namespace std;

// In Recursion
// Time = 2 raised to power n
// Space = O(n) i.e., the stack space 

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Memoization
int cal(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
    if(i == prices.size() - 1) {
        if(buy)
            return 0;
        return prices[i];
    }

    if(dp[i][buy] != -1)
        return dp[i][buy];

    if(buy) {
        int take = -prices[i] + cal(i + 1, 0, prices, dp);
        int notTake = cal(i + 1, 1, prices, dp);
        return dp[i][buy] = max(take, notTake);
    }
    else {
        int take = prices[i] + cal(i + 1, 1, prices, dp);
        int notTake = cal(i + 1, 0, prices, dp);
        return dp[i][buy] = max(take, notTake);
    }
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int> (2, -1));
    return cal(0, 1, prices, dp);
}

// Tabulation
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int> (2, 0));
    dp[n][0] = 0;
    dp[n][1] = 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int buy = 0; buy < 2; buy++) {
            if(buy) {
                int notTake = dp[i + 1][1];
                int take = -prices[i] + dp[i + 1][0];
                dp[i][buy] = max(take, notTake);
            } else {
                int notTake = dp[i + 1][0];
                int take = prices[i] + dp[i + 1][1];
                dp[i][buy] = max(take, notTake);
            }
        }
    }
    return dp[0][1];
}