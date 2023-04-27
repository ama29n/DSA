#include<bits/stdc++.h>
using namespace std;

// Finding maximum in range
class SegmentTree {
public:
    int maxN;
    vector<int> seg;
    SegmentTree(int n) : maxN(n) {
        seg = vector<int> (maxN * 4 + 10, 0);
    }
    void build(int i, int low, int high, vector<int>& arr) {
        if(low == high) {
            seg[i] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(i * 2 + 1, low, mid, arr);
        build(i * 2 + 2, mid + 1, high, arr);
        seg[i] = max(seg[i * 2 + 1], seg[i * 2 + 2]);
    }
    int query(int i, int low, int high, int l, int r) {
        if(low >= l && high <= r) {
            return seg[i];
        }
        if(low > r || high < l) {
            return INT_MIN;
        }
        int mid = (low + high) / 2;
        int left = query(2 * i + 1, low, mid, l, r);
        int right = query(2 * i + 2, mid + 1, high, l, r);
        return max(left, right);
    }
    void update(int i, int low, int high, int ele, int len) {
        if(high == low) {
            seg[i] = len;
            return;
        }
        int mid = (low + high) / 2;
        if(ele <= mid) {
            update(2 * i + 1, low, mid, ele, len);
        } else {
            update(2 * i + 2, mid + 1, high, ele, len);
        }
        seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
    }
};

// Finding sum of range
class SegmentTree {
public:
    int maxN;
    vector<int> seg;
    SegmentTree(int n) : maxN(n) {
        seg = vector<int> (maxN * 4 + 10, 0);
    }
    void build(int i, int low, int high, vector<int>& arr) {
        if(low == high) {
            seg[i] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(i * 2 + 1, low, mid, arr);
        build(i * 2 + 2, mid + 1, high, arr);
        seg[i] = seg[i * 2 + 1] + seg[i * 2 + 2];
    }
    int query(int i, int low, int high, int l, int r) {
        if(low >= l && high <= r) {
            return seg[i];
        }
        if(low > r || high < l) {
            return 0;
        }
        int mid = (low + high) / 2;
        int left = query(2 * i + 1, low, mid, l, r);
        int right = query(2 * i + 2, mid + 1, high, l, r);
        return left + right;
    }
    void update(int i, int low, int high, int ele, int len) {
        if(high == low) {
            seg[i] = len;
            return;
        }
        int mid = (low + high) / 2;
        if(ele <= mid) {
            update(2 * i + 1, low, mid, ele, len);
        } else {
            update(2 * i + 2, mid + 1, high, ele, len);
        }
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }
};

// Segment Tree with Node class
class Node {
public:
    int val;
    Node *left, *right;
    Node() {
        val = 0; 
        left = right = NULL;
    }
    Node(int _val) {
        val = _val;
        left = right = NULL;
    }
};
class SegmentTree {
public:
    int maxN;
    Node *root;
    SegmentTree(int n) : maxN(n) {
        root = new Node();
    }
    void build(Node *root, int low, int high, vector<int> &nums) {
        if(!root->left) {
            root->left = new Node();
        }
        if(!root->right) {
            root->right = new Node();
        }
        if(low == high) {
            root->val = nums[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(root->left, low, mid, nums);
        build(root->right, mid + 1, high, nums);
        root->val = root->left->val + root->right->val;
    }
    int query(Node *root, int low, int high, int l, int r) {
        if(low > r || high < l) {
            return 0;
        }
        if(low >= l && high <= r) {
            return root->val;
        }
        int mid = low + (high - low) / 2;
        int left = query(root->left, low, mid, l, r);
        int right = query(root->right, mid + 1, high, l, r);
        return left + right;
    }
    void update(Node *root, int low, int high, int node, int val) {
        if(low == high) {
            root->val = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if(node <= mid) {
            update(root->left, low, mid, node, val);
        } else {
            update(root->right, mid + 1, high, node, val);
        }
        root->val = root->left->val + root->right->val;
    }
};