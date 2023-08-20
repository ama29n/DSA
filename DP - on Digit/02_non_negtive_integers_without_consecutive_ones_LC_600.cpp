#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/ 

#include <bitset>
class Solution {
public:
    int dp[32][2][2][4];
    int dfs(int idx, bool isZero, bool tight, int prev, string &digits) {
        if(idx == digits.size()) {
            return 1;
        }

        if(dp[idx][isZero][tight][prev + 1] != -1) return dp[idx][isZero][tight][prev + 1];

        int limit = 1, res = 0;
        if(tight) limit = (digits[idx] - '0');

        for(int dig = 0; dig <= limit; dig++) {
            if(prev == -1 || !(prev == 1 && dig == 1)) {
                res += dfs(idx + 1, (isZero & (dig == 0)), (tight & (limit == dig)), 
                        (isZero & (dig == 0)) ? -1 : dig, digits);
            }
        }

        return dp[idx][isZero][tight][prev + 1] = res;
    }
    int findIntegers(int n) {
        std::bitset<32> input = n;
        string x = input.to_string();
        int i = 0;
        while(i < 32 && x[i++] != '1');
        x = x.substr(i - 1);
        memset(dp, -1, sizeof dp);
        return dfs(0, true, true, -1, x);
    }
};