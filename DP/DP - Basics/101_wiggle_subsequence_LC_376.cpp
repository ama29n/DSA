#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/wiggle-subsequence/

// Apply DP on difference array
// Time - O(n ^ 2) where n = size of arr
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        for(int i = 1; i < n; i++) { 
            int x = nums[i] - nums[i - 1]; 
            if(x != 0) { arr.push_back(x); }
        }
        n = arr.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            int x = 1;
            for(int j = 0; j < i; j++) {
                if((arr[i] > 0 && arr[j] < 0) || (arr[i] < 0 && arr[j] > 0)) {
                    x = max(x, dp[j] + 1);
                }
            }
            dp[i] = x;
        }
        int ans = 1;
        for(auto it : dp) { ans = max(ans, it + 1); }
        return ans;
    }
};

// Time - O(n) 
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> peak(n, 0), valley(n, 0);
        valley[0] = peak[0] = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                peak[i] = valley[i - 1] + 1;
                valley[i] = valley[i - 1];
            } else if(nums[i] < nums[i - 1]) {
                valley[i] = peak[i - 1] + 1;
                peak[i] = peak[i - 1];
            } else {
                valley[i] = valley[i - 1];
                peak[i] = peak[i - 1];
            }
        }
        return max(valley[n - 1], peak[n - 1]);
    }
};

// Constant Space 
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int valley = 1, peak = 1;
        for(int i = 1; i < n; i++) {
                 if(nums[i] > nums[i - 1]) { peak = valley + 1; }
            else if(nums[i] < nums[i - 1]) { valley = peak + 1; }
        }
        return max(valley, peak);
    }
};
