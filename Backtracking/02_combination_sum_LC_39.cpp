#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum/ 

// Approach 1
class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void dfs(int idx, vector<int> &can, vector<int> &v, int t) {
        if(t == 0) {
            ans.push_back(v);
            return;
        }
        if(idx == n) {
            return;
        }
        for(int i = idx; i < n; i++) {
            if(can[i] <= t) {
                v.push_back(can[i]);
                dfs(i, can, v, t - can[i]);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &can, int target) {
        n = can.size();
        vector<int> v;
        dfs(0, can, v, target);
        return ans;
    }
};

// Approach 2
class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void dfs(int idx, vector<int> &can, vector<int> &v, int t) {
        if(idx == n) {
            if(t == 0) {
                ans.push_back(v);
            }
            return;
        }
        if(can[idx] <= t) {
            v.push_back(can[idx]);
            dfs(idx, can, v, t - can[idx]);
            v.pop_back();
        }
        dfs(idx + 1, can, v, t);
    }
    vector<vector<int>> combinationSum(vector<int> &can, int target) {
        n = can.size();
        vector<int> v;
        dfs(0, can, v, target);
        return ans;
    }
};