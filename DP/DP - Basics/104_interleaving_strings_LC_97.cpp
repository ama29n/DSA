#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/interleaving-string/ 

class Solution {
public:
    int n1, n2, n3;
    vector<vector<int>> dp;
    bool dfs(int i, int j, int k, string &r, string &s, string &t) {
        if(i == n1) {
            return s.substr(j) == t.substr(k);
        }
        if(j == n2) {
            return r.substr(i) == t.substr(k);
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        bool x = false, y = false;
		// not_take is not an option because n1 + n2 = n3
        if(r[i] == t[k]) {
            x = dfs(i + 1, j, k + 1, r, s, t);
        }
        if(s[j] == t[k]) {
            y = dfs(i, j + 1, k + 1, r, s, t);
        }
        return dp[i][j] = x || y;
    }
    bool isInterleave(string r, string s, string t) {
        n1 = r.size(); n2 = s.size(); n3 = t.size();
        if(n1 + n2 != n3) {
            return false;
        }
        dp.resize(n1, vector<int> (n2, -1));
        return dfs(0, 0, 0, r, s, t);
    }
};