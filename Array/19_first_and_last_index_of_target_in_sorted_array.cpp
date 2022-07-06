#include <bits/stdc++.h>
using namespace std;

// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a 
// given target value.

// If target is not found in the array, return [-1, -1].

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

 vector<int> searchRange(vector<int>& nums, int target) {
    int beg = 0, end = nums.size() - 1;
    int idx = -1;
    while(beg <= end) {
        int mid = beg + (end - beg) / 2;
        if(nums[mid] == target) {
            idx = mid;
            break;
        }
        if(nums[mid] > target)
            end = mid - 1;
        else 
            beg = mid + 1;
    }
    if(idx == -1)
        return {-1, -1};
    int i = idx, j = idx;
    while(i >= 0 && nums[i] == target)
        i--;
    while(j < nums.size() && nums[j] == target)
        j++;
    return {i + 1, j - 1};
}