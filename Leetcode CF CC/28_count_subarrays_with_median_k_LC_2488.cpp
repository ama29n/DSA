#include <bits/stdc++.h>
using namespace std;

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