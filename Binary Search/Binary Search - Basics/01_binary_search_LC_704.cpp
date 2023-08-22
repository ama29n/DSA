#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-search/ 

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(nums[m] == target) {
                return m;
            }
            target < nums[m] ? (r = m - 1) : (l = m + 1);
        }
        return -1;
    }
};