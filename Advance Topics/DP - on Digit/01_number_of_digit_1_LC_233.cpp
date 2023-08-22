#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-digit-one/

class Solution {
public:
    int dp[11][2][2][10];
    int dfs(int idx, bool isZero, bool tight, int count, string &digits) {
        if(idx == digits.length()) {
            return count;
        }

        if(dp[idx][isZero][tight][count] != -1) return dp[idx][isZero][tight][count];

        int limit = 9, res = 0;
        if(tight) limit = (digits[idx] - '0');

        for(int dig = 0; dig <= limit; dig++) {
            res += dfs(idx + 1, (isZero && (dig == 0)), (tight && (dig == limit)), 
                    count + (dig == 1 ? 1 : 0), digits);
        }

        return dp[idx][isZero][tight][count] = res;
    }
    int countDigitOne(int n) {
        string digits = to_string(n);
        memset(dp, -1, sizeof dp);
        return dfs(0, true, true, 0, digits);
    }
};