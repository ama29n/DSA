#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int cal(int i, int n, int W, vector<int>& profit, vector<int>& wt, vector<vector<int>>& dp) {
        // Here, we are not using the if condition of 20th question because here we don't need to complete the target w / wt[0] 
        // will automatically give the highest integer value less than or equal to w.
        if(i == n - 1)
            return (W / wt[i]) * profit[i];
        if(dp[i][W] != -1)
            return dp[i][W];
        int notTake = cal(i + 1, n, W, profit, wt, dp);
        int take = 0;
        if(wt[i] <= W)
            take = profit[i] + cal(i, n, W - wt[i], profit, wt, dp);
        return dp[i][W] = max(take, notTake);
    }
    int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight) {
        vector<vector<int>> dp(n, vector<int> (W + 1, -1));
        return cal(0, n, W, profit, weight, dp);
    }



    int knapSack(int n, int w, int val[], int weight[]) {
        vector<vector<int>> dp(n, vector<int> (w + 1, 0));
        for(int i = 0; i < n; i++)
            dp[i][0] = 0;
        for(int j = 1; j <= w; j++)
            dp[0][j] = j / weight[0] * val[0];
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= w; j++) {
                int notTake = dp[i - 1][j];
                int take = INT_MIN;
                if(weight[i] <= j)
                    take = val[i] + dp[i][j - weight[i]];
                dp[i][j] = max(take, notTake);
            }
        }
        return dp[n - 1][w];
    }
};