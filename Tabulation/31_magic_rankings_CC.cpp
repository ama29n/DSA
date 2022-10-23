#include <bits/stdc++.h>
using namespace std;

const int mod = 1E9 + 7; const string yes = "YES", no = "NO";

#define pb            push_back
#define mem(a, i)     memset(a, i, sizeof(a))
#define ff            first
#define ss            second
#define all(v)        v.begin(), v.end()
#define rall(v)       v.rbegin(), v.rend()
#define forn(i, n)    for(int i = 0; i < n; i++)

// https://www.codechef.com/submit/MGCRNK

/*.....................................................................*/

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = 0;
            } else {
                int u = INT_MIN, l = INT_MIN;
                if(i > 0)
                    u = dp[i - 1][j];
                if(j > 0)
                    l = dp[i][j - 1];
                dp[i][j] = max(u, l) + grid[i][j];
            }
        }
    }
    double ans = (double)dp[n - 1][n - 1] / double((n * 2) - 3);
    if(dp[n - 1][n - 1] < 0) {
        cout << "Bad Judges" << endl;
    } else {
        cout << fixed << setprecision(6) << ans << endl;
    }
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
