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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    
    int count = 0;
    for(auto it : s)
        if(it == '1')
            count++;
    if(count == 0) {
        cout << s.size() * m << endl;
        return;
    }
    
    vector<int> pre(n, 0), suf(n + 1, 0);
    pre[0] = s[0] - '0';
    for(int i = 1; i < n; i++) {
        if(s[i] == '1') {
            pre[i] = pre[i - 1] + 1;
        } else {
            pre[i] = pre[i - 1];
        }
    }
    suf[n - 1] = s[n - 1] - '0';
    for(int i = n - 2; i >= 0; i--) {
        if(s[i] == '1') {
            suf[i] = suf[i + 1] + 1;
        } else {
            suf[i] = suf[i + 1];
        }
    }
    int ans = 0;
    if(m % 2 != 0) {
        for(int i = 0; i < n; i++)
            if(pre[i] == suf[i + 1])
                ans++;
    } else {
        for(int i = 0; i < n; i++) {
            if(pre[i] != suf[i + 1] && abs(pre[i] - suf[i + 1]) % count == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
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
