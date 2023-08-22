#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

class Solution {
public:
    int dp[102][102];
    int dfs(int i, int j, vector<int>& cuts) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        int min_cost = INT_MAX;
        for(int k = i; k <= j; k++) {
            int cost = cuts[j + 1] - cuts[i - 1] + dfs(i, k - 1, cuts) + dfs(k + 1, j, cuts);
            if(cost < min_cost) {
                min_cost = cost;
            }
        }
        return dp[i][j] = min_cost;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof(dp));
        return dfs(1, cuts.size() - 2, cuts);
    }
};