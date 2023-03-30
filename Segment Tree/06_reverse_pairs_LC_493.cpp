#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-pairs/
// For explanation - https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22

// Find pairs such that nums[i] > 2 * nums[j] where i < j

// Time complexity O(n log n)

// Segment Tree Solution
class Solution {
public:
    typedef long long ll;
    class SegmentTree {
        public:
        // Data Members
        int maxN;
        vector<int> seg;
        // Constructor
        SegmentTree(int n) : maxN(n) {
            seg = vector<int> (maxN * 4 + 10, 0);
        }
        // Member Functions
        int query(int l, int r) {
            return query_util(0, 0, maxN - 1, l, r);
        }
        int query_util(int i, int low, int high, int l, int r) {
            if(low >= l && high <= r)
                return seg[i];
            if(low > r || high < l)
                return 0;
            int mid = low + (high - low) / 2;
            int left = query_util(2 * i + 1, low, mid, l, r);
            int right = query_util(2 * i + 2, mid + 1, high, l, r);
            return left + right;
        }
        void update(int index) {
            update_util(0, 0, maxN - 1, index);
        }
        void update_util(int i, int low, int high, int index) {
            if(low == high) {
                seg[i] = 1;
                return;
            }
            int mid = low + (high - low) / 2;
            if(index <= mid) {
                update_util(2 * i + 1, low, mid, index);
            } else {
                update_util(2 * i + 2, mid + 1, high, index);
            }
            seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
        }
    };
    // Given Function to be completed
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        SegmentTree seg(n);
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++)
            arr[i] = {nums[i], i};
        sort(arr.begin(), arr.end());
        int j = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            int ele = arr[i].first, idx = arr[i].second;
            while(j < n && ele > (ll)arr[j].first * 2) {
                seg.update(arr[j].second);
                j++;
            }
            int count = seg.query(idx + 1, n - 1);
            ans += count;
        }
        return ans;
    }
};