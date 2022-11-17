#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/couples-holding-hands/

class Solution {
public:
    class DSU {
    public:
        int n;
        vector<int> parent;
        DSU(int size) : n(size) {
            parent = vector<int> (n);
            for(int i = 0; i < n; i++)
                parent[i] = i;
        }
        int findParent(int n) {
            if(parent[n] == n)
                return n;
            return parent[n] = findParent(parent[n]);
        }
        void makeUnion(int a, int b) {
            parent[a] = b;
        }
    };
    int minSwapsCouples(vector<int>& nums) {
        int n = nums.size();
        DSU d(n);
        for(int i = 0; i < n; i += 2) {
            d.makeUnion(nums[i], nums[i + 1]);
        }
        int swaps = 0;
        for(int i = 0; i < n; i += 2) {
            int parent_x = d.findParent(i);
            int parent_y = d.findParent(i + 1);
            if(parent_x != parent_y) {
                swaps++;
                d.makeUnion(parent_x, parent_y);
            }
        }
        return swaps;
    }
};