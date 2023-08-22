#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353; const string yes = "YES", no = "NO"; typedef long long ll;

#define pb            push_back
#define mem(a, i)     memset(a, i, sizeof(a))
#define ff            first
#define ss            second
#define all(v)        v.begin(), v.end()
#define rall(v)       v.rbegin(), v.rend()
#define forn(i, n)    for(int i = 0; i < n; i++)

// https://www.codechef.com/submit/BINARYSUB

/*.....................................................................*/

// If 2 consecutive alphabets are same, then the count will remain same
// else, add dp[i - 2]

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<ll> dp(n, 0);
    dp[0] = 1;
    dp[1] = s[0] == s[1] ? 1 : 2;
    for(int i = 2; i < n; i++) {
        dp[i] = dp[i - 1];
        if(s[i] != s[i - 1])
            dp[i] += dp[i - 2];
        dp[i] %= mod;
    }
    cout << dp[n - 1] << endl;
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
