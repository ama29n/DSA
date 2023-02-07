#include <bits/stdc++.h>
using namespace std;

void activitySelector(int s[], int f[], int n) {
    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++) {
        v[i] = {f[i], s[i], i}; // {finish, start, activity number}
    }
    sort(v.begin(), v.end());
    vector<int> selected;
    int prevF = 0;
    for(auto it : v) {
        int f = it[0], s = it[1], activity = it[2];
        if(s >= prevF) {
            selected.push_back(activity);
            prevF = f;
        } 
    }
    cout << "selected Activities: { ";
    for(auto it : selected) {
        cout << it << " ";
    }
    cout << "}";
}

int main() {
    int n = 3;
    int s[n] = {10, 12, 20};
    int f[n] = {20, 25, 30};
    activitySelector(s, f, n);
}