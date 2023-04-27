#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-pairs/

// For explanation - https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22

// Merge Sort Solution
class Solution {
public:
    vector<int> arr;
    void merge(int l, int m, int r) {
        int n = r - l + 1;
        vector<int> v(n);
        int i = l, j = m + 1, k = 0;
        while(k < n) {
            int x = i <= m ? arr[i] : INT_MAX;
            int y = j <= r ? arr[j] : INT_MAX;
            v[k++] = x <= y ? arr[i++] : arr[j++]; 
        }
        for(int idx = 0; idx < n; idx++) {
            arr[l + idx] = v[idx];
        }
    }
    int mergeSort(int l, int r) {
        if(l >= r) {
            return 0;
        }
        int m = l + ((r - l) / 2);
        int ans = mergeSort(l, m) + mergeSort(m + 1, r);
        int i = l, j = m + 1;
        while(i <= m && j <= r) {
            if(arr[i] > (long long) arr[j] * 2) {
                ans += m - i + 1;
                j++;
            } else { i++; }
        }
        merge(l, m, r);
        return ans;
    }
    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        arr = nums;
        return mergeSort(0, n - 1);
    }
};

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