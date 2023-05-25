#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/ 

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj[n + 1];
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(!vis[it[0]]) {
                    vis[it[0]] = 1;
                    q.push(it[0]);
                }
            }
        }
        int min_path = INT_MAX;
        for(auto it : roads) {
            if(vis[it[1]] && vis[it[0]] && it[2] < min_path) 
                min_path = it[2];
        }
        return min_path;
    }
};