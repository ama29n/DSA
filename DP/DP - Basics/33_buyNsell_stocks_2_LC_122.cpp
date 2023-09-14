#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Memoization
class Solution {
private:
    int n;
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
    int maxProfit(vector<int> &prices) {
        n = prices.size();
        dp.resize(n, vector<int> (2, -1));
        return dfs(0, 1, prices);
    }
};

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

// Direct Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, 0));
        // dp[i][1] -> selling state considering if the current stock will add to profit
        // dp[i][0] -> buying state considering if the current stock will add to the profit 
        // or take previous best buying price
        dp[0][0] = 0 - prices[0];
        for(int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }
        return dp[n - 1][1];
    }
};
