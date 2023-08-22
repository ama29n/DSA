#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/ 

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
            if(nums[beg] < nums[mid]) {
                beg = mid + 1;
            } else if(nums[beg] > nums[mid]) {
                end = mid;
            } else {
                beg++;
            }
        }
        return nums[beg];
    }
};