#include <bits/stdc++.h>
using namespace std;

#define MOD 1E9 + 7
#define ll long long int

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    int a, b, dif = INT_MAX;
    for(int i = 0; i < n - 1; i++)
        if(v[i + 1] - v[i] < dif) {
            dif = v[i + 1] - v[i];
            a = i + 1;
            b = i;
        }

    vector<int> ans;

    ans.push_back(v[b]);
    for(int i = a + 1; i < n; i++)
        ans.push_back(v[i]);
    for(int i = 0; i < b; i++)
        ans.push_back(v[i]);
    ans.push_back(v[a]);

    for(auto it : ans)
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
