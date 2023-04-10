#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/permutations-ii/ 

class Solution {
public:
    vector<vector<int>> ans;
    
    void permutation(vector<int> &nums, int l, int r) {
        if(l == r) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int i = l; i < r; i++) {
            
            if(s.find(nums[i]) == s.end()) {
                
                s.insert(nums[i]);
                swap(nums[i], nums[l]);
                permutation(nums, l + 1, r);
                swap(nums[i], nums[l]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        permutation(nums, 0, nums.size());
        return ans;
    }
};