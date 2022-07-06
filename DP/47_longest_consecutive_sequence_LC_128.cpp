#include<bits/stdc++.h>
using namespace std;

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.


// Dp approach 
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> arr(n, 1);
    for(int i = 1; i < n; i++) {
        int maxi = i;
        for(int j = 0; j < i; j++) {
            if(nums[i] == nums[j] + 1)
                arr[i] = arr[j] + 1;
        }
    }
    int ans = 0;
    for(auto it : arr)
        ans = max(it, ans);
    return ans;
}

// Space - O(n)
// Time - O(n ^ 2)



// O(n) Solution 

int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return n;
        unordered_set<int> s;
        for(auto it : nums)
            s.insert(it);
        int maxCount = 0;
        for(auto it : s) {
            // If it - 1 element exists it means it has been considered in a sequence
            if(s.find(it - 1) != s.end())
                continue;
            // If it - 1 doesn't exists it means it is a new sequence 
            int j = 1;
            while(s.find(it + j) != s.end())
                j++;
            maxCount = max(maxCount, j);
        }
        return maxCount;
    }   
