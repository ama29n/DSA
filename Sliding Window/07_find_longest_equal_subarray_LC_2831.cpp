#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-longest-equal-subarray/

// 1 <= nums[i] <= nums.length 

// Maintain a list of indiices for every unique nums[i]
// Apply Sliding Window on each such list
// (arr[j] - arr[i]) - (j - i) -> Length of consecutive subarray -> <= k
// (j - i + 1) is maximised

class Solution {
public:
    int longestEqualSubarray(vector<int> &nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, vector<int>> map;
        for(int i = 0; i < n; i++) {
            map[nums[i]].push_back(i);
        }
        for(auto &it : map) {
            vector<int> &arr = it.second;
            int i = 0, j = 0;
            while(j < arr.size()) {
                int consecutive = (arr[j] - arr[i]) - (j - i);
                if(consecutive <= k) {
                    ans = max(ans, (j - i + 1));
                    j++;
                } else {
                    i++;
                }
            }
        }
        return ans;
    }
};

