#include <bits/stdc++.h>
using namespace std;

const int mod = 1E9 + 7; const string yes = "YES", no = "NO"; typedef long long ll;

#define forn(i, n)    for(int i = 0; i < n; i++)

// https://www.codechef.com/submit/MAXCOMP

/*.....................................................................*/

void solve() {
    int n; 
    cin >> n;
    vector<int> s(n), e(n), c(n);
    int max_s = 0, max_e = 0;
    vector<vector<int>> nums(49, vector<int> (49, 0));
    forn(i, n) {
        int x, y, z; cin >> x >> y >> z;
        s[i] = x; e[i] = y; c[i] = z;
        nums[x][y] = max(nums[x][y], z);
        max_s = max(max_s, x); max_e = max(max_e, y);
    }
    vector<int> dp(49, 0);
    for(int j = 0; j <= max_e; j++) {
        for(int i = 0; i <= max_s; i++) {
            if(nums[i][j] != 0)
                dp[j] = max(dp[j], nums[i][j] + dp[i]);
        }
        dp[j] = max(dp[j], dp[j - 1]);
    }
    cout << dp[max_e] << endl;
}

/*.....................................................................*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}
