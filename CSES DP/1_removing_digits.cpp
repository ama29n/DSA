#include <bits/stdc++.h>
using namespace std;

#define MOD 1E9 + 7

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define pb          push_back
#define mem(a, i)   memset(a, i, sizeof(a))
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// https://cses.fi/problemset/task/1637/

// You are given an integer n. On each step, you may subtract one of the digits from the number.

// Input:
// 27
// Output:
// 5
// Explanation: An optimal solution is 27 -> 20 -> 18 -> 10 -> 9 -> 0.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        set<int> s;
        int c = i;
        while(c != 0) {
            int x = c % 10;
            c /= 10;
            if(x != 0)
                s.insert(x);
        }
        for(auto it : s) {
            if(i - it >= 0)
                dp[i] = 1 + min(dp[i], dp[i - it]);
        }
    }
    cout << dp[n];
}
