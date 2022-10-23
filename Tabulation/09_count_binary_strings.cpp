#include <bits/stdc++.h>
using namespace std;

// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count-binary-strings-official/ojquestion

// Given n. Find number of strings such that they don't have consecutive zeros.
// For n total strings possible are 2 ^ n.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // dp[i][0] -> Strigns of length i ending with 0
    // dp[i][1] -> Strings of length i ending with 1
    vector<vector<int>> dp(n + 1, vector<int> (2, 0));

    dp[1][0] = dp[1][1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    }
    cout << dp[n][0] + dp[n][1];
}