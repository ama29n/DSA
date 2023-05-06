#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/ 

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
            // [5, 1, 2, 3, 4], t = 1
            // '=' is being used because always 'm' will become equal to 'l'
            if(nums[l] <= nums[m]) { // 4 5 6 7 8 9 1 2 3
                if(target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else { // 7 8 9 1 2 3 4 5 6
                if(target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};