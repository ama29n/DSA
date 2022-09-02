#include <bits/stdc++.h>
using namespace std;

// You are given a positive integer k. You are also given:

// a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
// a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
// The two arrays contain integers from 1 to k.

// You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. 
// The remaining cells should have the value 0.

// The matrix should also satisfy the following conditions:

// The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
// The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
// Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

// Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
// Output: [[3,0,0],[0,0,1],[0,2,0]]

class Solution {
public:
    // Function that returns the topo sort
    vector<int> topoSort(int k, vector<vector<int>>& c) {
        set<int> adj[k + 1];
        for(auto it : c) {
            adj[it[0]].insert(it[1]);
        }
        vector<int> inDegree(k + 1, 0);
        for(int i = 1; i <= k; i++)
            for(auto it : adj[i])
                inDegree[it]++;
        queue<int> q;
        for(int i = 1; i <= k; i++)
            if(inDegree[i] == 0)
                q.push(i);
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node]) {
                if(inDegree[it] > 0) {
                    inDegree[it]--;
                    if(inDegree[it] == 0)
                    q.push(it);
                }
            }
        }
        return ans;
    }
    // 1 3 2 or 3 1 2 
    // 3 2 1 
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rc = topoSort(k, rowConditions), cc = topoSort(k, colConditions);
        
        // If there exists cycle in the graph
        if(rc.size() != k || cc.size() != k)
            return {};

        vector<vector<int>> grid(k, vector<int> (k, 0));
        
        vector<int> idx(k + 1, 0);
        for(int j = 0; j < cc.size(); j++)
            idx[cc[j]] = j;
        
        for(int i = 0; i < k; i++)
            grid[i][idx[rc[i]]] = rc[i];
        
        return grid;
    }
};