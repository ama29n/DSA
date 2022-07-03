// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

// You may return the answer in any order.

// Input: n = 4, k = 2
// Output: [[2,4], [3,4], [2,3], [1,2], [1,3], [1,4]]

#include<bits/stdc++.h>
using namespace std;

// Approach 1

class Solution {
public:
    vector<vector<int>> ans;
    
    void combinations(int num, int n, int k, vector<int> v) {
        if(k == 0) {
            if(k == 0) ans.push_back(v);
            return;
        }
        if(num <= n) {
            v.push_back(num);
            combinations(num + 1, n, k - 1, v);
            v.pop_back();
            combinations(num + 1, n, k, v);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        combinations(1, n, k, v);
        return ans;
    }
};

// Approach 2

class Solution {
public:
    vector<vector<int>> ans;
    
    void combinations(int left, int n, int k, vector<int> v) {
        if(k == 0) {
            ans.push_back(v);
            return;
        }
        for(int i = left; i <= n; i++) {
            v.push_back(i);
            combinations(i + 1, n, k - 1, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        combinations(1, n, k, v);
        return ans;
    }
};