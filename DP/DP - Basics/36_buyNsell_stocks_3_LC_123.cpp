#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/ 

class Solution {
private:
    int n;
    vector<vector<vector<int>>> dp;
    int dfs(int i, int buy, int count, vector<int> &prices) {
        if(count == 0 || i == n) {
            return 0;
        }
        if(dp[i][buy][count] != -1) {
            return dp[i][buy][count];
        }
        if(buy) {
            int pick = -prices[i] + dfs(i + 1, 0, count, prices);
            int skip = dfs(i + 1, 1, count, prices);
            return dp[i][buy][count] = max(pick, skip);
        } else {
            int pick = prices[i] + dfs(i + 1, 1, count -1, prices);
            int skip = dfs(i + 1, 0, count, prices);
            return dp[i][buy][count] = max(pick, skip);
        }
    }
public:
    int maxProfit(vector<int> &prices) {
        n = prices.size();
        dp.resize(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return dfs(0, 1, 2, prices);
    }
};
