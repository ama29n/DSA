#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber/ 

// Memoization
class Solution {
public:
    int n;
    int dp[102];
    int dfs(int i, vector<int> &nums) {
        if(i >= n) {
            return 0;
        }
        if(dp[i] + 1) {
            return dp[i];
        }
        int take = dfs(i + 2, nums) + nums[i];
        int nake = dfs(i + 1, nums);
        return dp[i] = max(take, nake);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, nums);
    }
};

// Tabulation
int rob(vector<int>& nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int neg = 0;
    for(int i = 1; i < nums.size(); i++) {
        int pick = nums[i];
        if(i - 2 >= 0) {
            pick += dp[i - 2];
        }
        int notPick = dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[nums.size() - 1];
}

// House Robber 2 

// https://leetcode.com/problems/house-robber-ii/ 

class Solution {
public:
    int dp[102];
    int dfs(int i, int n, vector<int> &nums) {
        if(i >= n) {
            return 0;
        }
        if(dp[i] + 1) {
            return dp[i];
        }
        int take = dfs(i + 2, n, nums) + nums[i];
        int nake = dfs(i + 1, n, nums);
        return dp[i] = max(take, nake);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int x = dfs(0, n - 1, nums);
        memset(dp, -1, sizeof(dp));
        int y = dfs(1, n, nums);
        return max(x, y);
    }
};