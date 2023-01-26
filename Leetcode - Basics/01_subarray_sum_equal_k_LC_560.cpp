#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subarray-sum-equals-k/

// Time - O(n ^ 2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int cur_sum = 0;
            for(int j = i; j < n; j++) {
                cur_sum += nums[j];
                if(cur_sum == k)
                    ans++;
            }
        }
        return ans;
    }
};