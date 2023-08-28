#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/profitable-schemes/ 

// Brute Force -> 100 * 100 * (100 * 100) -> 1E8

// min(cur_profit + profit[i], goal) -> after reaching the goal, all the profits would give the same answer

class Solution {
private:
    int goal;
    vector<int> group, profit;
    int dp[102][102][102];
    const int MOD = 1E9 + 7;
    // DP
    int dfs(int i, int n, int cur_profit) {   
        if(i == group.size()) {
            return cur_profit >= goal ? 1 : 0;
        }
        if(dp[i][n][cur_profit] != -1) {
            return dp[i][n][cur_profit];
        }
        int skip = dfs(i + 1, n, cur_profit);
        int pick = 0;
        if(group[i] <= n) {
            pick = dfs(i + 1, n - group[i], min(cur_profit + profit[i], goal));
        }
        return dp[i][n][cur_profit] = (skip + pick) % MOD;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& Group, vector<int>& Profit) {
        goal = minProfit;
        group = Group; profit = Profit;
        memset(dp, -1, sizeof dp);
        return dfs(0, n, 0);
    }
};
