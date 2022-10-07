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

// https://cses.fi/problemset/task/1636/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // dp[t] will represent number of ways to make target t 
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = coins[i]; j < dp.size(); j++) {
            dp[j] += dp[j - coins[i]];
            dp[j] %= MOD;
        }
    }

    cout << dp[target] % MOD;
}
