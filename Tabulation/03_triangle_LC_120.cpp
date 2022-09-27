#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 2
    // 3 4
    // 6 5 7
    // 4 1 8 3
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m - 1].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = m - 1; i >= 0; i--) {
            int k = triangle[i].size() - 1;
            for(int j = k; j >= 0; j--) {
                if(i == m - 1) {
                    dp[i][j] = triangle[i][j];
                } else {
                    int d = dp[i + 1][j], r = dp[i + 1][j + 1];
                    dp[i][j] = min(d, r) + triangle[i][j];
                }
            }
        }
        return dp[0][0];
    }
};