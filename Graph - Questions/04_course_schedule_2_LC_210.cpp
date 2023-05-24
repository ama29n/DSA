#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/course-schedule-ii/ 

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>> &pre) {
        vector<int> adj[n];
        for(auto it : pre) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> ans;
        // Kahn's Algorithm
        vector<int> inDegree(n, 0);
        for(int i = 0; i < n; i++) for(auto it : adj[i]) inDegree[it]++;
        queue<int> q;
        int node_count = 0;
        for(int i = 0; i < n; i++) if(inDegree[i] == 0) q.push(i);
        while(!q.empty()) {
            int node = q.front(); q.pop(); node_count++;
            if(inDegree[node] == 0) ans.push_back(node);
            for(auto it : adj[node]) {
                if(inDegree[it]) {
                    inDegree[it]--;
                    if(inDegree[it] == 0) q.push(it);
                }
            }
        }
        if(node_count != n) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};