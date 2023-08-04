#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1 

class Solution {
private:
    vector<int> merge(vector<int> &v1, vector<int> &v2) {
        int m = v1.size(), n = v2.size(), i = 0, j = 0;
        vector<int> v;
        while(i < m && j < n) {
            if(v1[i] < v2[j]) {
                v.push_back(v1[i++]);
            } else {
                v.push_back(v2[j++]);
            }
        }
        while(i < m) {
            v.push_back(v1[i++]);
        }
        while(j < n) {
            v.push_back(v2[j++]);
        }
        return v;
    }
    vector<int> dfs(vector<vector<int>> &arr, int l, int r) {
        if(l == r) {
            return arr[l];
        }
        int m = l + (r - l) / 2;
        vector<int> v1 = dfs(arr, l, m);
        vector<int> v2 = dfs(arr, m + 1, r);
        vector<int> ans = merge(v1, v2);
        return ans;
    }
public:
    vector<int> mergeKArrays(vector<vector<int>> &arr, int K) {
        return dfs(arr, 0, K - 1);
    }
};
// Time Complexity: O(N * K * log K)
// Auxiliary Space: O(N * K * log K). In each level O(N * K) space is required

// Min heap Solution

// Time Complexity: O(N * K * log K), Insertion and deletion in a Min Heap requires log K time
// Auxiliary Space: O(K), If Output is not stored then the only space required is the Min-Heap of K elements