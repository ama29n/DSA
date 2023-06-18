#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/special-permutations/description/ 


// Keep track of the chosen numbers, a bitmask is used. Each bit in the bitmask represents a number that has been chosen. 
// Setting the corresponding bit in the bitmask for the current index, indicates that the number at that index has been chosen.

class Solution {
public:
    int n;
    int dp[14][16400];
    const int mod = 1E9 + 7;
    bool check(int &a, int &b) {
        return a % b == 0 || b % a == 0;
    }
    int dfs(int i, int mask, vector<int> &nums) {
        if(mask == ((1 << n) - 1)) {
            return 1;
        }
        if(dp[i][mask] == -1) {
            dp[i][mask] = 0;
            for(int j = 0; j < n; j++) {
                if((mask & (1 << j)) == 0 && (mask == 0 || check(nums[i], nums[j]))) {
                    dp[i][mask] = (dp[i][mask] + dfs(j, mask + (1 << j), nums)) % mod;
                }
            }
        }
        return dp[i][mask];
    }
    int specialPerm(vector<int> &nums) {
        n = nums.size();
        memset(dp, -1, sizeof dp);
        return dfs(0, 0, nums);
    }
};