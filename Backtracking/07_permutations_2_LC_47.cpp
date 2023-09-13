#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/permutations-ii/ 

class Solution {
private:
    vector<vector<int>> ans;
    void dfs(int i, int n, vector<int> &nums) {
        if(i == n) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> set;
        for(int j = i; j < n; j++) {
            if(set.find(nums[j]) == set.end()) {
                set.insert(nums[j]);
                swap(nums[i], nums[j]);
                dfs(i + 1, n, nums);
                swap(nums[i], nums[j]);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(0, nums.size(), nums);
        return ans;
    }
};
