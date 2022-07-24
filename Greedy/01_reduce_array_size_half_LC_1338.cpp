#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reduce-array-size-to-the-half/

int minSetSize(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> v;
    int c = 1;

    // v is frequency array
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i - 1])
            c++;
        else {
            v.push_back(c);
            c = 1;
        }
    }
    v.push_back(c);

    // sorting frequency array
    sort(v.begin(), v.end());

    int ans = 0, removedEls = 0, i = v.size() - 1;
    while(i > -1 && removedEls < n / 2) {
        ans++;
        removedEls += v[i];
        i--;
    }
    return ans;
}