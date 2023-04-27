#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-excellent-pairs/

class Solution {
public:
    typedef long long ll;
    long long countExcellentPairs(vector<int> &nums, int k) {
        unordered_set<int> set(nums.begin(), nums.end());
        vector<int> v;
        for(auto it : set) {
            v.push_back(__builtin_popcount(it));
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        for(auto ele : v) {
            ll dis = v.end() - lower_bound(v.begin(), v.end(), k - ele);
            ans += dis;
        }
        return ans;
    }
};