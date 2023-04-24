#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/ 

// Memoization
class Solution {
public:
    int cal(int i, int buy, int count, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if(count == 2 || i == prices.size()) {
            return 0;
        }
        if(dp[i][buy][count] != -1) {
            return dp[i][buy][count];
        }
        int profit = 0;
        if(buy) {
            int take = -prices[i] + cal(i + 1, 0, count, prices, dp);
            int notTake = cal(i + 1, 1, count, prices, dp);
            profit = max(take, notTake);
        }
        else {
            int take = prices[i] + cal(i + 1, 1, count + 1, prices, dp);
            int notTake = cal(i + 1, 0, count, prices, dp);
            profit = max(take, notTake);
        }
        return dp[i][buy][count] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (3, vector<int> (2, -1)));
        return cal(0, 1, 0, prices, dp);
    }
};