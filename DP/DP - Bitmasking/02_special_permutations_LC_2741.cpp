#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/special-permutations/description/ 

class Solution {
private:
    int n;
    int dp[15][(1 << 15)];
    const int MOD = 1E9 + 7;
    bool check(int &a, int &b) {
        return a % b == 0 || b % a == 0;
    }
    int dfs(int i, int mask, vector<int> &nums) {
        if(mask == (1 << n) - 1) {
            return 1;
        }
        if(dp[i][mask] != -1) {
            return dp[i][mask];
        }
        dp[i][mask] = 0;
        for(int j = 0; j < n; j++) {
            if(!(mask & (1 << j)) && (mask == 0 || check(nums[i], nums[j]))) {
                dp[i][mask] = (dp[i][mask] + dfs(j, mask | (1 << j), nums)) % MOD;
            }
        }
        return dp[i][mask];
    }
public:
    int specialPerm(vector<int> &nums) {
        n = nums.size();
        memset(dp, -1, sizeof dp);
        return dfs(0, 0, nums);
    }
};