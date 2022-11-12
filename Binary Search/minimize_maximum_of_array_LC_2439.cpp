#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimize-maximum-of-array/

class Solution {
public:
    typedef long long ll;
    // (sum + i) / (i + 1) is equal to ceil((double)sum / (i + 1))
    int minimizeArrayValue(vector<int>& nums) {
        ll minmax = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ll avg = (sum + i) / (i + 1);
            minmax = max(minmax, avg);
        }
        return minmax;
    }
};