#include<bits/stdc++.h>
using namespace std;

// Let the index i of the segment tree keep track of the longest increasing subsequence that ends with i.

// The idea is to use segment_tree max, for each of the A[i], query the values smaller than it (a[i] - 1), 
// which will return the maximum LIS present in those values. Then simply update our tree with the newfound solution.

// Once we are done with all the numbers, query the whole tree, which will return the maximum LIS.

const int maxN = 100000 + 1;

class Solution {
public:
    class SegmentTree {
        public:
        vector<int> seg;
        
        SegmentTree() {
            seg = vector<int>(maxN * 4 + 10, 0);
        }
        
        int query(int l, int r) {
            return query_util(0, 0, maxN - 1, l, r);   
        }
        
        int query_util(int i, int low, int high, int l, int r) {
            if(low >= l && high <= r)
                return seg[i];
            if(low > r || high < l)
                return INT_MIN;
            int mid = (low + high) / 2;
            int left = query_util(2 * i + 1, low, mid, l, r);
            int right = query_util(2 * i + 2, mid + 1, high, l, r);
            return max(left, right);
        }
        
        void update(int len, int ele) {
            update_util(0, 0, maxN - 1, ele, len);
        }
        
        void update_util(int i, int low, int high, int ele, int len) {
            if(high == low) {
                seg[i] = len;
                return;
            }
            int mid = (low + high) / 2;
            if(low <= ele && ele <= mid) {
                update_util(2 * i + 1, low, mid, ele, len);
            } else {
                update_util(2 * i + 2, mid + 1, high, ele, len);
            }
            seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
        }
    };
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        SegmentTree seg;
        // Offsetting, the minimum element can be -10000
        for(int i = 0; i < n; i++)
            nums[i] += 10000;
        for(auto it : nums) {
            int longestSequenceBefore = 1 + seg.query(0, it - 1);
            seg.update(longestSequenceBefore, it);
        }
        return seg.query(0, maxN - 1);
    }
};