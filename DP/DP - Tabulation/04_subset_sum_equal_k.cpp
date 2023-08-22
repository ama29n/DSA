#include<bits/stdc++.h>
using namespace std;

// here dp[i][t] will reprent if it is possible to make sum t with elements upto i index
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
                if(arr[idx - 1] <= t)
                    dp[idx][t] = dp[idx - 1][t - arr[idx - 1]];
                else 
                    dp[idx][t] = dp[idx - 1][t];
            }
        }
    }
    return dp[n][k];
}