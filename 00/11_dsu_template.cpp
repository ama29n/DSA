#include<bits/stdc++.h>
using namespace std;

class DSU {
public:
    int n;
    vector<int> parent, rank;
    DSU(int size) : n(size) {
        rank = vector<int> (n, 0);
        parent = vector<int> (n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findParent(int n) {
        if(parent[n] == n) {
            return n;
        }
        return parent[n] = findParent(parent[n]);
    }
    void makeParent(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if(rank[a] > rank[b]) {
            parent[b] = a;
            return;
        }
        if(rank[b] > rank[a]) {
            parent[a] = b;
            return;
        }
        parent[b] = a;
        rank[a]++;
    }
};