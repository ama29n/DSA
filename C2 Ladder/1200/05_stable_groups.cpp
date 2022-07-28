#include <bits/stdc++.h>
using namespace std;

#define MOD 1E9 + 7
#define ll long long int

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<int> dif;
    for(int i = 1; i < n; i++) {
        if(v[i] - v[i - 1] > x)
            dif.push_back(v[i] - v[i - 1]);
    }

    sort(dif.begin(), dif.end());

    int idx = dif.size();

    for(int i = 0; i < dif.size(); i++) {
        int gap = dif[i] / x;
        if(dif[i] % x == 0)
            gap--;

        if(gap <= k)
            k -= gap;
        else {
            idx = i;
            break;
        }
    }

    cout << dif.size() - idx + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
