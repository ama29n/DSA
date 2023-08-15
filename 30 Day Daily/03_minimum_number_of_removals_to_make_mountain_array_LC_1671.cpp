#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array

class Solution {
private: 
    #define all(x)      x.begin(), x.end()
    int n;
    // LIS will return dp[]
    // dp[i] -> LIS till ith ele
    vector<int> LIS(vector<int> &nums) {
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp;
    }
public:
    int minimumMountainRemovals(vector<int> &nums) {
        n = nums.size();
        vector<int> dp1 = LIS(nums);
        reverse(all(nums));
        vector<int> dp2 = LIS(nums);
        reverse(all(dp2));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            // Both side should be > than 1 otherwise it is not mountain
            // It is a one sided slope
            if(dp1[i] > 1 && dp2[i] > 1) {
                // - 1 -> as current ele is included 2 times
                ans = max(ans, dp1[i] + dp2[i] - 1);
            }
        }
        return n - ans;
    }
};
