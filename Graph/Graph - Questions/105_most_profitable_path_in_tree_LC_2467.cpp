#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/most-profitable-path-in-a-tree/

// For Explantaion
// https://leetcode.com/problems/most-profitable-path-in-a-tree/discuss/2807150/2-DFS-oror-1-DFS-oror-Simple-Approach-oror-C%2B%2B

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent, depth;
    void dfs(int node, int h, int p) {
        parent[node] = p;
        depth[node] = h;
        for(auto child : adj[node]) {
            if(child != p) {
                dfs(child, h + 1, node);
            }
        }
    }
    int maxPath(int node, int p, vector<int>& amount) {
        int res = INT_MIN;
        for(auto child : adj[node]) {
            if(child != p) {
                res = max(res, maxPath(child, node, amount));
            }
        }
        return res == INT_MIN ? amount[node] : amount[node] + res;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj = vector<vector<int>> (n, vector<int>());
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        parent = vector<int> (n);
        depth = vector<int> (n);
        dfs(0, 0, 0);
        int bob_node = bob;
        int bob_dis = 0;
        while(bob_node != 0) {
            if(depth[bob_node] > bob_dis) {
                amount[bob_node] = 0;
            } else if(depth[bob_node] == bob_dis) {
                amount[bob_node] /= 2;
            }
            bob_node = parent[bob_node];
            bob_dis++;
        }
        return maxPath(0, 0, amount);
    }
};