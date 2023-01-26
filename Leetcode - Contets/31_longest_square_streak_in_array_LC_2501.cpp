#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-square-streak-in-an-array

// Square streak is a subsequence such that after sorting, all elements are square of previous element, except the first one

// DP pattern of longest sequence but here there is a relation between elements, thus map can be used
class Solution {
public:
    typedef long long ll;
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        unordered_map<int, int> map;
        // Start from big to small
        for(int i = 0; i < n; i++) {
            // If square is not found then, max sequence = 1
            if(map.find((ll)nums[i] * (ll)nums[i]) == map.end()) {
                map[nums[i]] = 1;
            } else {
                map[nums[i]] = map[nums[i] * nums[i]] + 1;
            }
        }
        int ans = 1;
        for(auto it : map)
            ans = max(ans, it.second);
        return ans == 1 ? -1 : ans;
    }
};