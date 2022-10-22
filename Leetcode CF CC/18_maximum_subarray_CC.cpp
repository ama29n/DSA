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

// https://www.codechef.com/submit/MAXSUBARR

// We can add 2nd subarrays all positive elements to the maximum subarray of 1st array

/*......................................................................*/

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    int m; cin >> m;
    vector<int> b(m);
    forn(i, m) cin >> b[i];
    
    ll ans = LLONG_MIN;
    ll sum;
    sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        ans = max(ans, sum);
    }
    sum = 0;
    for(int i = n - 1; i >= 0; i--) {
        sum += a[i];
        ans = max(ans, sum);
    }
    for(auto it : b)
        if(it > 0)
            ans += it;
    cout << ans << endl;
}

/*.......................................................................*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}
