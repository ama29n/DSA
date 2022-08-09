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

unsigned int countSetBits(unsigned int n) {
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void solve() {
    int n;
    cin >> n;
    set<int> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp.insert(x);
    }
    int dis = mp.size();
    for(int i = 1; i <= n; i++) {
        if(i <= dis) {
            cout << dis << " ";
        } else {
            cout << ++dis << " ";
        }
    }
    cout << endl;
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