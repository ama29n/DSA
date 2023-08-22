#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/all-paths-from-source-to-target/ 

// Graph is DAG 

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int node, int n, vector<int> &v, vector<vector<int>> &graph) {
        v.push_back(node);
        for(auto it : graph[node]) {
            dfs(it, n, v, graph);
        }
        if(node == n - 1) {
            ans.push_back(v);
        }
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<int> path;
        dfs(0, graph.size(), path, graph);
        return ans;
    }
};