#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1 

class Solution {
public:
    int m, n;
    bool check(int node, int candidate_color, vector<int> &color, bool graph[101][101]) {
        for(int i = 0; i < n; i++) {
            if(graph[node][i] && candidate_color == color[i]) return false;
        }
        return true;
    }
    bool dfs(int node, vector<int> &color, bool graph[101][101]) {
        if(node == n) {
            return true;
        }
        for(int i = 1; i <= m; i++) {
            if(check(node, i, color, graph)) {
                color[node] = i;
                if(dfs(node + 1, color, graph)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int M, int V) {
        m = M; n = V;
        vector<int> color(V, 0);
        return dfs(0, color, graph);
    }
};