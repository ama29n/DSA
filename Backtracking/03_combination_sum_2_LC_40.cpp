#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum-ii/ 

class Solution {
private:
    vector<vector<int>> ans;
    void dfs(int i, vector<int> &can, int T, vector<int> &v) {
        if(T == 0) {
            ans.push_back(v);
            return;
        }
        for(int j = i; j < can.size(); j++) {
            if(i == j || can[j] != can[j - 1]) {
                v.push_back(can[j]);
                dfs(j + 1, can, T - can[j], v);
                v.pop_back();
            } 
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int> &can, int T) {
        vector<int> v;
        sort(can.begin(), can.end());
        dfs(0, can, T, v);
        return ans;
    }
};
