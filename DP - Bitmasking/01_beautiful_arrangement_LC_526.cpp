#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/beautiful-arrangement/

class Solution {
public:
    int n;
    int dp[16][32770];
    bool check(int a, int b) {
        return a % b == 0 || b % a == 0;
    }
    int dfs(int i, int mask) {
        if(mask == (1 << n) - 1) {
            return 1;
        }
        if(dp[i][mask] == -1) {
            dp[i][mask] = 0;
            for(int j = 1; j <= n; j++) {
                int bit = j - 1;
                if(((1 << bit) & mask) == 0 && (mask == 0 || check(i, j))) {
                    dp[i][mask] += dfs(i + 1, mask | (1 << bit));
                }
            }
        }
        return dp[i][mask];
    }
    int countArrangement(int N) {
        n = N;
        memset(dp, -1, sizeof dp);
        return dfs(1, 0);
    }
};