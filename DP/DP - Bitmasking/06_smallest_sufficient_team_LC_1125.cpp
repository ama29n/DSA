#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/smallest-sufficient-team/

class Memoization {
private:
    int n, m;
    unordered_map<string, int> map;
    unordered_map<int, vector<int>> dp;
    // Member Function
    void dfs(int i, int mask, vector<vector<string>> &people) {
        if(i == m) {
            return;
        }
        dfs(i + 1, mask, people);
        int new_mask = mask;
        for(auto &str : people[i]) {
            if(map.find(str) != map.end()) {
                new_mask = new_mask | (1 << (map[str]));
            }
        }
        if(dp.find(new_mask) == dp.end() || dp[new_mask].size() > 1 + dp[mask].size()) {
            dp[new_mask] = dp[mask];
            dp[new_mask].push_back(i);
            dfs(i + 1, new_mask, people);
        }
    }
public:
    vector<int> smallestSufficientTeam(vector<string> &skills, vector<vector<string>> &people) {
        n = skills.size(); m = people.size();
        for(int i = 0; i < n; i++) map[skills[i]] = i;
        dp[0] = {};
        dfs(0, 0, people);
        return dp[(1 << n) - 1];
    }
};

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string> &skills, vector<vector<string>> &people) {
        int n = skills.size(), m = people.size();
        unordered_map<string, int> map;
        for(int i = 0; i < n; i++) { map[skills[i]] = i; }
        unordered_map<int, vector<int>> dp;
        dp.reserve(1 << n);
        dp[0] = {};
        for(int i = 0; i < m; i++) {
            int mask = 0;
            for(auto &str : people[i]) {
                mask = mask | (1 << (map[str]));
            }
            for(auto it : dp) {
                int new_mask = it.first | mask;
                if(dp.find(new_mask) == dp.end() || dp[new_mask].size() > 1 + it.second.size()) {
                    dp[new_mask] = it.second;
                    dp[new_mask].push_back(i);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};