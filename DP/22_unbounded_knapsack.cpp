#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int find(int i, int w, int val[], int weight[], vector<vector<int>>& dp) {
        if(w == 0)
            return 0;
        // Here, we are not using the if condition of 20th question because here we don't need to complete the target w / wt[0] 
        // will automatically give the highest integer value less than or equal to w.
        if(i == 0)
            return (w / weight[0] * val[0]);
        if(dp[i][w] != -1)
            return dp[i][w];
            
        int notTake = find(i - 1, w, val, weight, dp);
        int take = INT_MIN;
        if(weight[i] <= w) 
            take = val[i] + find(i, w - weight[i], val, weight, dp);
        return dp[i][w] = max(take, notTake);
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