#include <bits/stdc++.h>
using namespace std;

// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/paint-house-official/ojquestion

int main() {
    int n;
    cin >> n;
    vector<int> red(n), blue(n), green(n);
    for(int i = 0; i < n; i++) {
        cin >> red[i] >> blue[i] >> green[i];
    }
    vector<vector<int>> dp(n, vector<int> (3, 0));
    dp[0][0] = red[0]; dp[0][1] = blue[0]; dp[0][2] = green[0];
    for(int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + red[i];
        dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + blue[i];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + green[i];
    }
    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}