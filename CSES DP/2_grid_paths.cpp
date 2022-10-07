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

// https://cses.fi/problemset/task/1638/

// Consider an n×n grid whose squares may have traps. It is not allowed to move to a square with a trap.

// Your task is to calculate the number of paths from the upper-left square to the lower-right square. 
// You can only move right or down.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int> (n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            if(ch == '*')
                grid[i][j] = 1;
        }
    }

    if(grid[0][0] == 1 || grid[n - 1][n -1 ] == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<ll>> dp(n, vector<ll> (n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
            } else {
                int u = 0, l = 0;
                if(i > 0 && grid[i - 1][j] != 1)
                    u = dp[i - 1][j] % MOD;
                if(j > 0 && grid[i][j - 1] != 1)
                    l = dp[i][j - 1] % MOD;
                dp[i][j] = (u + l) % MOD; 
            }
        }
    }

    cout << dp[n - 1][n - 1] % MOD;
}
