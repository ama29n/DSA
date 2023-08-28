#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-subsequence-score/

class Solution {
private:
    typedef long long int ll;
public:
    long long maxScore(vector<int> &nums, vector<int> &arr, int k) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = { arr[i], nums[i] };
        }
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        ll cur_sum = 0;
        ll ans = 0;
        for(auto &it : v) {
            int arr_ele = it.first, nums_ele = it.second;
            cur_sum += nums_ele;
            pq.push(nums_ele);
            if(pq.size() == k) {
                ans = max(ans, (cur_sum * arr_ele));
                cur_sum -= pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};