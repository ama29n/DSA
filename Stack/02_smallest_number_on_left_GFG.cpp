#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        vector<int> prev(n);
        prev[0] = -1;
        stack<int> s;
        s.push(arr[0]);
        for(int i = 1; i < n; i++) {
            while(s.size() && s.top() >= arr[i])
                s.pop();
            prev[i] = !s.empty() ? s.top() : -1;
            s.push(arr[i]);
        }
        return prev;
    }
};