#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
    public:

    int MOD = 1e9 + 7;
    
    ll cal(int i, int j, int m, int n, int moves, vector<vector<vector<ll>>>& dp) {
        if(i >= m || j >= n || i < 0 || j < 0)
            return 1;
        if(moves == 0)
            return 0;
        if(dp[i][j][moves] != -1)
            return dp[i][j][moves];
        ll u = cal(i - 1, j, m, n, moves - 1, dp);
        ll d = cal(i + 1, j, m, n, moves - 1, dp);
        ll l = cal(i, j - 1, m, n, moves - 1, dp);
        ll r = cal(i, j + 1, m, n, moves - 1, dp);
        return dp[i][j][moves] = ((u % MOD) + (d % MOD) + (l % MOD) + (r % MOD)) % MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>> (n, vector<ll> (maxMove + 1, -1)));
        return cal(startRow, startColumn, m, n, maxMove, dp);
    }
};