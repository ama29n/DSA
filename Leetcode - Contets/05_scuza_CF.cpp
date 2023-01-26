#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1E9 + 7;
 
const string yes = "YES";
const string no = "NO";
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
#define pb          push_back
#define mem(a, i)   memset(a, i, sizeof(a))
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()
 
vector<int> Factors(int n) { vector<int> ans; for (int i = 1; i * i <= n; i++) { if(n % i == 0) { ans.push_back(i); if((n / i) != i) ans.push_back(n / i); } } return ans; }

// https://codeforces.com/problemset/problem/1742/E 

void solve() {
    int n, q; 
    cin >> n >> q;
    vector<int> v(n), h(q);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < q; i++) {
        cin >> h[i];
    }
    vector<ll> pre(n, 0);
    pre[0] = v[0];
    for(int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }
    vector<int> maxi(n);
    maxi[0] = v[0];
    for(int i = 1; i < n; i++) {
        maxi[i] = max(maxi[i - 1], v[i]);
    }
    vector<ll> ans;
    for(auto it : h) {
        // If height is 0, can't step up
        if(it == 0) {
            cout << 0 << " ";
            continue;
        }
        int idx = upper_bound(all(maxi), it) - maxi.begin() - 1;
        // If height is smaller than the first step
        if(idx == -1) {
            cout << 0 << " ";
            continue;
        }
        cout << pre[idx] << " ";
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