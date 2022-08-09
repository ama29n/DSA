#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> v;
        for(auto& it : s) {
            int x = __builtin_popcount(it);
            v.push_back(x);
        }
        
        sort(v.begin(), v.end());
        
        ll ans = 0;
        for(int i = 0; i < v.size(); i++) {
            auto it = lower_bound(v.begin(), v.end(), k - v[i]);
            ans += v.end() - it;
        }
        
        return ans;
    }
};