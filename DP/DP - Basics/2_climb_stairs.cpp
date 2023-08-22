#include <bits/stdc++.h>
using namespace std;

// Memoization
int cs(int n, vector<int> &dp) {
    if(n == 0) {
        return 1;
    } 
    if(n < 0) {
        return 0;
    }
    if(dp[n] != 0) {
        return dp[n];
    }
    int step1 = cs(n - 1, dp);
    int step2 = cs(n - 2, dp);
    int step3 = cs(n - 3, dp);
    int ways = step1 + step2 + step3;
    dp[n] = ways;
    return ways;
}
int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    cout << cs(n, dp) << endl;
}
