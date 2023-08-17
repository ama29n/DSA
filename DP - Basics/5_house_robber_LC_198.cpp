#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber/ 

// Memoization
class Solution {
private:
    int n;
    int dp[102];
    int dfs(int i, vector<int> &nums) {
        if(i >= n) return 0;
        if(dp[i] != -1) {
            return dp[i];
        }
        int pick = dfs(i + 2, nums) + nums[i];
        int skip = dfs(i + 1, nums);
        return dp[i] = max(pick, skip);
    }
public:
    int rob(vector<int> &nums) {
        n = nums.size();
        memset(dp, -1, sizeof dp);
        return dfs(0, nums);
    }
};

// Tabulation
class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < n; i++) {
            int pick = nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
            int skip = dp[i - 1];
            dp[i] = max(pick, skip);
        }
        return dp[n - 1];
    }
};

// House Robber 2 

// https://leetcode.com/problems/house-robber-ii/ 

class Solution {
private:
    int dp[102];
    int dfs(int i, int n, vector<int> &nums) {
        if(i >= n) {
            return 0;
        }
        if(dp[i] + 1) {
            return dp[i];
        }
        int pick = dfs(i + 2, n, nums) + nums[i];
        int skip = dfs(i + 1, n, nums);
        return dp[i] = max(pick, skip);
    }
public:
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