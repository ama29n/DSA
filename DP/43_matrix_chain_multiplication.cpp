#include<bits/stdc++.h>
using namespace std;

// For recursive solution it is exponential

// Memoization

int cal(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
    if(i >= j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int mini = INT_MAX;
    for(int k = i; k <= j - 1; k++) {
        int step = (arr[i - 1] * arr[k] * arr[j]) + cal(arr, i, k, dp) + cal(arr, k + 1, j, dp);
        mini = min(mini, step);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int n) {
    vector<vector<int>> dp(n, vector<int> (n, -1));
    return cal(arr, 1, n - 1, dp);
}

// Space - O(n ^ 2) ignoring recursion stack space
// Time - O(n ^ 3)