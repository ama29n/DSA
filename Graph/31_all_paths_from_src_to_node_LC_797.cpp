#include <bits/stdc++.h>
using namespace std;

// given graph is a dag

class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(int i, vector<int> &v, vector<vector<int>> &graph) {
        v.push_back(i);
        if(i == graph.size() - 1)
            ans.push_back(v);
        for(auto it : graph[i]) {
            dfs(it, v, graph);
        }
        v.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> v;
        dfs(0, v, graph);
        return ans;
    }
};