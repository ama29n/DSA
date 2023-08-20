#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/ 

class Solution {
public:
    unordered_set<string> set;
    int dp[11][2][2];
    int dfs(int i, bool isZero, bool tight, string &digits) {
        if(i == digits.size()) {
            return isZero ? 0 : 1;
        }

        if(dp[i][isZero][tight] != -1) return dp[i][isZero][tight];

        int limit = 9, res = 0;
        if(tight) limit = (digits[i] - '0');

        for(int dig = 0; dig <= limit; dig++) {
            string x = to_string(dig);
            // isZero && dig == 0) -> So as to take recursion forward
            if((isZero && dig == 0) || (set.find(x) != set.end())) {
                res += dfs(i + 1, (isZero & (dig == 0)), (tight & (limit == dig)), digits);
            }
        }

        return dp[i][isZero][tight] = res;
    }
    int atMostNGivenDigitSet(vector<string> &digits, int n) {
        set = unordered_set<string> (digits.begin(), digits.end());
        string x = to_string(n);
        memset(dp, -1, sizeof dp);
        return dfs(0, true, true, x);
    }
};