#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> pre(n, 0);
        for(int i = 0; i < n; i++) {
            pre[i] = i - 1 < 0 ? nums[i] : pre[i - 1] + nums[i];
        }
        unordered_map<int, int> map;
        int ans = 0;
        for(auto it : pre) {
            ans += map[it - k];
            if(it == k) {
                ans++;
            }
            map[it]++;
        }
        return ans;
    }
};