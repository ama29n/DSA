#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

// Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i]

class Solution {
public:
    class SegmentTree {
        public:
        int maxN;
        vector<int> seg;
        
        SegmentTree(int n) : maxN(n) {
            seg = vector<int> (maxN * 4 + 10, 0);
        }
        
        void update(int ele) {
            update_util(0, 0, maxN - 1, ele);
        } 
        
        void update_util(int i, int low, int high, int ele) {
            if(low == high) {
                seg[i]++;
                return;
            }
            int mid = low + (high - low) / 2;
            if(ele <= mid) {
                update_util(2 * i + 1, low, mid, ele);
            } else {
                update_util(2 * i + 2, mid + 1, high, ele);
            }
            seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
        }
        
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
    };
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        int offset = 10000;
        int maxi = nums[0];
        for(int i = 0; i < n; i++)
            maxi = max(maxi, nums[i]);
        SegmentTree seg(maxi + offset + 1);
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; i--) {
            int ele = nums[i];
            int count = seg.query(0, ele + offset - 1);
            ans[i] = count;
            seg.update(ele + offset);
        }
        return ans;
    }
};

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