#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximize-score-after-n-operations/ 

class Solution {
private: 
    int n;
    int dp[8][(1 << 14)];
    int dfs(int i, int mask, vector<int> &nums) {
        if(mask == (1 << n) - 1) {
            return 0;
        }
        int &temp = dp[i][mask];
        if(temp != -1) return temp;
        temp = 0;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(j == k) continue;
                int new_mask = (1 << j) + (1 << k);
                if(!(mask & new_mask)) {
                    int score = i * __gcd(nums[j], nums[k]) + dfs(i + 1, mask | new_mask, nums);
                    temp = max(temp, score);
                } 
            }
        }
        return temp;
    }
public:
    int maxScore(vector<int> &nums) {
        n = nums.size();
        memset(dp, -1, sizeof dp);
        return dfs(1, 0, nums);
    }
};