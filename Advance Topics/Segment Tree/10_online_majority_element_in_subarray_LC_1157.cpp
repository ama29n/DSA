#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/online-majority-element-in-subarray

#define ff  first
#define ss  second

class MajorityChecker {
private:
    int n;
    vector<int> nums;
    vector<vector<int>> index;
    // seg[0] = Majority Element & seg[1] = Count
    vector<pair<int, int>> seg;
    void seg_build(int i, int low, int high) {
        if(low == high) {
            seg[i] = {nums[low], 1};
            return;
        }
        int mid = low + (high - low) / 2;
        seg_build(2 * i + 1, low, mid);
        seg_build(2 * i + 2, mid + 1, high);
        seg[i] = seg_merge(seg[2 * i + 1], seg[2 * i + 2]);
    }
    // Boyer Moore Algorithm
    pair<int, int> seg_merge(pair<int, int> &v1, pair<int, int> &v2) {
        int ele_1 = v1.ff, cnt_1 = v1.ss;
        int ele_2 = v2.ff, cnt_2 = v2.ss;
        if(ele_1 == ele_2) {
            return {ele_1, cnt_1 + cnt_2};
        } else if(cnt_1 > cnt_2) {
            return {ele_1, cnt_1 - cnt_2};
        } else {
            return {ele_2, cnt_2 - cnt_1};
        }
    }
    pair<int, int> seg_query(int i, int low, int high, int l, int r) {
        if(low > r || high < l) {
            return {0, 0};
        }
        if(low >= l && high <= r) {
            return seg[i];
        }
        int mid = low + (high - low) / 2;
        pair<int, int> left = seg_query(2 * i + 1, low, mid, l, r);
        pair<int, int> right = seg_query(2 * i + 2, mid + 1, high, l, r);
        return seg_merge(left, right);
    }
public:
    MajorityChecker(vector<int> &arr) {
        n = arr.size();
        nums = arr;
        index.resize(2 * 1E4 + 1);
        seg.resize(4 * n + 10);
        for(int i = 0; i < n; i++) {
            index[arr[i]].push_back(i);
        }
        seg_build(0, 0, n - 1);
    }
    int query(int left, int right, int threshold) {
        pair<int, int> q = seg_query(0, 0, n - 1, left, right);
        auto &v = index[q.ff];
        int l = lower_bound(v.begin(), v.end(), left) - v.begin();
        int r = upper_bound(v.begin(), v.end(), right) - v.begin();
        if(r - l < threshold) {
            return -1;
        }
        return q.ff;
    }
};

// This is faster somehow
class MajorityChecker {
public:
    // Node Structure
    struct Node {
        public:
        int majority, count;
    };
    // Data Members
    int maxN;
    vector<int> arr;                    // Given array
    vector<Node> seg;                   // Segmnet Tree array
    vector<vector<int>> indices;        // Array to store indices where each element occurs
    // Boyer - Moore Algorithm
    Node merge(Node a, Node b) {
        if(a.majority == b.majority) {
            return {a.majority, a.count + b.count};
        }
        if(a.count > b.count) {
            return {a.majority, a.count - b.count};
        }
        return {b.majority, b.count - a.count};
    }
    // Build Function
    void build(int i, int low, int high) {
        if(low == high) {
            Node node; node.majority = arr[low]; node.count = 1;
            seg[i] = node;
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * i + 1, low, mid);
        build(2 * i + 2, mid + 1, high);
        seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
    }
    Node query_util(int i, int low, int high, int l, int r) {
        if(low > r || high < l) {
            Node node; node.majority = 0; node.count = 0;
            return node;
        }
        if(low >= l && high <= r) {
            return seg[i];
        }
        int mid = low + (high - low) / 2;
        Node ll = query_util(2 * i + 1, low, mid, l, r);
        Node rr = query_util(2 * i + 2, mid + 1, high, l, r);
        return merge(ll, rr);
    }
    // Given Functions to be completed
    MajorityChecker(vector<int> &nums) {
        maxN = nums.size();
        arr = nums;
        seg.resize(maxN * 4 + 10);
        int maxi = 0; for(auto it : nums) { maxi = max(maxi, it); }
        indices.resize(maxi + 1);
        for(int i = 0; i < maxN; i++) indices[nums[i]].push_back(i);
        build(0, 0, maxN - 1);
    }
    int query(int left, int right, int threshold) {
        int ele = query_util(0, 0, maxN - 1, left, right).majority;
        auto &v = indices[ele];
        int l = lower_bound(v.begin(), v.end(), left) - v.begin();
        int r = upper_bound(v.begin(), v.end(), right) - v.begin();
        if(r - l < threshold) {
            return -1;
        }
        return ele;
    }
};