#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1 

class DSU {
private:
    int n;
    vector<int> parent, rank;
    public:
    DSU(int size) : n(size) {
        rank = vector<int> (n, 0);
        parent = vector<int> (n);
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
    void makePair(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if(rank[a] > rank[b]) {
            parent[b] = a; return;
        }
        if(rank[b] > rank[a]) {
            parent[a] = b; return;
        }
        parent[b] = a;
        rank[a]++;
    }
    int getComponents() {
        int x = 0;
        for(int i = 0; i < n; i++) if(parent[i] == i && rank[i] > 0) x++;
        return x;
    }
};
class Solution {
    public:
    int maxRemove(vector<vector<int>> &stones, int N) {
        int n = 0, m = 0;
        for(auto it : stones) {
            n = max(n, it[0]); m = max(m, it[1]);
        }
        DSU dsu(n + m + 2);
        for(auto it : stones) {
            dsu.makePair(it[0], it[1] + n + 1);
        }
        return N - dsu.getComponents();
    }
};