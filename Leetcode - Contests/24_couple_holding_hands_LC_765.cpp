#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/couples-holding-hands/

class Solution {
public:
    class DSU {
    private:
        int n;
        vector<int> parent, rank;
    public:
        DSU(int _n) : n(_n) {
            parent.resize(n); rank.resize(n, 0);
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        int findParent(int x) {
            if(parent[x] == x) {
                return x;
            }
            return parent[x] = findParent(parent[x]);
        }
        void makePair(int x, int y) {
            x = findParent(x); y = findParent(y);
            if(rank[x] > rank[y]) {
                parent[y] = x;
            } else if(rank[y] < rank[x]) {
                parent[y] = x;
            } else {
                parent[y] = x;
                rank[x]++;
            } 
        }
    };
    int minSwapsCouples(vector<int> &row) {
        int n = row.size();
        DSU dsu(n);
        for(int i = 0; i < n; i += 2) {
            dsu.makePair(i, i + 1);
        }
        int swaps = 0;
        for(int i = 0; i < n; i += 2) {
            int x = row[i], y = row[i + 1];
            if(dsu.findParent(x) != dsu.findParent(y)) {
                swaps++;
                dsu.makePair(x, y);
            }
        }
        return swaps;
    }
};