#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1742/G

#define pb            push_back
#define mem(a, i)     memset(a, i, sizeof(a))
#define ff            first
#define ss            second
#define all(v)        v.begin(), v.end()
#define rall(v)       v.rbegin(), v.rend()
#define forn(i, n)    for(int i = 0; i < n; i++)

// This approach fails because maximum element doesn't means maximum OR.
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    forn(i, n) cin >> v[i];
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
    forn(i, n) if(!vis[i]) ans.pb(v[i]);
    for(auto it : ans) cout << it << " ";
    cout << endl;
}

// This will work
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    forn(i, n)
        cin >> v[i];
    vector<int> ans;
    vector<int> vis(n, 0);
    int num = 31 - __builtin_clz(*max_element(all(v)));
    int prev_or = 0;
    for(int i = 0; i <= num && ans.size() < n; i++) {
        int mx = 0, idx = -1;
        for(int j = 0; j < n; j++) {
            if(vis[j])
                continue;
            if((prev_or | v[j]) > mx) {
                idx = j;
                mx = (prev_or | v[j]);
            }
        }
        vis[idx] = 1;
        ans.push_back(v[idx]);
        prev_or |= v[idx];
    }

    forn(i, n) if(!vis[i]) ans.pb(v[i]);
    for(auto it : ans) cout << it << " ";
    cout << endl;
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

