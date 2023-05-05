#include<bits/stdc++.h>
using namespace std;

// For recursive solution Time Complexity is exponential

// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// Memoization
class Solution {
public:
    int n;
    int dp[102][102];
    vector<int> nums;
    int dfs(int i, int j) {
        if(i >= j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int min_steps = INT_MAX;
        for(int k = i; k < j; k++) {
            int steps = nums[i - 1] * nums[k] * nums[j] + dfs(i, k) + dfs(k + 1, j);
            min_steps = min(min_steps, steps);
        }
        return dp[i][j] = min_steps;
    }
    int matrixMultiplication(int N, int arr[]) {
        n = N;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++) {
            nums.push_back(arr[i]);
        }
        return dfs(1, n - 1);
    }
};
// Time - O(n ^ 3)
// Space - O(n ^ 2) ignoring recursion stack space

// Tabulation
class Solution{
public:
    int matrixMultiplication(int n, int arr[]) {
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = n - 1; i >= 1; i--) {
            for(int j = i + 1; j < n; j++) {
                int min_steps = INT_MAX;
                for(int k = i; k < j; k++) {
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    if(steps < min_steps) {
                        min_steps = steps;
                    }
                }
                dp[i][j] = min_steps;
            }
        }
        return dp[1][n - 1];
    }
};

class Solution {
public:
    int matrixMultiplication(int n, int arr[]) {
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int g = 2; g < n; g++) {
            for(int i = 1, j = g; j < n; i++, j++) {
                int min_steps = INT_MAX;
                for(int k = i; k < j; k++) {
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    min_steps = min(min_steps, steps);
                }
                dp[i][j] = min_steps;
            }
        }
        return dp[1][n - 1];
    }
};