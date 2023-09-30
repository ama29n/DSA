#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

class Solution {
private:
    int n;
    vector<vector<int>> dp;
    int find(int i, vector<vector<int>> &events) {
        int l = i, r = n - 1, t = events[i][1] + 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(t < events[m][0] || events[m][0] == t) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    int dfs(int i, vector<vector<int>> &events, int k) {
        if(k == 0 || i == n) {
            return 0;
        }
        if(dp[i][k] != -1) return dp[i][k]; 
        int skip = dfs(i + 1, events, k);
        int j = find(i, events);
        int pick = events[i][2] + dfs(j, events, k - 1);
        return dp[i][k] = max(pick, skip);
    }
public:
    int maxValue(vector<vector<int>> &events, int k) {
        n = events.size();
        dp.resize(n, vector<int> (k + 1, -1));
        sort(events.begin(), events.end());
        return dfs(0, events, k);
    }
};