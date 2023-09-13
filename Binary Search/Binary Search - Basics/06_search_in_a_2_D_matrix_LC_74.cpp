#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix/ 

// Time Complexity - O(m + n) 

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int T) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while(i < m && j >= 0) {
            int &ele = matrix[i][j];
            if(ele == T) {
                return true;
            }
            if(ele > T) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};