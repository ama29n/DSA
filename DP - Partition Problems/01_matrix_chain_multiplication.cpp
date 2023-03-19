#include<bits/stdc++.h>
using namespace std;

// For recursive solution it is exponential

// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// Memoization

class Solution{
public:
    vector<vector<int>> dp;
    int cal(int i, int j, int arr[]) {
        if(i >= j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int min_steps = INT_MAX;
        for(int k = i; k <= j - 1; k++) {
            int steps = (arr[i - 1] * arr[k] * arr[j]) + cal(i, k, arr) + cal(k + 1, j, arr);
            if(steps < min_steps) {
                min_steps = steps;
            }
        }
        return dp[i][j] = min_steps;
    }
    int matrixMultiplication(int n, int arr[]) {
        dp.resize(n, vector<int> (n, -1));
        return cal(1, n - 1, arr);
    }
};

// Time - O(n ^ 3)
// Space - O(n ^ 2) ignoring recursion stack space

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

class Solution{
public:
    int matrixMultiplication(int n, int p[]) {
        vector<vector<int>> m(n, vector<int> (n, 0));
        for(int L = 2; L < n; L++) {
            for(int i = 1; i < n - L + 1; i++) {
                int j = i + L - 1;
                m[i][j] = INT_MAX;
                for(int k = i; k <= j - 1; k++) {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if(q < m[i][j]) {
                        m[i][j] = q;
                    }
                }
            }
        }
        return m[1][n - 1];
    }
};