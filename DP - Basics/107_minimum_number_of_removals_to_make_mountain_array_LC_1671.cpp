#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/ 

int minimumMountainRemovals(vector<int>& nums) {
    // LIS from starting 
    int n = nums.size();
    vector<int> dp1(n + 1, 1);
    for(int i = 1; i < n; i++) {
        int maxi = 1;
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j])
                maxi = max(maxi, dp1[j] + 1);
        }
        dp1[i] = maxi;
    }
    // LIS from end 
    vector<int> dp2(n + 1, 1);
    for(int i = n - 2; i >= 0; i--) {
        int maxi = 1;
        for(int j = n - 1; j > i; j--) {
            if(nums[i] > nums[j])
                maxi = max(maxi, dp2[j] + 1);
        }
        dp2[i] = maxi;
    }
    // We don't want peak to be at corners 
    // also both dps should be greater than 1... as otherwise it will be strictly increasing or decreasing 
    int ans = 0;
    for(int i = 1; i < n - 1; i++) {
        if(dp1[i] > 1 && dp2[i] > 1)
            ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    return n - ans;
}
// Time - O(n ^ 2) 
// Space = O(n)