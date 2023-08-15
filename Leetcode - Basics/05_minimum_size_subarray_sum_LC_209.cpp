#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-size-subarray-sum/

// Problematic Solution
// TCs
// T = 5, nums = [2,3,1,1,1,1,1]
// T = 15, nums = [1,2,3,4,5]
// It doesn't takes into consideration the starting element

class Solution {
public:
    int minSubArrayLen(int T, vector<int> &nums) {
        int n = nums.size();
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int to_find = T + pre[i];
            auto it = lower_bound(pre.begin(), pre.end(), to_find);
            // Accumulate sum of nums[i] < T
            if(it != pre.end()) { 
                int dis = it - (pre.begin() + i);
                ans = min(ans, dis);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// Solution 
class Solution {
public:
    int minSubArrayLen(int T, vector<int> &nums) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int to_find = T + pre[i];
            auto it = lower_bound(pre.begin(), pre.end(), to_find);
            // Accumulate sum of nums[i] < T
            if(it != pre.end()) { 
                int dis = it - (pre.begin() + i);
                ans = min(ans, dis);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// 1 2 3  4  5
// 0 1 3  6 10 16
// 5 6 8 11 15 21
