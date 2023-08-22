#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-consecutive-sequence 

// Dp approach 
int longestConsecutive(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> arr(n, 1);
    for(int i = 1; i < n; i++) {
        int maxi = i;
        for(int j = 0; j < i; j++) {
            if(nums[i] == nums[j] + 1) {
                arr[i] = arr[j] + 1;
            }
        }
    }
    int ans = 0;
    for(auto it : arr) {
        ans = max(it, ans);
    }
    return ans;
}
// Space - O(n)
// Time - O(n ^ 2)

// O(n) Solution 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set(nums.begin(), nums.end());
        int max_count = 0;
        for(auto it : set) {
            // If it - 1 element exists it means it has been considered in a sequence
            if(set.find(it - 1) != set.end()) {
                continue;
            }
            // If it - 1 doesn't exists it means it is a new sequence 
            int j = 1;
            while(set.find(it + j) != set.end()) {
                j++;
            }
            max_count = max(max_count, j);
        }
        return max_count;
    }
};