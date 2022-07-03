#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool> (k + 1, false));
    for(int i = 0; i < n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    
    for(int idx = 1; idx < n; idx++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = dp[idx - 1][target];
            bool take = false;
            
            if(arr[idx] <= target) take = dp[idx - 1][target - arr[idx]];
            dp[idx][target] = take || notTake;
        }
    }
    return dp[n - 1][k];
}

bool canPartition(vector<int> &arr, int n) {
    int sum = 0;
    for(auto it : arr) sum += it ;
    if(sum % 2 != 0) return false;
	return subsetSumToK(n - 1, sum / 2, arr);
}