#include<bits/stdc++.h>
using namespace std;

// Recursive

// Time = 2 raised to the power n as for every index i have options take or dont take 
// space = O(n) stack space 



// Memoization

// here dp array is 1001 becuase the limit on value of arr[i] is 1000

bool check(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(target == 0)
        return true;
    if(i == 0)
        return (target == arr[0]);
    
    if(dp[i][target] != -1)
        return dp[i][target];
    
    // Subarrays from previous positions, 
    bool notTake = check(i - 1, target, arr, dp);

    // Subarrays from current positions
    bool take = false; 
    if(arr[i] <= target) 
        take = check(i - 1, target - arr[i], arr, dp);

    return dp[i][target] = take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int> (k + 1, -1));
    return check(n - 1, k, arr, dp);
}

// Time = n * target 
// Space = O(n) + O(n * target) 




// Tabulation 

// This solution is derived from memoization solution
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool> (k + 1, false));
    for(int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int idx = 1; idx < n; idx++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = dp[idx - 1][target];
            bool take = false;
            if(arr[idx] <= target)
                take = dp[idx - 1][target - arr[idx]];
            dp[idx][target] = take || notTake;
        }
    }
    return dp[n - 1][k];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n + 1, vector<bool> (k + 1));
    for(int idx = 0; idx <= n; idx++) {
        for(int t = 0; t <= k; t++) {
            if(idx == 0 && t == 0) {
                dp[idx][t] = true;
            } else if(idx == 0) {
                dp[idx][t] == false;
            } else if(t == 0) {
                dp[idx][t] = true;
            } else {
                bool notTake = dp[idx - 1][t];
                bool take = false;
                if(arr[idx - 1] <= t)
                    take = dp[idx - 1][t - arr[idx - 1]];
                dp[idx][t] = take | notTake;
            }
        }
    }
    return dp[n][k];
}