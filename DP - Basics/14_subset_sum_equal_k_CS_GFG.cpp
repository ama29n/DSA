#include<bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954 

// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1 

// Recursive
// Time = 2 raised to the power n as for every index, i has 2 options; take & not take 
// space = O(n) stack space 

// Memoization
bool dfs(int i, int k, vector<int> &arr, vector<vector<int>> &dp, int n) {
    if(k == 0) {
        return true;
    }
    if(i == n) {
        return false;
    }
    if(dp[i][k] != -1) {
        return dp[i][k];
    }
    bool not_take = dfs(i + 1, k, arr, dp, n);
    bool take = false;
    if(arr[i] <= k) {
        take = dfs(i + 1, k - arr[i], arr, dp, n);
    }
    return dp[i][k] = not_take || take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int> (k + 1, -1));
    return dfs(0, k, arr, dp, n);
}
// Time = n * target 
// Space = O(n) + O(n * target) 

// Tabulation (From Memoization)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool> (k + 1, false));
    for(int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for(int idx = 1; idx < n; idx++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = dp[idx - 1][target];
            bool take = false;
            if(arr[idx] <= target) {
                take = dp[idx - 1][target - arr[idx]];
            }
            dp[idx][target] = take || notTake;
        }
    }
    return dp[n - 1][k];
}

// Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n + 1, vector<bool> (k + 1));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = true;
            } else if(i == 0) {
                dp[i][j] = false;
            } else if(j == 0) {
                dp[i][j] = true;
            } else {
                bool not_take = dp[i - 1][j];
                bool take = false;
                if(arr[i - 1] <= j) {
                    take = dp[i - 1][j - arr[i - 1]];
                }
                dp[i][j] = take || not_take;
            }
        }
    }
    return dp[n][k];
}