#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[]) {
        vector<int> dp(W + 1, 0);
        for(int i = 0; i < n; i++) {
            for(int w = wt[i]; w <= dp.size(); w++)
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
        return dp[W];
    }
};