#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-subsequence-score/

class Solution {
public:
    typedef long long ll;
    typedef pair<int, int> p;
    long long maxScore(vector<int>& nums, vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> v(n);
        // Sort both arrays on the basis of 1st array, arrays whose elements will give the sum
        for(int i = 0; i < n; i++) {
            v[i] = {nums[i], arr[i]};
        }
        sort(v.begin(), v.end());
        ll sum = 0, ans = 0;
        // Pq is used to find the minimum
        priority_queue<p, vector<p>, greater<p>> q;
        for(int i = n - 1; i >= 0; i--) {
            sum += v[i][0];
            q.push({v[i][1], v[i][0]});
            if(q.size() == k) {
                ll x = sum * q.top().first;
                sum -= q.top().second;
                if(x > ans) {
                    ans = x;
                }
                q.pop();
            }
        }
        return ans;
    }
};