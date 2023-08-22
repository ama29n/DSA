#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

// Merge Sort Solution
class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r, vector<int>& index, vector<int>& ans) {
        vector<int> arr(r - l + 1);
        int i = l, j = m + 1, k = 0;
        while(k < arr.size()) {
            int num1 = i > m ? INT_MAX : nums[index[i]];
            int num2 = j > r ? INT_MAX : nums[index[j]];
            arr[k++] = num1 <= num2 ? index[i++] : index[j++];
        }
        for(int idx = 0; idx < arr.size(); idx++)
            index[l + idx] = arr[idx];
    }
    void mergeSort(vector<int>& nums, int l, int r, vector<int>& index, vector<int>& ans) {
        if(l == r)
            return;
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m, index, ans);
        mergeSort(nums, m + 1, r, index, ans);
        int i = l, j = m+ 1, rightCount = 0;
        while(i <= m && j <= r) {
            if (nums[index[j]] < nums[index[i]])
				rightCount++, j++;
			else
                ans[index[i++]] += rightCount;
        }
        while (i <= m)
            ans[index[i++]] += rightCount;
        merge(nums, l, m, r, index, ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> index(n), ans(n);
        for(int i = 0; i < n; i++)
            index[i] = i;
        mergeSort(nums, 0, n - 1, index, ans);
        return ans;
    }
};

// Segment Tree Solution
const int offset = 1E4;
class Solution {
private: 
    int maxN;
    vector<int> seg;
    void seg_update(int i, int low, int high, int node) {
        if(low == high){
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
        int ll = seg_query(2 * i + 1, low, mid, l, r);
        int rr = seg_query(2 * i + 2, mid + 1, high, l, r);
        return ll + rr;
    }
public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        for(auto &it : nums) {
            it += offset;
        }
        maxN = 2 * offset + 1;
        seg.resize(maxN * 4 + 10, 0);
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; i--) {
            ans[i] = seg_query(0, 0, maxN - 1, 0, nums[i] - 1);
            seg_update(0, 0, maxN - 1, nums[i]);
        }
        return ans;
    }
};