#include <bits/stdc++.h>
using namespace std;

// Time - O(n * 2n)
class Solution {
    public:
    vector<vector<int>> ans;

    void fn(int idx, vector<int> &nums, vector<int> &helper) {
        if(idx == nums.size()) {
            ans.push_back(helper);
            return;
        } else {
            helper.push_back(nums[idx]);
            fn(idx + 1, nums, helper);
            helper.pop_back();
            fn(idx + 1, nums, helper);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> helper;
        fn(0, nums, helper);
        return ans;
    }
};


// Using bit manipulation
// Time - O((2 ^ n) * n)

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int size = pow(2, n);
    vector<vector<int>> ans;
    for(int i = 0; i < size; i++) {
        vector<int> v;
        for(int j = 0; j < n; j++) {
            if((1 << j) & i)
                v.push_back(nums[j]);
        }
        ans.push_back(v);
    }
    return ans;
}