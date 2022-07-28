#include <bits/stdc++.h>
using namespace std;

#define MOD 1E9 + 7
#define ll long long int

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n % 2 == 0) {
        cout << "BOB" << endl;
        return;
    }
    if(s[n / 2] == '1') {
        cout << "BOB" << endl;
        return;
    }

    int count = 0;
    for(auto it : s) {
        if(it == '0')
            count++;
        if(count > 1)
            break;
    }
    if(count == 1) {
        cout << "BOB" << endl;
        return;
    }
    cout << "ALICE" << endl;
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
