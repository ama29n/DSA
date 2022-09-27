#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n - 1) {
                    dp[i][j] = 1;
                } else {
                    int down = 0, right = 0;
                    if(i < m - 1)
                        down = dp[i + 1][j];
                    if(j < n - 1)
                        right = dp[i][j + 1];
                    dp[i][j] = down + right;
                }
            }
        }
        return dp[0][0];
    }
};