#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/closest-subsequence-sum/ 

// TC -> O(2^n) (from find) + O(n * log(n)) (from sort & lower_bound in loop), where n = N / 2
// SC -> O(2 * 2^n), where n = N / 2 

class Solution {
public:
    void find(int i, int n, int sum, vector<int> &v, vector<int> &nums) {
        if(i == n) {
            v.push_back(sum); return;
        }
        find(i + 1, n, sum + nums[i], v, nums);
        find(i + 1, n, sum, v, nums);
    }
    int minAbsDifference(vector<int> &nums, int goal) {
        int n = nums.size();
        vector<int> v1, v2;
        int m = n / 2;
        find(0, m, 0, v1, nums);
        find(m, n, 0, v2, nums);
        sort(v2.begin(), v2.end());
        int ans = INT_MAX;
        for(auto ele : v1) {
            auto it = lower_bound(v2.begin(), v2.end(), (goal - ele));
            // No lower bound found -> last element can give the min dif with ele
            if(it == v2.end()) {
                ans = min(ans, abs(goal - (ele + *(it - 1))));
            } else {
                // Lower bound found
                ans = min(ans, abs(goal - (ele + *it)));
                // If (goal - ele) doesn't exist -> *it will be next greater
                // but *(it - 1) can also give min dif with ele
                if(it != v2.begin())
                    ans = min(ans, abs(goal - (ele + *(it - 1))));
            }     
        }
        return ans;
    }
};
