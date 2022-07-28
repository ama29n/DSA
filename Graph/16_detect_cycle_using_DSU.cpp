#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int parent[10000];
    
    void makeSet(int n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int findParent(int node) {
        if(parent[node] == node)
            return node;
        return findParent(parent[node]);
    }
    
    void makeUnion(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        parent[b] = a;
    }
    
	int detectCycle(int n, vector<int>adj[]) {
	    makeSet(n);
	    for(int i = 0; i < n; i++) {
	        for(auto it : adj[i]) {
	            int u = i, v = it;
	            u = findParent(u);
	            v = findParent(v);
	            if(u == v && i < it)
	                return 1;
	           makeUnion(u, v);
	        }
	    }
	    return 0;
	}
};