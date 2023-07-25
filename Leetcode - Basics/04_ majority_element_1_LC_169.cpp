#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/majority-element/

// Boyer Moore Voting algorithm  

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int fre = 0, ele;
        for(auto it : nums) {
            if(fre == 0) {
                ele = it;
            }
            it == ele ? fre++ : fre--;
        }
        return ele;
    }
};

// Similar Problems 

// 1. https://leetcode.com/problems/minimum-index-of-a-valid-split/ 

class Solution {
public:
    int minimumIndex(vector<int> &nums) {
        int n = nums.size();
        int ele, fre = 0;
        for(auto it : nums) {
            if(fre == 0) ele = it;
            ele == it ? fre++ : fre--;
        }
        fre = 0;
        for(auto it : nums) if(it == ele) fre++;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == ele) count++;
            int rem_count = fre - count;
            if(count > (i + 1 - count) && rem_count > (n - i - 1 - rem_count)) {
                return i;
            }
        }   
        return -1;
    }
};