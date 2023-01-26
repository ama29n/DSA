#include <bits/stdc++.h>
using namespace std;

const int mod = 1E9 + 7; const string yes = "YES", no = "NO"; typedef long long ll;

// https://www.codechef.com/submit/FCBARCA

/*.....................................................................*/

void solve() {
    int n; 
    cin >> n;
    int k;
    cin >> k;
    // dp[i][0] -> ways, when pass is made to messi
    // dp[i][1] -> ways, when pass is not made to messi
    vector<vector<ll>> dp(n + 1, vector<ll> (2, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = ((((dp[i - 1][1] * (k - 1)) % mod) + ((dp[i - 1][0] * k) % mod)) % mod);
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
