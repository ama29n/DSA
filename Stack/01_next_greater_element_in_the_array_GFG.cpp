#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1 

class Solution {
    public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<long long> next(n);
        next[n - 1] = -1;
        stack<long long> s;
        s.push(arr[n - 1]);
        for(int i = n - 2; i >= 0; i--) {
            while(!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            next[i] = s.size() != 0 ? s.top() : -1;
            s.push(arr[i]);
        }
        return next;
    }
};