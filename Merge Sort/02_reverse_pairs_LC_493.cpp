#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-pairs/
// For explanation - https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22

// Find pairs such that nums[i] > 2 * nums[j] where i < j

// Using merge sort
class Solution {
public:
    void merge(vector<int>& arr, int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        vector<int> subarr1, subarr2;
        for(int i = 0; i < n1; i++)
            subarr1.push_back(arr[l + i]);
        for(int i = 0; i < n2; i++)
            subarr2.push_back(arr[mid + 1 + i]);
        int i = 0, j = 0, k = l;
        while(i < n1 && j < n2) {
            if(subarr1[i] <= subarr2[j])
                arr[k++] = subarr1[i++];
            else
                arr[k++] = subarr2[j++];
        }
        while(i < n1)
            arr[k++] = subarr1[i++];
        while(j < n2)
            arr[k++] = subarr2[j++];
    }
    int mergeSort(vector<int>& nums, int l, int r) {
        if(l == r)
            return 0;
        int mid = l + (r - l) / 2;
        int count = mergeSort(nums, l, mid) + mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1;
        while(i <= mid && j <= r) {
            if(nums[i] > (long)nums[j] * 2)
                count += mid - i + 1, j++;
            else
                i++;
        }
        merge(nums, l, mid , r);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() -  1);
    }
};