#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1 

class Solution {
private: 
    int n;
    int dp[1000 + 1][1000 + 1];
    int dfs(int i, int W, int wt[], int val[]) {
		// if(i == n - 1) {
		// 	return wt[i] <= W ? val[i] : 0;
		// }
        if(i == n) {
            return 0; // Return 0, irrespective of value of W
        }
        if(dp[i][W] != -1) {
            return dp[i][W];
        }
        int skip = dfs(i + 1, W, wt, val);
        int pick = -1E5;
        if(wt[i] <= W) {
            pick = val[i] + dfs(i + 1, W - wt[i], wt, val);
        }
        return dp[i][W] = max(skip, pick);
    }
public:
    int knapSack(int W, int wt[], int val[], int _n) { 
       n = _n;
       memset(dp, -1, sizeof dp);
       return dfs(0, W, wt, val);
    }
};

// Tabulation
class Solution {
public:
    int knapSack(int W, int wt[], int val[], int n) { 
       vector<vector<int>> dp(n + 1, vector<int> (W + 1));
       for(int i = 0; i <= n; i++) {
           for(int w = 0; w <= W; w++) {
               if(i == 0 || w == 0) {
                   dp[i][w] = 0;
               } else {
                   if(wt[i - 1] <= w)
                        dp[i][w] = max(dp[i - 1][w - wt[i - 1]] + val[i - 1], dp[i - 1][w]);
                    else 
                        dp[i][w] = dp[i - 1][w];
               }
           }
       }
       return dp[n][W];
    }
};
