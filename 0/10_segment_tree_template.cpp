#include<bits/stdc++.h>
using namespace std;

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
        if(ele <= mid) {
            update_util(2 * i + 1, low, mid, ele, len);
        } else {
            update_util(2 * i + 2, mid + 1, high, ele, len);
        }
        seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
    }
};