#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/peak-index-in-a-mountain-array/ 

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int beg = 0, end = n - 1;
        while(beg < end) {
            int mid = beg + (end - beg) / 2;
            if(nums[mid] <= nums[mid + 1]) {
                beg = mid + 1;
            } else {
                end = mid;
            }
        }
        return beg;
    }
};