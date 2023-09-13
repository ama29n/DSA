#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/trapping-rain-water/ 

class Solution {
private:
    int n;
    vector<int> leftMaxims(vector<int> &nums) {
        vector<int> v(n);
        int maxi = nums[0];
        v[0] = maxi;
        for(int i = 1; i < n; i++) {
            if(nums[i] > maxi)
                maxi = nums[i];
            v[i] = maxi;
        }
        return v;
    }
    vector<int> rightMaxims(vector<int> &nums) {
        vector<int> v(n);
        int maxi = nums[n - 1];
        v[n - 1] = maxi;
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] > maxi)
                maxi = nums[i];
            v[i] = maxi;
        }
        return v;
    }
public:
    int trap(vector<int> &height) {
        n = height.size();
        vector<int> l = leftMaxims(height);
        vector<int> r = rightMaxims(height);
        int trappedWater = 0;
        for(int i = 0; i < n; i++) {
            int low = min(l[i], r[i]);
            trappedWater += (low - height[i]);
        }
        return trappedWater;
    }
};