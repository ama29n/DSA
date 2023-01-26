#include <bits/stdc++.h>
using namespace std;

const int mod = 1E9 + 7; const string yes = "YES", no = "NO"; typedef long long ll;

#define pb            push_back
#define mem(a, i)     memset(a, i, sizeof(a))
#define ff            first
#define ss            second
#define all(v)        v.begin(), v.end()
#define rall(v)       v.rbegin(), v.rend()
#define forn(i, n)    for(int i = 0; i < n; i++)

// https://www.codechef.com/submit/POGOSTCK

/*.....................................................................*/

void solve() {
    int n, k; 
    cin >> n >> k;
    vector<int> v(n);
    forn(i, n) {
        cin >> v[i];
    }
    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++) {
        if(i < k) {
            dp[i] = v[i];
        } else {
            dp[i] = max(v[i], dp[i - k] + v[i]);
        }
    }
    int ans = INT_MIN;
    for(int i = n - 1; i >= n - k; i--)
        ans = max(ans, dp[i]);
    cout << ans << endl;
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
