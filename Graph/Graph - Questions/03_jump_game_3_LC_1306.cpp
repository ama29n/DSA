#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/jump-game-iii/ 

class Solution {
public:
    bool canReach(vector<int> &arr, int start) {
        int n = arr.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++) {
            if(i - arr[i] >= 0) 
                adj[i].push_back(i - arr[i]);
            if(i + arr[i] < n) 
                adj[i].push_back(i + arr[i]);
        }
        vector<int> vis(n, 0);
        vis[start] = 1;
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int node = q.front(); q.pop();
            if(arr[node] == 0) return true;
            for(auto it : adj[node]) if(!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
        return false;
    }
};