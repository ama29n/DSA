#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum-iii/

class Solution {
private:
    vector<vector<int>> ans;
    void dfs(int i, int k, int n, vector<int> &v) {
        if(k == 0) {
            if(n == 0) ans.push_back(v);
            return;
        }
        for(int j = i; j <= 9; j++) {
            if(j <= n) {
                v.push_back(j);
                dfs(j + 1, k - 1, n - j, v);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        dfs(1, k, n, v);
        return ans;
    }
};