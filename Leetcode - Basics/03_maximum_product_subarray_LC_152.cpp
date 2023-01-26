#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int p = 1;
            for(int j = i; j < n; j++) {
                p *= nums[j];
                ans = max(ans, p);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxProduct(vector<int> A) {
        int n = A.size(), res = A[0], l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            l =  (l ? l : 1) * A[i];
            r =  (r ? r : 1) * A[n - 1 - i];
            res = max(res, max(l, r));
        }
        return res;
    }
};