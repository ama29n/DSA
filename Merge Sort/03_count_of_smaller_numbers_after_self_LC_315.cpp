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