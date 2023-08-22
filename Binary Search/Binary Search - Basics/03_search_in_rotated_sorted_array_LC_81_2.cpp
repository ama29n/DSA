#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/ 

class Solution {
public:
    // 1 0 1 1 1
    bool search(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(nums[m] == target) {
                return true;
            }
            if((nums[m] == nums[l]) && (nums[m] == nums[r])) {
                l++; r--;
            } else if(nums[l] <= nums[m]) {
                if(target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if(target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return false;
    }
};