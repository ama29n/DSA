#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/painting-the-walls/ 

class Solution {
public:
    typedef long long int ll;
    int n;
    ll offset = 250000;
    vector<vector<ll>> dp;
    ll dfs(int i, ll pendingTime, vector<int> &cost, vector<int> &time) {
        if(i == n) {
            if(pendingTime < offset) {
                return INT_MAX;
            }
            return 0;
        }
        if(dp[i][pendingTime] != -1) return dp[i][pendingTime];
        ll paid = cost[i] + dfs(i + 1, pendingTime + time[i], cost, time);
        ll free = dfs(i + 1, pendingTime - 1, cost, time);
        return dp[i][pendingTime] = min(paid, free);
    }
    int paintWalls(vector<int> &cost, vector<int> &time) {
        n = cost.size();
        dp.resize(n, vector<ll> (2 * offset + 10, -1));
        return dfs(0, offset, cost, time);
    }
};

// At any point we won't need more than (n / 2) paid workers

class Solution {
public:
    int n;
    int dp[501][501];
    int dfs(int i, int pendingTime, vector<int> &cost, vector<int> &time) {
        if(pendingTime <= 0) {
            return 0;
        }
        if(i == n) {
            return 1E9;
        }
        if(dp[i][pendingTime] != -1) {
            return dp[i][pendingTime];
        }
        int paid = cost[i] + dfs(i + 1, pendingTime - time[i] - 1, cost, time);
        int free = dfs(i + 1, pendingTime, cost, time);
        return dp[i][pendingTime] = min(paid, free);
    }
    int paintWalls(vector<int> &cost, vector<int> &time) {
        n = cost.size();
        memset(dp, -1, sizeof dp);
        return dfs(0, n, cost, time);
    }
};