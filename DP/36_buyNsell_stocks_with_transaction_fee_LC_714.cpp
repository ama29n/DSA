#include<bits/stdc++.h>
using namespace std;

// Memoization

class Solution {
public:
    int find(int i, int buy, int fee, vector<int>& prices, vector<vector<int>>& dp) {
        if(i == prices.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if(buy) {
            int notTake = find(i + 1, 1, fee, prices, dp);
            int take = -prices[i] + find(i + 1, 0, fee, prices, dp);
            profit = max(take, notTake);
        } else {
            int notTake = find(i + 1, 0, fee, prices, dp);
            int take = prices[i] + find(i + 1, 1, fee, prices, dp) - fee;
            profit = max(take, notTake);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        return find(0, 1, fee, prices, dp);
    }
};


// Tabulation