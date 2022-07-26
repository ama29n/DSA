#include <bits/stdc++.h>
using namespace std;

// Also valid for whole negative array
int maxSubArray(vector<int>& nums) {
    int sum = 0, maxEle = INT_MIN, ans = INT_MIN;
    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if(sum < 0)
            sum = 0;
        ans = max(ans, sum);
        maxEle = max(maxEle, nums[i]);
    }
    if(maxEle < 0)
        return maxEle;
    return ans;
}

// Variation
// Maximum Product sub array 
// LC 152

// Brute Force
int maxProduct(vector<int>& nums) {
    int ans = INT_MIN;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int p = 1;
            for(int k = i; k <= j; k++) {
                p *= nums[k];
            }
            ans = max(ans, p);
        }
    }
    return ans;
}

// Optimised




