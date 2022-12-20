#include <bits/stdc++.h>
using namespace std;

const int mod = 1E9 + 7; const string yes = "YES", no = "NO"; typedef long long ll;

#define forn(i, s, n)    for(int i = s; i < n; i++)
#define pb               push_back
#define sp               << ' ' <<
#define nl               << '\n'

// https://codeforces.com/contest/1747/problem/D

/*.....................................................................*/

void solve() {
    int n; 
    cin >> n;
    vector<int> v(n);
    forn(i, 0, n) {
        cin >> v[i];
    }
    for(int i = 0; i + 1 < n; i++) {
        int x = 32 - __builtin_clz(v[i] ^ v[i + 1]);
        v[i] = (v[i] < v[i + 1] ? -1 : 1) * x;
    }
    map<int, int> m;
    int ans = 1;
    for(int i = 0, left = 0; i + 1 < n; i++) {
        if(m.find(-v[i]) != m.end()) {
               left = max(m[-v[i]] + 1, left);
            }
        m[v[i]] = i;
        ans = max(ans, i - left + 2);
    }
    cout << ans nl;
}

// 15 1111      XOR

// 14 1110     0001 -> 1
// 11 1011  3  0100 -> 4
//  9 1001  2  0110 -> 6
//  3 0011  4  1100 -> 12
//  7 0111 -3  1000 -> 8

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
