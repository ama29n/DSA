#include <bits/stdc++.h>
using namespace std;

const int mod = 1E9 + 7; const string yes = "YES", no = "NO"; typedef long long ll;

#define pb            push_back
#define ff            first
#define ss            second
#define all(v)        v.begin(), v.end()
#define rall(v)       v.rbegin(), v.rend()
#define forn(i, n)    for(int i = 0; i < n; i++)

// https://www.codechef.com/submit/NZXOR

// Pre requisite - Number of subarrays with xor k or 0

/*...............................................................................*/

void solve() {
    int n; 
    cin >> n;
    vector<int> v(n);
    forn(i, n) {
        cin >> v[i];
    }
    ll x = 0;
    int ans = 0;
    set<ll> s;
    for(auto it : v) {
        x ^= it;
        // If for a prefix subarray, the xor is 0
        // Or we find a prefix subarray with xor already being present in the array, it means the elements between
        // that index and current index have xor 0
        if(x == 0 || s.find(x) != s.end()) {
            x = 0;
            ans++;
            s.clear();
        } else {
            s.insert(x);
        }
    }
    cout << ans << endl;
}

/*...............................................................................*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}
