// Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

// Write an algorithm to minimize the largest sum among these m subarrays.

// Input: nums = [7,2,5,10,8], m = 2
// Output: 18
// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.

// Input: nums = [1,4,4], m = 3
// Output: 4

#include<bits/stdc++.h>
using namespace std;

bool check(int bar, int m, vector<int> &nums) {

    int count = 0, sum = 0;
    for (auto it : nums){
        sum += it;
        if (sum == bar) { count++; sum = 0; }
        else if (sum > bar) {count++; sum = it; }
    }
    if (sum > 0) count++;
    if (count <= m) return true;
    return false;
}

int splitArray(vector<int> &nums, int m) {

    int beg = INT_MIN, end = 0, ans;
    for (auto it : nums) {
        end += it;
        if (it > beg) beg = it;
    }
    while (beg <= end) {
        int mid = beg + (end - beg) / 2;
        if (check(mid, m, nums)){
            ans = mid;
            end = mid - 1;
        }
        else beg = mid + 1;
    }
    return ans;
}