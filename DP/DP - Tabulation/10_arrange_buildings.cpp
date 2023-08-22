#include <bits/stdc++.h>
using namespace std;

// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/arrange-buildings-official/ojquestion

// 1. You are given a number n, which represents the length of a road. The road has n plots on it's each side.
// 2. The road is to be so planned that there should not be consecutive buildings on either side of the road.
// 3. You are required to find and print the number of ways in which the buildings can be built on both side of roads.

int main() {
    int n;
    cin >> n;
    // dp[i][0] -> number of ways till ith pos and house is not considered
    // dp[i][1] -> number of ways till ith pos and house is considered
    vector<vector<int>> dp(n + 1, vector<int> (2, 0));
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    long long ans = dp[n][0] + dp[n][1];
    cout << ans * ans << endl;
}