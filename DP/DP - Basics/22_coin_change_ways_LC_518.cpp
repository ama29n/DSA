#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/coin-change-ii/

class Solution {
private:
    int n;
    int dp[300 + 1][5000 + 1];
    int dfs(int i, int amount, vector<int> &coins) {
        // if(i == n - 1) {
        //     return amount % coins[i] == 0 ? 1 : 0;
        // }
        if(i == n) {
            return amount == 0 ? 1 : 0;
        }
        if(dp[i][amount] != -1) {
            return dp[i][amount];
        }
        int skip = dfs(i + 1, amount, coins);
        int pick = 0;
        if(coins[i] <= amount) {
            pick = dfs(i, amount - coins[i], coins);
        }
        return dp[i][amount] = pick + skip;
    }
public:
    int change(int amount, vector<int> &coins) {
        n = coins.size();
        memset(dp, -1, sizeof dp);
        return dfs(0, amount, coins);
    }
};