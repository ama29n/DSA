#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        int cur_sum = 0, min_len = INT_MAX;
        while(j < n) {
            cur_sum += nums[j];
            while(cur_sum >= target) {
                min_len = min(min_len, j - i + 1);
                cur_sum -= nums[i];
                i++;
            }
            j++;
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};