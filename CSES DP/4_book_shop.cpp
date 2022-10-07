#include <bits/stdc++.h>
using namespace std;

const int MOD = 1E9 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define pb          push_back
#define mem(a, i)   memset(a, i, sizeof(a))
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// https://cses.fi/problemset/task/1158/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> price(n), pages(n);

    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    vector<vector<int>> dp(n + 1, vector<int> (x + 1));

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                if(price[i - 1] <= j) 
                    dp[i][j] = max(pages[i - 1] + dp[i - 1][j - price[i - 1]], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][x];
}
