#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector <int> calculateSpan(int price[], int n) {
       vector<int> span(n);
       span[0] = 1;
       
       stack<int> s;
       s.push(0);
       
       // 100 90 80 70 60 50 60, reason for <= condition
       for(int i = 1; i < n; i++) {
           while(!s.empty() && price[s.top()] <= price[i])
                s.pop();
            span[i] = !s.empty() ? i - s.top() : i + 1;
            s.push(i);
       }
       
       return span;
    }
};