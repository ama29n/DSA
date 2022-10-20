#include <bits/stdc++.h>
using namespace std;

const int mod = 1E9 + 7; const string yes = "YES"; const string no = "NO"; typedef long long ll;

#define pb            push_back
#define mem(a, i)     memset(a, i, sizeof(a))
#define ff            first
#define ss            second
#define all(v)        v.begin(), v.end()
#define rall(v)       v.rbegin(), v.rend()
#define forn(i, n)    for(int i = 0; i < n; i++)

// https://www.codechef.com/submit/ORTUPLES

/*...............................................................................*/

void solve() {
    int p, q, r;
    cin >> p >> q >> r;
    ll ans = 1;
    for(int i = 0; i < 32; i++) {
        bool a = (p & (1 << i));
        bool b = (q & (1 << i));
        bool c = (r & (1 << i));
        int count = a + b + c;
        if(count == 0 || count == 2) {
            ans *= 1;
        } else if(count == 3) {
            ans *= 4;
        } else {
            cout << 0;
            return;
        }
    }
    cout << ans;
}

/*...............................................................................*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
        cout << endl;
    }
}
