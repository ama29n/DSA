#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/contiguous-array

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        int n = nums.size();
        for(auto &it : nums) {
            if(it == 0) it = -1;
        }
        for(int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        unordered_map<int, int> map;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            // Starting from 0th index the array has equal number of 0s and 1s
            if(nums[i] == 0) {
                ans = max(ans, i + 1);
            } else {
                // If a already existing number is encountered again,
                // it means the subarray has equal number of 0s and 1s
                // Example
                // 0 1 2 3 4
                // 1 1 1 0 0
                // 1 2 3 2 1
                if(map.find(nums[i]) != map.end()) {
                    ans = max(ans, i - map[nums[i]]);
                    // We don't need to update the index
                    // Example
                    //  0  1  2  3  4  5  6  7
                    //  0  0  1  0  0  0  1  1
                    // -1 -2 -1 -2 -3 -4 -3 -2
                } else {
                    map[nums[i]] = i;
                }
            }
        }
        return ans;
    }
}; 