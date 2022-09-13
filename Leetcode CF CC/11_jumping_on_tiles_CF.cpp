#include <bits/stdc++.h>
using namespace std;

#define MOD 1E9 + 7

// https://codeforces.com/contest/1729/problem/C

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define pb          push_back
#define mem(a, ch)   memset(a, ch, sizeof(a))
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> v;
    ll ans = 0;
    char prev = s[0];

    if(s[0] < s[n - 1]) {
        for(char ch = s[0]; ch <= s[n - 1]; ch++)
            for(int j = 0; j < n; j++)
                if(s[j] == ch) {
                    v.push_back(j + 1);
                    ans += abs(prev - s[j]);
                    prev = s[j];
                }
    } else {
        for(char ch = s[0]; ch >= s[n - 1]; ch--)
            for(int j = 0; j < n; j++)
                if(s[j] == ch) {
                    v.push_back(j + 1);
                    ans += abs(prev - s[j]);
                    prev = s[j];
                }
    }

    cout << ans << " " << v.size() << endl;
    for(auto it : v)
        cout << it << " ";
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
