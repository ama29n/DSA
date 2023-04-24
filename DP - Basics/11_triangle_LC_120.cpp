#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/triangle/ 

class Solution {
public:
    int path(int rows, int ele, vector<vector<int>>& triangle) {
        if(rows == triangle.size() - 1) {
            return triangle[rows][ele];
        }
        int down = path(rows + 1, ele, triangle);
        int diaDown = path(rows + 1, ele + 1, triangle);
        return triangle[rows][ele] + min(down, diaDown);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1) {
            return triangle[0][0];
        }
        int rows = triangle.size();
        return path(0, 0, triangle);
    }
};

// Memoization
class Solution {
public:
    int find(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(j >= triangle[i].size()) {
            return 10001;
        }
        if(i == triangle.size() - 1) {
            return triangle[i][j];
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int bottom = find(i + 1, j, triangle, dp);
        int bottomRight = find(i + 1, j + 1, triangle, dp);
        return dp[i][j] = min(bottom, bottomRight) + triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m - 1].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return find(0, 0, triangle, dp);
    }
};

// Tabulation
class Solution {
public:
    // 2
    // 3 4
    // 6 5 7
    // 4 1 8 3
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();
        int dp[m][n]; memset(dp, 0, sizeof dp);
        for(int i = m - 1; i >= 0; i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                if(i == m - 1) {
                    dp[i][j] = triangle[i][j];
                } else {
                    int x = dp[i + 1][j];
                    int y = dp[i + 1][j + 1];
                    dp[i][j] = min(x, y) + triangle[i][j];
                }
            }
        }
        return dp[0][0];
    }
};