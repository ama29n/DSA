#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ 

class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int beg = 0, end = n - 1;
        while(beg < end) {
            if(nums[beg] < nums[end]) {
                return nums[beg];
            }
            int mid = beg + (end - beg) / 2;
            if(nums[beg] <= nums[mid]) {
                beg = mid + 1;
            } else {
                end = mid;
            }
        }
        return nums[beg];
    }
};