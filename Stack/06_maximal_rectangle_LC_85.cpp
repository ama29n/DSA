#include <bits/stdc++.h>
using namespace std;

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
    int maximalRectangle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> matrix(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == '1')
                    matrix[i][j] = 1;
        
        int ans = largestRectangleArea(matrix[0]);
        
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1)
                    matrix[i][j] += matrix[i - 1][j];
            }
            int cal = largestRectangleArea(matrix[i]);
            if(cal > ans)
                ans = cal;
        }
        
        return ans;
    }
};