#include <bits/stdc++.h>
using namespace std;

const int mod = 1E9 + 7; const string yes = "YES", no = "NO"; typedef long long ll;

#define pb            push_back
#define ff            first
#define ss            second
#define all(v)        v.begin(), v.end()
#define rall(v)       v.rbegin(), v.rend()
#define forn(i, n)    for(int i = 0; i < n; i++)
#define mem(a, i)     memset(a, i, sizeof(a))

// https://www.codechef.com/submit/RING_GAME

// The idea is to calculate the continuous one and zero
// Example 1111000 ((4, 3) and pairs are 2) -> 1110100 (pairs are 4), the answer will depend upon the minimum value

/*...............................................................................*/

void solve() {
    int n; 
    cin >> n;
    vector<int> v(n);
    forn(i, n) {
        cin >> v[i];
    }
    int o = 0, z = 0;
    forn(i, n) {
        if(v[i] == v[(i + 1) % n]) {
            v[i] == 1 ? o++ : z++;
        }
    }
    int x = min(o, z);
    if(x % 2 == 0) {
        cout << "BOB" << endl;
    } else {
        cout << "ALICE" << endl;
    }
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
