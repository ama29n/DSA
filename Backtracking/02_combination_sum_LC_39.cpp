#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum/ 

// Approach 1
class Solution {
private:
    vector<vector<int>> ans;
    void dfs(int i, vector<int> &can, int T, vector<int> &v) {
        if(T == 0) {
            ans.push_back(v);
            return;
        }
        for(int j = i; j < can.size(); j++) {
            if(can[j] <= T) {
                v.push_back(can[j]);
                dfs(j, can, T - can[j], v);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int> &can, int T) {
        vector<int> v;
        dfs(0, can, T, v);
        return ans;
    }
};
