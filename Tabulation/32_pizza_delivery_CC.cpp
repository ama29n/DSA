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

// https://www.codechef.com/submit/DBOY

// Dry run to understand the code
// Here dp[i] will store the minimum number of times a fuel store is required to reach ith km

/*.....................................................................*/

void solve() {
    int n; 
    cin >> n;
    vector<int> distance(n);
    forn(i, n) {
        cin >> distance[i];
    }
    vector<int> fuel(n);
    forn(i, n) {
        cin >> fuel[i];
    }
    vector<int> dp(1001, 99999);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = fuel[i]; j < dp.size(); j++) {
            dp[j] = min(dp[j], dp[j - fuel[i]] + 1);
        }
    }
    int ans = 0;
    forn(i, n) {
        ans += dp[2 * distance[i]];
    }
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
