#include <bits/stdc++.h>
using namespace std;

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
    int n, k;
    cin >> n >> k;
    
    if(n % 2 == 0) {
        int a = n / 2;
        if(a % 2 != 0)
            cout << 2 << " " << a - 1 << " " << n - a - 1 << endl;
        else
            cout << a << " " << a / 2 << " " << a / 2 << endl;
    } else {
        n--;
        cout << 1 << " " << n / 2 << " " << n / 2 << endl;
        }
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
