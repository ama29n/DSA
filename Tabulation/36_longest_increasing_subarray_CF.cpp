#include <bits/stdc++.h>
using namespace std;

const int mod = 1E9 + 7; const string yes = "YES", no = "NO"; typedef long long ll;

#define forn(i, s, n)    for(int i = s; i < n; i++)
#define pb               push_back
#define all(v)           v.begin(), v.end()
#define rall(v)          v.rbegin(), v.rend()
#define ff               first
#define ss               second
#define AND(a, b)        ((a) & (b))
#define OR(a, b)         ((a) | (b))
#define XOR(a, b)        ((a) ^ (b))
#define YES              cout << yes << endl
#define NO               cout << no << endl

// https://codeforces.com/problemset/problem/702/A

/*.....................................................................*/

void solve() {
    int n; 
    cin >> n;
    vector<ll> v(n);
    forn(i, 0, n) {
        cin >> v[i];
    }
    vector<ll> dp(n, 1);
    for(int i = 0; i < n; i++)
        if(v[i] > v[i - 1])
            dp[i] = dp[i - 1] + 1;
    ll ans = 0;
    for(auto it : dp)
        ans = max(ans, it);
    cout << ans << endl;
}

/*.....................................................................*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }
}
