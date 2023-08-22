#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-a-2d-matrix/ 

// Time Complexity - O(m + n) 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size(), i = 0, j = col - 1;
        while(i < row && j >= 0) {
            int el = matrix[i][j];
            if(el == target) {
                return true;
            }
            if(el > target) {
                j--;
            }
            else i++;
        }
        return false;
    }
};