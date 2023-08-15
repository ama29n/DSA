#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1 

class Solution {
    public:
    vector <int> calculateSpan(int price[], int n) {
       stack<int> s;
       vector<int> span(n, 1);
       s.push(0);
       for(int i = 1; i < n; i++) {
           while(!s.empty() && price[s.top()] <= price[i]) {
               s.pop();
           }
           span[i] = s.empty() ? i + 1 : i - s.top();
           s.push(i);
       }
       return span;
    }
};