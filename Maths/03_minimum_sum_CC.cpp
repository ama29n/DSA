#include <bits/stdc++.h>
using namespace std;

// You are given an array A. You can choose two indices i and j and replace either A(i) or A(j) with gcd(A(i), A(j))
// Find minimum possible sum of array

#define MOD 1E9 + 7

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define pb          push_back
#define mem(a, i)   memset(a, i, sizeof(a))
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int g = v[0];
    for(int i = 1; i < n; i++)
        g = __gcd(g, v[i]);
    cout << n * g << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}
