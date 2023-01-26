#include <bits/stdc++.h>
using namespace std;

int find(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
    
    if(i == 0) {
        if(target == 0 && nums[0] == 0) return 2;
        if(target == nums[0] || target + nums[0] == 0) return 1;
        return 0;
    }
    
    if(dp[i][target + 2000] != -1)
        return dp[i][target + 2000];
    
    int add = find(i - 1, target - nums[i], nums, dp);
    int subtract = find(i - 1, target + nums[i], nums, dp);
    
    return dp[i][target + 2000] = add + subtract;
}

int findTargetSumWays(vector<int>& nums, int target) {
    vector<vector<int>> dp(nums.size(), vector<int> (4000, -1));
    return find(nums.size() - 1, target, nums, dp);
}