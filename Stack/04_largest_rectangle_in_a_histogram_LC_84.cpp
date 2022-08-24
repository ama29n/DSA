#include <bits/stdc++.h>
using namespace std;

// We need next smaller and previous smaller for each element
// In previous smaller for boundary case and for empty stack case, store -1 
// In next smaller for boundary case and for empty stack case, stor n

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n), prev(n);
        stack<int> s;
        
        prev[0] = -1;
        s.push(0);
        for(int i = 1; i < n; i++) {
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            prev[i] = !s.empty() ? s.top() : -1;
            s.push(i);
        }
        
        while(!s.empty())
            s.pop();
        
        next[n - 1] = n;
        s.push(n - 1);
        for(int i = n - 2; i >= 0; i--) {
            while(!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            next[i] = !s.empty() ? s.top() : n;
            s.push(i);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, (next[i] - prev[i] - 1) * heights[i]);
        }
        
        return ans;
    }
};