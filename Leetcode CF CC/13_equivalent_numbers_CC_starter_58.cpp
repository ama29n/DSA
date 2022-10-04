#include <bits/stdc++.h>
using namespace std;

#define MOD 1E9 + 7

// https://www.codechef.com/submit/EQUIVALENT?tab=statement

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define pb          push_back
#define mem(a, i)   memset(a, i, sizeof(a))
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// b is small

// In order for a and b to be equal, 2 conditions must satisfy:
// 1. Both the number should have the same prime factors.
// 2. The ratio of frequency of each prime factors of the two numbers should be the same.

void cal(int a, int b) {
    if(a % b != 0) {
        cout << "NO" << endl;
        return;
    }
    if(a == b) {
        cout << "YES" << endl;
        return;
    }
    a /= b;
    if(a > b)
        cal(a, b);
    else 
        cal(b, a);
}

void solve() {
    int a, b;
    cin  >> a >> b;
    if(a > b)
        cal(a, b);
    else 
        cal(b, a);
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