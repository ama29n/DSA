#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/ 

class Solution {
private:
    int n;
    bool check(int cap, vector<int> &nums, int maxi) {
        int count = 0;
        for(auto &it : nums) {
            count += (it / cap);
            if(it % cap == 0) count --;
        }
        if(count <= maxi) return true;
        return false;
    }
public:
    int minimumSize(vector<int> &nums, int maxi) {
        n = nums.size();
        int beg = 1, end = 0;
        for(auto it : nums) end = max(end, it);
        int ans;
        while(beg <= end) {
            int cap = beg + (end - beg) / 2;
            if(check(cap, nums, maxi)) {
                ans = cap;
                end = cap - 1;
            } else {
                beg = cap + 1;
            }
        }
        return ans;
    }
};