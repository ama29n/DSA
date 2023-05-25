#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/description/

class Solution {
public:
    bool check(int a, int b, int c, int d, vector<int> adj[]) {
        for(auto it : adj[a]) if(it == b) return false;
        for(auto it : adj[c]) if(it == d) return false;
        return true;
    }
    bool isPossible(int n, vector<vector<int>> &edges) {
        vector<int> inDegree(n + 1, 0);
        for(auto it : edges) { inDegree[it[0]]++; inDegree[it[1]]++; }
        vector<int> v;
        for(int i = 1; i <= n; i++) if(inDegree[i] % 2 != 0) v.push_back(i);
        int oddCount = v.size();
        // Base Cases
        if(oddCount % 2 != 0 || oddCount > 4) return false;
        if(oddCount == 0) return true;
        vector<int> adj[n + 1];
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]); adj[it[1]].push_back(it[0]);
        }
        // 2 odd degree nodes -> Can be connected togather or with a node which is not connected with either of them
        if(oddCount == 2) {
            int a = v[0], b = v[1];
            for(int i = 1; i <= n; i++) {
                if(check(i, a, i, b, adj)) return true;
            }
            return false;
        }
        // 4 odd degree nodes -> Have to be connected togather as it will take 2 edges
        int a = v[0], b = v[1], c = v[2], d = v[3];
        return check(a, b, c, d, adj) || check(a, c, b, d, adj) || check(a, d, b, c, adj);
    }
};