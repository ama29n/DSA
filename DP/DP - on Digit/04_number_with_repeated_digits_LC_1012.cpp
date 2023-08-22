#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/numbers-with-repeated-digits/ 

// In this question, mask works as isZero
// Mask is used to make sure that a digit is not repeated
// Final Answer -> (Total - Numbers that have unique digits)


class Solution {
public:
    int dp[11][2][1025];         // 1025 -> 2 ^ 10
    int dfs(int i, int mask, bool tight, string &digits) {
        if(i == digits.size()) {
            return mask == 0 ? 0 : 1;
        }

        if(dp[i][tight][mask] != -1) return dp[i][tight][mask];

        int limit = 9, res = 0;
        if(tight) limit = (digits[i] - '0');

        for(int dig = 0; dig <= limit; dig++) {
            if(mask == 0 && dig == 0) {
                res += dfs(i + 1, mask, (tight & (limit == dig)), digits);
                continue;
            }
            int repeated = mask & (1 << dig);
            if(repeated == 0) {
                res += dfs(i + 1, mask | (1 << dig), (tight & (limit == dig)), digits);
            }
        }

        return dp[i][tight][mask] = res;
    }
    int numDupDigitsAtMostN(int n) {
        memset(dp, -1, sizeof dp);
        string x = to_string(n);
        return n - dfs(0, 0, true, x);
    }
};