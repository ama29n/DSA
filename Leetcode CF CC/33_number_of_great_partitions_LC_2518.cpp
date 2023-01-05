#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-great-partitions/

// You are given an array nums consisting of positive integers and an integer k.
// Partition the array into two ordered groups such that each element is in exactly one group.
// A partition is called great if the sum of elements of each group is greater than or equal to k.
// Return the number of distinct great partitions. Since the answer may be too large, return it modulo 109 + 7.
// Two partitions are considered distinct if some element nums[i] is in different groups in the two partitions.

// Approach
// Calculate subsequences whose sum is less than k and answer will be total subsequences - mentioned subsequences

class Solution {
public:
    typedef long long ll;
    const int mod = 1E9 + 7;
    ll total = 0;
    vector<vector<int>> dp;
    ll cal(int i, ll sum, vector<int>& nums, int k) {
        if(sum > k) {
            return 0;
        }
        if(i == nums.size()) {
            return sum < k ? 1 : 0;
        }
        if(dp[i][sum] != -1)
            return dp[i][sum];
        ll take = cal(i + 1, sum + nums[i], nums, k) % mod;
        ll nake = cal(i + 1, sum, nums, k) % mod;
        return dp[i][sum] = (take + nake) % mod;
    }
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        for(auto it : nums)
            total += it;
        if(total < (2 * k))
            return 0;
        dp = vector<vector<int>> (n, vector<int> (k + 1, -1));
        ll x = cal(0, 0, nums, k);
        x--;           // x also include count of empty sequence i.e., {}
        ll y = 2;      // Total number of sequences
        for(int i = 2; i <= n; i++) {
            y *= 2; y %= mod;
        }
        // Subtracting sequences whose partition is not possible i.e., {} and {all elements of nums[]}
        y -= 2;        
        ll ans = ((y - ((2 * x) % mod)) + mod) % mod;
        return ans;
    }
};