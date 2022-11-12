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








// If there are n elements in the array, the segment tree can have 4 * n nodes
int arr[100005], seg[4 * 100005];

// Function to build segment tree
void build(int i, int low, int high) {
    if(low == high) {
        seg[i] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(i * 2 + 1, low, mid);
    build(i * 2 + 2, mid + 1, high);
    seg[i] = max(seg[i * 2 + 1], seg[i * 2 + 2]);
}

// Function to find maximum in range 
int find(int i, int low, int high, int l, int r) {
    // l and r is the range we need to find maximum in 

    // If the interval lies in range
    if(low >= l && high <= r)
        return seg[i];

    // If the interval lies completely outside the range
    if(high < l || low > r)
        return INT_MIN;

    // If the interval lies partially in the range 
    int mid = (low + high) / 2;
    int left = find(i * 2 + 1, low, mid, l, r);
    int right = find(i * 2 + 2, mid + 1, high, l, r);

    return max(left, right);
}

// Function if we update an element in the array
void update(int i, int index, int val, int low, int high) {
    if(high == low) {
        seg[i] = val;
        return;
    }
    int mid = (low + high) / 2;
    if(low <= index && index <= mid) {
        update(2 * i + 1, index, val, low, mid);
    } else {
        update(2 * i + 2, index, val, mid + 1, high);
    }
    seg[i] = max(seg[i * 2 + 1], seg[i * 2 + 2]);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // Build Tree
    build(0, 0, n - 1);

    // Number of queries
    int q;
    cin >> q;

    while(q--) {
        // Range
        int l, r;
        cin >> l >> r;

        // Finding maximum in the range l and r
        int maxi = find(0, 0, n - 1, l, r);

        cout << maxi << endl;
    }
}

// Input
// 10
// 8 2 5 1 4 5 3 9 6 10
// 5
// 0 9
// 2 8
// 1 5
// 3 4 
// 7 7

// Output
// 10
// 9
// 5
// 4
// 9