#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1  5  9
    // 10 11 13
    // 12 13 15
    int lessOrEqualToK(int el, vector<vector<int>>& matrix, int n) {
        int c = 0, j = n - 1;
        for(int i = 0; i < n; i++) {
            while(j >= 0 && matrix[i][j] > el) 
                j--;
            c += j + 1;
        }
        return c;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int beg = matrix[0][0], end = matrix[n - 1][n - 1];
        int ans;
        while(beg <= end) {
            int mid = beg + (end - beg) / 2;
            if(lessOrEqualToK(mid, matrix, n) >= k) {
                ans = mid;
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        }
        return ans;
    }
};