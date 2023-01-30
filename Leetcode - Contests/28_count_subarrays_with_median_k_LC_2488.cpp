#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-subarrays-with-median-k/

// Array contains nodes from 1 to n, thus there will only be 1 k present in the array
 
// If we convert all strictly smaller elements to -1 and strictly greater elements to 1 then,
// For odd subarrays around k -> sum = 0
// For even subarrays around k -> sum = 1 (If k = 2, then for [1, 2, 3, 4] -> [-1, 0, 1, 1], sum = 1) 

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(auto& it : nums) {
            it = it == k ? 0 : it > k ? 1 : -1;
        }
        int idx = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                idx = i; break;
            }
        }
        unordered_map<int, int> map;
        int sum = 0;
        for(int i = idx; i >= 0; i--) { // going left
            sum += nums[i]; map[sum]++;
        }
        int ans = 0; sum = 0;
        for(int i = idx; i < n; i++) { // going right 
            sum += nums[i];
            int x = -1 * sum;
            ans += map[x];
            x += 1; 
            ans += map[x];
        }
        return ans;
    }
}; 