#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-palindromic-subsequences/

// We need to find the palindromic subsequeces of length 5

// DP Solution
class Solution {
public:
    typedef long long ll;
    const int mod = 1E9 + 7;
    string s, t;
    int dp[10000 + 1][5];

    // Generating string of type XY_YX
    string getDigit(int n) {
        string p = to_string(n);
        if(p.size() == 1)
            p = "0" + p;
        string q = p;
        reverse(q.begin(), q.end());
        return p + "." + q;
    }
    
    // Counting number of times above generated string can be made from main string 
    ll countSub(int i, int j) {
        if(j == 5)
            return 1;
        if(i == s.size())
            return 0;
        if(dp[i][j] + 1)
            return dp[i][j];
        ll ret = countSub(i + 1, j) % mod;
        if(j == 2 || s[i] == t[j]) {
            ret = (ret + countSub(i + 1, j + 1)) % mod;
        }
        return dp[i][j] = ret;
    }
    int countPalindromes(string str) {
        s = str;
        ll ans = 0;
        for(int i = 0; i < 100; i++) {
            t = getDigit(i);
            memset(dp, -1, sizeof dp);
            ans += countSub(0, 0);
            ans %= mod;
        }
        return ans;
    }
};