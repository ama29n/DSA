#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1742/G

#define forn(i, s, n)    for(int i = s; i < n; i++)
#define pb               push_back
#define all(v)           v.begin(), v.end()
#define sp               << ' '
#define nl               << '\n'
#define endl             '\n'

// This approach fails because maximum element doesn't means maximum OR.
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    forn(i, 0, n) cin >> v[i];
    vector<int> ans;
    vector<int> vis(n, 0);
    int num = 31 - __builtin_clz(*max_element(all(v)));

    for(int i = num; i >= 0; i--) {
        int mask = 1 << i, ele = INT_MIN, idx;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 1) continue;
            if((mask & v[i]) && v[i] > ele) {
                ele = v[i], idx = i;
            }
        }
        if(ele == INT_MIN) continue;
        vis[idx] = 1;
        ans.pb(v[idx]);
    }
    forn(i, 0, n) if(!vis[i]) ans.pb(v[i]);
    for(auto it : ans) cout << it << " ";
    cout << endl;
}

// This will work
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    forn(i, 0, n) {
        cin >> v[i];
    }
    vector<int> vis(n, 0);
    int prev_or = 0;
    for(int i = 0; i < 32 && i < n; i++) {
        int cur_or = prev_or, idx = INT_MAX;
        forn(j, 0, n) {
            if(vis[j] == 0 && (prev_or | v[j]) > cur_or) {
                cur_or = prev_or | v[j];
                idx = j;
            }
        }
        if(idx == INT_MAX) {
            continue;
        }
        vis[idx] = 1;
        prev_or = cur_or;
        cout << v[idx] sp;
    }
    forn(i, 0, n) {
        if(!vis[i]) {
            cout << v[i] sp;
        }
    }
    cout nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}

