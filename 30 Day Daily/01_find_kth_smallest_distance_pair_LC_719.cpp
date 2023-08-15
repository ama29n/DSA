#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-k-th-smallest-pair-distance/

// distance pair -> absolute difference between a pair

class Solution {
public:
    bool check(int x, int k, vector<int> &nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int count = 0;
        while(i < n) {
            while(j < n && nums[j] - nums[i] <= x) j++;
            count += j - i - 1;                           // - 1 as the pairs = n - 1
            i++;
        }
        return count >= k ? true : false;
    }
    int smallestDistancePair(vector<int> &nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int beg = 0, end = nums[n - 1] - nums[0];
        int ans;
        while(beg <= end) {
            int mid = beg + (end - beg) / 2;
            if(check(mid, k, nums)) {
                ans = mid; end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        return ans;
    }
};