#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) { 
       vector<vector<int>> dp(n + 1, vector<int> (W + 1));
       for(int i = 0; i <= n; i++) {
           for(int w = 0; w <= W; w++) {
               if(i == 0 || w == 0) {
                   dp[i][w] = 0;
               } else {
                   int notTake = dp[i - 1][w];
                   int take = 0;
                   if(wt[i - 1] <= w)
                        take = dp[i - 1][w - wt[i - 1]] + val[i - 1];
                   dp[i][w] = max(take, notTake);
               }
           }
       }
       return dp[n][W];
    }
};