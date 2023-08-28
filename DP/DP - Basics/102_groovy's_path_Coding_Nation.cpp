#include<bits/stdc++.h>
using namespace std;

long cal(long i, long j, long n, long b, vector<vector<long>>& dp) {
    if(i >= n || j >= n)
        return 0;
    long  m = n / 2;
    if(i == m && j == m)
        return 0;
    if(i >= m - b && i <= m + b && j >= m - b && j <= m + b)
        return 0;
    if(i == n - 1 && j == n - 1)
        return 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    long mod = 1e9 + 7;
    long down = cal(i + 1, j, n, b, dp);
    long right = cal(i, j + 1, n, b, dp);
    down %= mod;
    right %= mod;
    return dp[i][j] = (down + right) % mod;
}
long  solve(long  A, long  B) {
    vector<vector<long>> dp(A, vector<long> (A, -1));
    long ans = cal(0, 0, A, B, dp);
    return ans;
}

int main() {
    cout << solve(77, 26);
}
