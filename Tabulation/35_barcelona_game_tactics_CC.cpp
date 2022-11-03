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

// https://www.codechef.com/submit/FCBARCA

/*.....................................................................*/

void solve() {
    ll n; 
    cin >> n;
    ll k;
    cin >> k;
    // dp[i][0] -> messi takes ith pass 
    // dp[i][1] -> messi doesn't takes ith pass
    vector<vector<ll>> dp(n + 1, vector<ll> (2, 0));
    dp[0][0] = 1; dp[0][1] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = (dp[i - 1][1] * k) % mod;
        // previous taken + previous not taken which might have been taken
        // by a player and we cannot count him again i.e., * (k - 1)
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * (k - 1)) % mod;
    }
    cout << dp[n][0] << endl;
}

/*.....................................................................*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}
