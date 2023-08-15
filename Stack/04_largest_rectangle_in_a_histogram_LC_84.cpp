#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-rectangle-in-histogram/ 

// We need next smaller and previous smaller for each element
// In previous smaller for boundary case and for empty stack case, store -1 
// In next smaller for boundary case and for empty stack case, store n

class Solution {
private:
    int n;
    vector<int> nextSmaller(vector<int> &nums) {
        vector<int> next(n, n);
        stack<int> s;
        s.push(n - 1);
        for(int i = n - 2; i >= 0; i--) {
            while(!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return next;
    }
    vector<int> prevSmaller(vector<int> &nums) {
        vector<int> prev(n, -1);
        stack<int> s;
        s.push(0);
        for(int i = 1; i < n; i++) {
            while(!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return prev;
    }
public:
    int largestRectangleArea(vector<int> &heights) {
        n = heights.size();
        vector<int> next = nextSmaller(heights);
        vector<int> prev = prevSmaller(heights);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, (next[i] - prev[i] - 1) * heights[i]);
        }
        return ans;
    }
};