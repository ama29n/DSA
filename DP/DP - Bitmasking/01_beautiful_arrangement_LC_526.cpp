#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/beautiful-arrangement/

// A mask is used to store the selected elements and backtracking is used to find the all valid permutations 

class Solution {
private:
    int dp[16][(1 << 16)];
    bool check(int a, int b) { 
        return (a % b) == 0 || (b % a) == 0;
    }
    int dfs(int i, int mask, int n) {
        if(mask == ((1 << n) - 1)) {
            return 1;
        }
        if(dp[i][mask] != -1) {
            return dp[i][mask];
        }
        dp[i][mask] = 0;
        for(int j = 1; j <= n; j++) {
            int bit = j - 1;
            if(!(mask & (1 << bit)) && check(i, j)) {
                dp[i][mask] += dfs(i + 1, mask | (1 << bit), n);
            }
        }
        return dp[i][mask];
    }
public:
    int countArrangement(int n) {
        memset(dp, -1, sizeof dp);
        return dfs(1, 0, n);
    }
};