#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/uncrossed-lines/description/ 

// LCS 

class Solution {
public:
    int maxUncrossedLines(vector<int> &nums, vector<int> &arr) {
        int m = nums.size(), n = arr.size();
        int dp[m + 1][n + 1]; memset(dp, 0, sizeof dp);
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(nums[i - 1] == arr[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
