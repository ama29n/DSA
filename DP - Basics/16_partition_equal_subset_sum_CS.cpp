#include<bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980 

// https://leetcode.com/problems/partition-equal-subset-sum/ 

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
                bool skip = dp[i - 1][j];
                bool pick = false;
                if(arr[i - 1] <= j) {
                    pick = dp[i - 1][j - arr[i - 1]];
                }
                dp[i][j] = pick || skip;
            }
        }
    }
    return dp[n][k];
}

bool canPartition(vector<int> &arr, int n) {
    int sum = 0;
    for(auto it : arr) {
        sum += it;
    }
    if(sum % 2 != 0) {
        return false;
    }
	return subsetSumToK(n - 1, sum / 2, arr);
}