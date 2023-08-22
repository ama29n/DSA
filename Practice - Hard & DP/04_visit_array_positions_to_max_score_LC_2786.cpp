#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/visit-array-positions-to-maximize-score/description/ 

// Inefficient Solution as record of prev element costs extra memory
// dp[i][prev] -> max sum till "i" element when prev was "j"

// Efficient Solution, keep record of parity of previous element
// dp[i][prev_parity]
class Solution {
private:
    int n, x;
    typedef long long ll;
    vector<vector<ll>> dp;
    ll dfs(int i, int parity, vector<int> &nums) {
        if(i == n) { return 0; }
        if(dp[i][parity] != -1) { return dp[i][parity]; }
        ll skip = dfs(i + 1, parity, nums);
        ll pick = nums[i] + dfs(i + 1, (nums[i] & 1), nums);
        if((nums[i] & 1) != parity)
            pick -= x;
        return dp[i][parity] = max(skip, pick);
    }
public:
    ll maxScore(vector<int> &nums, int _x) {
        n = nums.size(); x = _x;
        dp.resize(n, vector<ll> (2, -1));
        return nums[0] + dfs(1, (nums[0] & 1), nums);
    }
};
