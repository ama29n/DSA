#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/ 

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            if(nums[l] < nums[r]) {
                break;
            }
            int m = l + (r - l) / 2;
            if(nums[l] == nums[m]) {
                l++; continue;
            }
            if(nums[l] < nums[m]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};