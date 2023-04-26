#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-increasing-subsequence/ 

// Let the index i of the segment tree keep track of the longest increasing subsequence that ends with i.
// The idea is to use segment_tree max, for each of the A[i], query the values smaller than it (a[i] - 1), 
// which will return the maximum LIS present in those values. Then simply update our tree with the newfound solution.
// Once we are done with all the numbers, query the whole tree, which will return the maximum LIS.

const int offset = 1E4;

class Solution {
private:
    int n;
    int maxN = 2E4;
    vector<int> seg;
    int query(int i, int low, int high, int l, int r) {
        if(low > r || high < l) {
            return 0;
        }
        if(low >= l && high <= r) {
            return seg[i];
        }
        int mid = low + (high - low) / 2;
        int ll = query(2 * i + 1, low, mid, l, r);
        int rr = query(2 * i + 2, mid + 1, high, l, r);
        return max(ll, rr);
    }
    void update(int i, int low, int high, int node, int val) {
        if(low == high) {
            seg[i] = max(seg[i], val);
            return;
        }
        int mid = low + (high - low) / 2;
        if(node <= mid) {
            update(2 * i + 1, low, mid, node, val);
        } else {
            update(2 * i + 2, mid + 1, high, node, val);
        }
        seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        for(auto &it : nums) {
            it += offset;
        }
        seg.resize(maxN * 4 + 10, 0);
        for(auto it : nums) {
            int x = query(0, 0, maxN, 0, it - 1);
            update(0, 0, maxN, it, x + 1);
        }
        return query(0, 0, maxN, 0, maxN);
    }
};