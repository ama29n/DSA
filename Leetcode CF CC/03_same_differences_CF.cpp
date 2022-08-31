#include <bits/stdc++.h>
using namespace std;

#define MOD 1E9 + 7
#define ll long long int

// You are given an array a of n integers. Count the number of pairs of indices (i,j) such that 
// i < j and aj − ai = j − i.

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    ll ans = 0;
    unordered_map<int, int> map;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        int dif = v[i] - i;
        ans += map[dif];
        map[dif]++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}
