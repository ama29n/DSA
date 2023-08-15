#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/target-sum/ 

class Solution {
private:
    int n;
    // 0 <= sum(nums[i]) <= 1000
    // If nums = [1000] and T = -1000 
    // Therefore, min(t) = -2000 & similarly max(t) = 2000
    // Thus, offset = 2000
    int dp[1000][4000 + 1];
    int dfs(int i, int t, vector<int> &nums) {
        if(i == n - 1) {
            if(t == 0 && nums[i] == 0) {
                return 2;
            }
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
        return dp[i][t + 2000] = add + sub;
    }
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, target, nums);
    }
};
