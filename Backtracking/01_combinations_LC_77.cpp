#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combinations/description/ 

// Approach 1
class Solution {
private:
    vector<vector<int>> ans;
    void combinations(int i, int n, int k, vector<int> &v) {
        if(k == 0) {
            ans.push_back(v);
            return;
        }
        if(i <= n) {
            v.push_back(i);
            combinations(i + 1, n, k - 1, v);
            v.pop_back();
            combinations(i + 1, n, k, v);
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        combinations(1, n, k, v);
        return ans;
    }
};
