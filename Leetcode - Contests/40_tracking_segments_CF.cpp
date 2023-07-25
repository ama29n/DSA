#include <bits/stdc++.h>
using namespace std;

const int mod = 1E9 + 7; const string yes = "YES", no = "NO"; typedef long long ll;

#define forn(i, s, n)    for(int i = s; i < n; i++)
#define ff               first
#define ss               second
#define nl               << '\n'

// https://codeforces.com/contest/1843/problem/E

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        v[i] = {x - 1, y};
    }
    int q; cin >> q;
    vector<int> queries(q);
    forn(i, 0, q) {
        cin >> queries[i];
    }
    int ans = -1;
    int beg = 1, end = q;
    while(beg <= end) {
        vector<int> pre(n + 1, 0);
        int mid = beg + (end - beg) / 2;
        for(int i = 0; i < mid; i++) {
            pre[queries[i]] = 1;
        }
        for(int i = 1; i <= n; i++) {
            pre[i] += pre[i - 1];
        }
        bool flag = false;
        for(auto it : v) {
            if(pre[it.ss] - pre[it.ff] > (it.ss - it.ff) / 2) {
                flag = true;
                break;
            }
        }
        if(flag) {
            ans = mid;
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    cout << ans nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
}