#include<bits/stdc++.h>
using namespace std;

long count(int i, int value, int *denominations, vector<vector<long>>& dp) {
    if(value == 0)
        return 1;
    if(i == 0) {
        if(value % denominations[0] == 0)
            return 1;
        return 0;
    }
    if(dp[i][value] != 0)
        return dp[i][value];
    
    long notTake = count(i - 1, value, denominations, dp);
    long take = 0;
    if(denominations[i] <= value)
        take = count(i, value - denominations[i], denominations, dp);
    return dp[i][value] = notTake + take;
}

long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<vector<long>> dp(n, vector<long> (value + 1, 0));
    int ans = count(n - 1, value, denominations, dp);
//     if(ans)
        return ans;
//     return 0;
}