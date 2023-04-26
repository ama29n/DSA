#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-pairs/

// For explanation - https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22

// Find pairs such that nums[i] > 2 * nums[j] where i < j

// Time complexity O(n log n)

// Segment Tree Solution
class Solution {
private:
    int maxN;
    vector<int> seg;
    void seg_update(int i, int low, int high, int node) {
        if(low == high) {
            seg[i]++;
            return;
        }
        int mid = low + (high - low) / 2;
        if(node <= mid) {
            seg_update(2 * i + 1, low, mid, node);
        } else {
            seg_update(2 * i + 2, mid + 1, high, node);
        }
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    int seg_query(int i, int low, int high, int l, int r) {
        if(low > r || high < l) {
            return 0;
        }
        if(low >= l && high <= r) {
            return seg[i];
        }
        int mid = low + (high - low) / 2;
        int left = seg_query(2 * i + 1, low, mid, l, r);
        int right = seg_query(2 * i + 2, mid + 1, high, l, r);
        return left + right;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        maxN = n;
        seg.resize(4 * n + 10, 0);
        vector<vector<int>> arr(n);
        for(int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }
        sort(arr.begin(), arr.end());
        int j = 0, ans = 0;
        for(auto it : arr) {
            int ele = it[0], idx = it[1];
            while(j < n && ele > 2 * (long) arr[j][0]) {
                seg_update(0, 0, maxN - 1, arr[j][1]);
                j++;
            }
            ans += seg_query(0, 0, maxN - 1, idx + 1, maxN - 1);
        }
        return ans;
    }
};

// Solution for 0 <= nums[i] <= 1E5
typedef long long ll;  
class Solution {
private:
    ll maxN;
    vector<ll> seg;
    void seg_update(int i, int low, int high, int node) {
        if(low == high) {
            seg[i]++;
            return;
        }
        int mid = low + (high - low) / 2;
        if(node <= mid) {
            seg_update(2 * i + 1, low, mid, node);
        } else {
            seg_update(2 * i + 2, mid + 1, high, node);
        }
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
    ll seg_query(int i, int low, int high, int l, int r) {
        if(low > r || high < l) {
            return 0;
        }
        if(low >= l && high <= r) {
            return seg[i];
        }
        ll mid = low + (high - low) / 2;
        ll left = seg_query(2 * i + 1, low, mid, l, r);
        ll right = seg_query(2 * i + 2, mid + 1, high, l, r);
        return left + right;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        for(auto it : nums) cout << it << " ";
        maxN = 1E4 + 1;
        seg.resize(4 * maxN + 10, 0);
        int ans = 0;
        for(auto it : nums) {
            ans += seg_query(0, 0, maxN - 1, 2 * it + 1, maxN - 1);
            seg_update(0, 0, maxN - 1, it);
        }
        return ans;
    }
};