#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-stepping-numbers-in-range/

class Solution {
public:
    const int MOD = 1E9 + 7;
    int dp[101][12][2];
    int dfs(int idx, int prev, bool tight, string &digits) {
        if(idx == digits.length()) {
            return prev != -1 ? 1 : 0;
        }

        if(dp[idx][prev + 1][tight] != -1) return dp[idx][prev + 1][tight];

        int limit = 9, res = 0;
        if(tight) limit = (digits[idx] - '0');

        for(int dig = 0; dig <= limit; dig++) {
            if(prev == -1 || abs(dig - prev) == 1) {
                res = ( res + dfs(idx + 1, (prev == -1 && dig == 0) ? -1 : dig, 
                        (tight & (dig == limit)), digits) ) % MOD;
            }
        }

        return dp[idx][prev + 1][tight] = res;
    }
    int go(string &x) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, -1, true, x);
    }
    int countSteppingNumbers(string &L, string &R) {
        int n = L.size();
        if(L[n - 1] == '0') {
            int j = n - 1;
            while(j >= 0 && L[j] == '0') {
                L[j] = '9'; j--;
            }
            L[j] = L[j] - 1;
        } else {
            L[n - 1] = L[n - 1] - 1;
        }
        int ans = go(R) - go(L);
        return ans < 0 ? ans + MOD : ans;
    }
};