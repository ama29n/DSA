#include<bits/stdc++.h>
using namespace std;

// Memoization 

class Solution {
public:
    int find(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if(i >= prices.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if(buy) {
            int notTake = find(i + 1, 1, prices, dp);
            int take = -prices[i] + find(i + 1, 0, prices, dp);
            profit = max(take, notTake);
        } else {
            int notTake = find(i + 1, 0, prices, dp);
            int take = prices[i] + find(i + 2, 1, prices, dp);
            profit = max(take, notTake);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        return find(0, 1, prices, dp);
    }
};


// Tabulation

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int> (2, 0));
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
                int take = prices[i] + dp[i + 2][1];
                dp[i][buy] = max(take, notTake);
            }
        }
    }
    // dp[0][1] is the answer because in order to maximise the transactions we must buy the initial one
    return dp[0][1];
}