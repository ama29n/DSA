#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1 

// Recursive
// Time = 2 raised to the power n as for every index, i has 2 options; pick & not pick 
// space = O(n) stack space 

// Memoization
class Solution {  
private: 
    int n;
public:
    bool dfs(int i, int sum, vector<int> &arr, vector<vector<int>> &dp) {
        if(sum == 0) {
            return true;
        }
        if(i == n) {
            return false;
        }
        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }
        bool skip = dfs(i + 1, sum, arr, dp);
        bool pick = false;
        if(arr[i] <= sum) {
            pick = dfs(i + 1, sum - arr[i], arr, dp);
        }
        return dp[i][sum] = skip || pick;
    }
    bool isSubsetSum(vector<int> &arr, int sum) {
        n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, -1));
        return dfs(0, sum, arr, dp);
    }
};
// Time = n * target 
// Space = O(n) + O(n * target) 

// Tabulation
class Solution {  
public:
    bool isSubsetSum(vector<int> &arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool> (sum + 1));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if(i == 0) {
                    dp[i][j] = false;
                } else if(j == 0) {
                    dp[i][j] = true;
                } else {
                    bool skip = dp[i - 1][j];
                    bool pick = false;
                    if(arr[i - 1] <= j) {
                        pick = dp[i - 1][j - arr[i - 1]];
                    }
                    dp[i][j] = pick || skip;
                }
            }
        }
        return dp[n][sum];
    }
};