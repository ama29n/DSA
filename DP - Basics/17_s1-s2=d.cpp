#include <bits/stdc++.h>
using namespace std;


// Memoization

int count(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(i == 0) {
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || target == arr[0]) return 1;
        return 0;
    }
    if(dp[i][target] != -1)
        return dp[i][target];
    
    int pick = 0;
    int notPick = count(i - 1, target, arr, dp);
    if(arr[i] <= target) pick = count(i - 1, target - arr[i], arr, dp);
    
    return dp[i][target] = (pick + notPick);
}

int countPartitions(int n, int d, vector<int> &arr) {
    int total = 0, target;
    for(auto it : arr) total += it;

    // Important conditions
    if(total - d < 0 || (total - d) % 2 != 0) return 0;

    target = (total - d) / 2;
    vector<vector<int>> dp(n, vector<int> (target + 1, -1));
    return count(n - 1, target, arr, dp);
}