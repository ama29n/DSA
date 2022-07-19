#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int size = 1 << n;

    vector<vector<int>> ans;

    // Outer Loop for all subsets which are equal to 2 ^ N
    for(int i = 0; i < size; i++) {
        vector<int> v;
        // Inner loop for selecting the elements which are set 
        for(int j = 0; j < n; j++) {
            if((1 << j) & i)
                v.push_back(nums[j]);
        }
        ans.push_back(v);
    }
    return ans;
}

// Time - O((2 ^ N) * N)