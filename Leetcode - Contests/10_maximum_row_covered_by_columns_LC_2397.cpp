#include <bits/stdc++.h>
using namespace std;

// You are given a 0-indexed m x n binary matrix mat and an integer cols, which denotes the number of columns 
// you must choose.

// A row is covered by a set of columns if each cell in the row that has a value of 1 also lies in one of the 
// columns of the chosen set.

// Return the maximum number of rows that can be covered by a set of cols columns.

// Convert each row into a decimal number and store in a vector.
// Then traverse over range 1 << size of column, to go through all permutations having set_bits = cols.
// For each such permutation count number of elements in above generated vector which have set bits at same position.
// Store the maximum answer.

// Time Complexity - (2 ^ n * n)

class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size(), n = mat[0].size();
        vector<int> nums;
        // for(int i = 0; i < m; i++) {
        //     string str;
        //     for(int j = 0; j < n; j++) {
        //         str += (mat[i][j] + '0');
        //     }
        //     int number = stoi(str, nullptr, 2);
        //     nums.push_back(number);
        // }
        for(int i = 0; i < m; i++) {
            int num = 0;
            for(int j = 0; j < n; j++)
                if(mat[i][j] == 1)
                    num += (1 << (n - j - 1));
            nums.push_back(num);
        }
        int range = 1 << n;
        int ans = 0;
        for(int i = 0; i < range; i++) {
            int count = 0;
            if(__builtin_popcount(i) == cols) {
                for(auto it : nums) {
                    if((it | i) == i)
                        count++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};

// Input: 
// mat = 0 0 0 
//       1 0 1
//       0 1 1
//       0 0 1

// cols = 2

// Output: 3

// 000 101 011 001
//  0   5   3   1

// 000 001 010 011 100 101 110 111