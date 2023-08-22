#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/next-greater-element-iv/

// For Explanation
// https://leetcode.com/problems/next-greater-element-iv/discuss/2756336/Segment-Tree-oror-CPP-oror-O(n-*-log(n))

// Segment Tree 
class Solution {
public:
    class SegmentTree {
    public:
        int maxN;
        vector<int> seg;
        SegmentTree(int n) : maxN(n) {
            seg = vector<int> (maxN * 4, 0);
        }
        void build(vector<int>& arr) {
            build_util(0, 0, maxN - 1, arr);
        }
        void build_util(int i, int low, int high, vector<int>& arr) {
            if(low == high) {
                seg[i] = arr[low];
                return;
            }
            int mid = (low + high) / 2;
            build_util(i * 2 + 1, low, mid, arr);
            build_util(i * 2 + 2, mid + 1, high, arr);
            seg[i] = max(seg[i * 2 + 1], seg[i * 2 + 2]);
        }
        int query(int l, int ele) {
            return query_util(0, 0, maxN - 1, l, maxN - 1, ele);   
        }
        int query_util(int i, int low, int high, int l, int r, int ele) {
            if(seg[i] <= ele || l > high)
                return -1;
            if(low == high)
                return low;
            int mid = (low + high) / 2;
            int res = query_util(2 * i + 1, low, mid, l, r, ele);
            if(res == -1)
                res = query_util(2 * i + 2, mid + 1, high, l, r, ele);
            return res;
        }
    };
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return {-1};
        vector<int> v(n, -1);
        SegmentTree seg(n);
        seg.build(nums);
        for(int i = 0; i < n - 2; i++) {
            int ff = seg.query(i + 1, nums[i]);
            if(ff != -1) {
                int ss = seg.query(ff + 1, nums[i]);
                if(ss != -1)
                    v[i] = nums[ss];
            }
        }
        return v;
    }
};