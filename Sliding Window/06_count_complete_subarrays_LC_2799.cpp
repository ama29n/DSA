#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-complete-subarrays-in-an-array/ 

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> map(2000 + 10, 0);
        int unique = 0;
        for(auto it : nums) {
            if(map[it] == 0) unique++;
            map[it]++;
        }
        map.assign(2000 + 10, 0);
        int count = 0, ans = 0;
        int i = 0, j = 0;
        while(j < n) {
            if(map[nums[j++]]++ == 0) {
                count++;
            }
            while(count == unique || (count == unique && j == n - 1)) {
                int m = n - j; 
                ans += (m + 1);
                if(map[nums[i++]]-- == 1) {
                    count--;
                }
            }
        }
        return ans;
    }
};