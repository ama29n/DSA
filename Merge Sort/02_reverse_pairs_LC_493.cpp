#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-pairs/
// For explanation - https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22

// Find pairs such that nums[i] > 2 * nums[j] where i < j

// Using merge sort
class Solution {
public:
    void merge(vector<int>& arr, int l, int mid, int r) {
        vector<int> nums(r - l + 1);
        int i = l, j = mid + 1, k = 0;
        while(k < nums.size()) {
            int num1 = i > mid ? INT_MAX : arr[i];
            int num2 = j > r ? INT_MAX : arr[j];
            nums[k++] = num1 <= num2 ? arr[i++] : arr[j++];
        }
        for(int idx = 0; idx < nums.size(); idx++)
            arr[l + idx] = nums[idx];
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

// Multiset Solution, gives TLE
class Solution {
public:
    typedef long long ll;
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        multiset<ll> s;
        for(auto it : nums) {
            auto iter = s.upper_bound((ll)it * 2);
            int dis = distance(iter, s.end());
            ans += dis;
            s.insert((ll)it);
        }
        return ans;
    }
};