#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/out-of-boundary-paths/ 

class Solution {
public:
    typedef long long ll;
    const int mod = 1E9 + 7;
    int m, n;
    vector<vector<vector<ll>>> dp;
    ll dfs(int i, int j, int moves) {
        if(i == m || j == n || i < 0 || j < 0) {
            return 1;
        }
        if(moves == 0) {
            return 0;
        }
        if(dp[i][j][moves] != -1) {
            return dp[i][j][moves];
        }
        ll l = dfs(i, j - 1, moves - 1) % mod;
        ll r = dfs(i, j + 1, moves - 1) % mod;
        ll u = dfs(i + 1, j, moves - 1) % mod;
        ll d = dfs(i - 1, j, moves - 1) % mod;
        return dp[i][j][moves] = (l + r + u + d) % mod;
    }
    int findPaths(int M, int N, int moves, int s, int e) {
        m = M; n = N;
        dp.resize(m, vector<vector<ll>> (n, vector<ll> (moves + 1, -1)));
        return dfs(s, e, moves);
    }
};
