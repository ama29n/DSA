#include <bits/stdc++.h>
using namespace std; 

// https://leetcode.com/problems/maximal-rectangle/

class Solution {
private:
    int m, n;
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
    int largestRectangleArea(vector<int> &heights) {
        vector<int> next = nextSmaller(heights);
        vector<int> prev = prevSmaller(heights);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, (next[i] - prev[i] - 1) * heights[i]);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>> &grid) {
        m = grid.size(); n = grid[0].size();
        vector<vector<int>> matrix(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == '1')
                    matrix[i][j] = 1;
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i != 0 && matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
            int temp = largestRectangleArea(matrix[i]);
            ans = max(ans, temp);
        }
        return ans;
    }
};