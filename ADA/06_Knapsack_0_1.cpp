#include <bits/stdc++.h>
using namespace std;

void knapsack(int weight[], int profit[], int n, int W) {
    int dp[n + 1][W + 1];
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0) {
                dp[i][w] = 0;
            } else {
                if(weight[i - 1] <= w) {
                    dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + profit[i - 1]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
    }
    // Max Profit
    cout << dp[n][W] << endl;
    // Elements selected in the knapsack
    int i = n, w = W;
    while(i > 0 && w > 0) {
        if(dp[i][w] != dp[i - 1][w]) {
            cout << i - 1 << " ";
            i--;
            w -= weight[i - 1];
        } else {
            i--;
        }
    }
}

int main () {
  int n = 3;
  int W = 6;
  int weight[n] = {1, 2, 3};
  int profit[n] = {10, 15, 40};
  knapsack(weight, profit, n, W);
}

