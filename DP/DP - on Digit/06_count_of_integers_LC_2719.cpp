#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-of-integers/ 

class Solution {
private:
    const int MOD = 1E9 + 7;
    int min_sum, max_sum;
    int dp[23][401][2];
    int dfs(int i, bool tight, int sum, string &digits) {
        if(i == digits.size()) {
            return (sum <= max_sum && sum >= min_sum) ? 1 : 0;
        }

        if(dp[i][sum][tight] != -1) 
            return dp[i][sum][tight];

        int limit = 9, res = 0;
        if(tight) limit = (digits[i] - '0');

        for(int dig = 0; dig <= limit; dig++) {
            bool isTight = (tight & (dig == limit));
            if(sum + dig <= max_sum) {
                res = (res + dfs(i + 1, isTight, sum + dig, digits)) % MOD;
            }
        }

        return dp[i][sum][tight] = res;
    }
    int go(string &x) {
        memset(dp, -1, sizeof dp);
        return dfs(0, true, 0, x);
    }
public:
    int count(string L, string R, int min_sum, int max_sum) {
        this->min_sum = min_sum; this->max_sum = max_sum;
        int n = L.size();
        if(L[n - 1] == '0') {
            int j = n - 1;
            while(L[j] == '0') {
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