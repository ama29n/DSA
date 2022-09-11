#include <bits/stdc++.h>
using namespace std;

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]

// Approach
// The queue will store elements of the window in ascending order 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      deque<int> q;
      vector<int> ans;
      
      for(int i = 0; i < nums.size(); i++) {
        while(!q.empty() && nums[i] > nums[q.back()])
            q.pop_back();
        
        if(!q.empty() && i - q.front() == k) 
            q.pop_front();
          
        q.push_back(i);

        if(i >= k - 1)
            ans.push_back(nums[q.front()]);
      }

      return ans;
  }
};