#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

class Solution {
private:
    #define ll long long
    int n;
    bool check(int mid, vector<int> &nums, ll k) {
        ll count = 0;
        for(auto it : nums) {
            count += (it / mid);
        }
        if(count >= k) return true;
        return false;
    }
public:
    int maximumCandies(vector<int> &candies, long long k) {
        n = candies.size();
        int beg = 1, end = 0;
        for(auto it : candies) end = max(end, it);
        int ans = 0;
        while(beg <= end) {
            int mid = beg + (end - beg) / 2;
            if(check(mid, candies, k)) {
                ans = mid;
                beg = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};