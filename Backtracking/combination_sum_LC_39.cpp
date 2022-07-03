// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations 
// of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency 
// of at least one of the chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void combination(vector<int> &nums, int idx, int t, vector<int> v) {
        
        if(idx == nums.size()){
            if(t == 0)
                ans.push_back(v);
            return;
        }
        
        if(nums[idx] <= t) {
            v.push_back(nums[idx]);
            combination(nums, idx, t - nums[idx], v);
            v.pop_back();
        }
        
        combination(nums, idx + 1, t, v);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        combination(candidates, 0, target, v);
        return ans;
    }
};