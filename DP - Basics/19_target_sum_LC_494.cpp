#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/target-sum/ 

// sum(nums[i]) <= 1000 thus, min nums[i] = -1000 &
// - 1000 <= target <= 1000
// Thus, offset = 2000
class Solution {
public:
    int n;
    int dp[1000 + 1][4000 + 1];
    int dfs(int i, int t, vector<int> &nums) {
        if(i == n - 1) {
            if(t == 0 && nums[i] == 0) {
                return 2;
            }
            // As it is mandatory to take all elements
            if(t == -nums[i] || t == nums[i]) {
                return 1;
            }
            return 0;
        }
        if(dp[i][t + 2000] != -1) {
            return dp[i][t + 2000];
        }
        int add = dfs(i + 1, t + nums[i], nums);
        int sub = dfs(i + 1, t - nums[i], nums);
        return add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, target, nums);
    }
};