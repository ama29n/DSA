#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/

class Solution {
public:
    // dp[0][i] --> LIS till "i", if ith ele from nums
    // dp[1][i] --> LIS till "i", if ith ele from arr
    int maxNonDecreasingLength(vector<int> &nums, vector<int> &arr) {
        int n = arr.size();
        int dp[2][n]; memset(dp, 0, sizeof dp);
        dp[0][0] = dp[1][0] = 1;
        // We are dealing with subarrays here 
        // If we don't find any subarray continuation then, initialise current state with 1
        // For case --> [8, 7, 4] & [13, 4, 4]
        for(int i = 1; i < n; i++) {
            dp[0][i] = max(nums[i] >= nums[i - 1] ? dp[0][i - 1] + 1 : 1, nums[i] >= arr[i - 1] ? dp[1][i - 1] + 1 : 1);
            dp[1][i] = max(arr[i] >= arr[i - 1] ? dp[1][i - 1] + 1 : 1, arr[i] >= nums[i - 1] ? dp[0][i - 1] + 1 : 1);
        }
        int ans = 0;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) ans = max(ans, dp[i][j]);
        }
        return ans;
    }
};

// For subsequence
// It is relatively easy, just take max of prev states
class Solution2 {
public:
    // dp[0][i] --> LIS till "i", if ith ele from nums
    // dp[1][i] --> LIS till "i", if ith ele from arr
    int maxNonDecreasingLength(vector<int> &nums, vector<int> &arr) {
        int n = arr.size();
        int dp[2][n]; memset(dp, 0, sizeof dp);
        dp[0][0] = dp[1][0] = 1;
        for(int i = 1; i < n; i++) {
            dp[0][i] = max(dp[0][i - 1] + (nums[i] >= nums[i - 1] ? 1 : 0), dp[1][i - 1] + (nums[i] >= arr[i - 1] ? 1 : 0));
            dp[1][i] = max(dp[1][i - 1] + (arr[i] >= arr[i - 1] ? 1 : 0), dp[0][i - 1] + (arr[i] >= nums[i - 1] ? 1 : 0));
        }
        return max(dp[0][n - 1], dp[1][n - 1]);
    }
};