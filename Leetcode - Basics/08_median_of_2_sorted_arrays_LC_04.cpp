#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/median-of-two-sorted-arrays 

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums, vector<int> &arr) {
        int n = nums.size(), m = arr.size();
        if(m < n) {
            return findMedianSortedArrays(arr, nums);
        }
        int beg = 0, end = n;
        while(beg <= end) {
            int mid = beg + (end - beg) / 2;
            // (n + m + 1) for odd cases
            // n = 4, m = 5; mid = 2, cut = 5 - mid = 3 
            int cut = (n + m + 1) / 2 - mid;
            // Critical Points
            int l1 = mid == 0 ? INT_MIN : nums[mid - 1];
            int l2 = cut == 0 ? INT_MIN : arr[cut - 1];
            int r1 = mid == n ? INT_MAX : nums[mid];
            int r2 = cut == m ? INT_MAX : arr[cut];
            // Base Case
            if(l1 <= r2 && l2 <= r1) {
                if((n + m) % 2 == 0) {
                    return ((min(r1, r2) + max(l1, l2)) / 2.0);
                } else {
                    return max(l1, l2);
                }
            }
            // Clipping Condition
            if(l1 > r2) {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        return 0.0;
    }
};