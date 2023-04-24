#include<bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532 

// Memoization
// This solution is only valid if  nums[i] != 0
// Example [0, 0, 1]
int dfs(int i, int k, vector<int> &nums, vector<vector<int>> &dp) {
    // By using this base case, solution is going till the end
    if(i == nums.size() - 1) {
        return (k == 0 || k == nums[i] ? 1 : 0);
    } 
    // By using this base case, solution is not going forward from the point where sum = 0
    // if(k == 0) {
    //     return 1;
    // }
    // if(i == nums.size()) {
    //     return 0;
    // }
    if(dp[i][k] != -1) {
        return dp[i][k];
    }
    int not_take = dfs(i + 1, k, nums, dp);
    int take = 0;
    if(nums[i] <= k) {
        take = dfs(i + 1, k - nums[i], nums, dp);
    }
    return dp[i][k] = take + not_take;
}
int findWays(vector<int> &nums, int K) {
    int n = nums.size(); 
    vector<vector<int>> dp(n + 1, vector<int> (K + 1, -1));
    return dfs(0, K, nums, dp);
}

// Tabulation
int findWays(vector<int> &nums, int K) {
    int n = nums.size(); 
    vector<vector<int>> dp(n + 1, vector<int> (K + 1));
    for(int i = 0; i <= n; i++) {
        for(int k = 0; k <= K; k++) {
            if(i == 0 && k == 0) {
                dp[i][k] = 1;
            } else if(i == 0) {
                dp[i][k] = 0;
            } else if(k == 0) {
                dp[i][k] = 1;
            } else {
                int not_take = dp[i - 1][k];
                int take = 0;
                if(nums[i - 1] <= k) {
                    take = dp[i - 1][k - nums[i - 1]];
                }
                dp[i][k] = take + not_take;
            } 
        }
    }
    return dp[n][K];
}

// If nums[i] can also be zero, following solution would be used
#include <bits/stdc++.h> 
int dfs(int i, int k, vector<int> &nums, vector<vector<int>> &dp) {
    if(i == nums.size() - 1) {
        if(k == 0 && nums[i] == 0) {
            return 2;
        }
        if(k == 0 || k == nums[i]) {
            return 1;
        }
        return 0;
    }
    if(dp[i][k] != -1) {
        return dp[i][k];
    }
    int not_take = dfs(i + 1, k, nums, dp);
    int take = 0;
    if(nums[i] <= k) {
        take = dfs(i + 1, k - nums[i], nums, dp);
    }
    return dp[i][k] = take + not_take;
}
int findWays(vector<int> &nums, int K) {
    int n = nums.size(); 
    vector<vector<int>> dp(n + 1, vector<int> (K + 1, -1));
    return dfs(0, K, nums, dp);
}