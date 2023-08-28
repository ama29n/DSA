#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sliding-window-maximum/ 

class Solution {
private:
    deque<int> q;
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            // Queue will store index of elements in ascending order
            // Delete small elements from right side
            while(!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }

            // If the leftmost element is now out of window (also it is the greatest)
            if(!q.empty() && i - q.front() == k) {
                q.pop_front();
            }

            // Insert current element into the queue
            q.push_back(i);

            if(i >= k - 1) {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};

// Accessing Elements - O(1)
// Insertion or removal of elements - O(N)
// Insertion or removal of elements at start or end - O(1)

// The deque Q is      - 15, 20, 10, 30
// Q.size()            - 4
// Q.at(2)             - 10
// Q.front()           - 15
// Q.back()            - 30
// Q.pop_front()       - 20, 10, 30
// Q.pop_back()        - 20, 10