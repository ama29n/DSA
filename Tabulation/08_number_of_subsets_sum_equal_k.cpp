#include<bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

int findWays(vector<int> &nums, int t) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int> (t + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= t; j++) {
            if(nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            else 
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][t];
}