#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> m;
        for(int i = 0; i < n; i++) {
            string s = "";
            for(int j = 0; j < n; j++) {
                s += to_string(grid[i][j]);
                s += "$";
            }
            m[s]++;
        }
        int ans = 0;
        for(int j = 0; j < n; j++) {
            string s = "";
            for(int i = 0; i < n; i++) {
                s += to_string(grid[i][j]);
                s += "$";
            }
            ans += m[s];
        }
        return ans;
    }
};