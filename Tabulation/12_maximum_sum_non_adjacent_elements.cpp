#include <bits/stdc++.h>
using namespace std;

// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/maximum-sum-non-adjacent-elements-official/ojquestion

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    // dp[i][0] -> maximum sum if the current element is considered
    // dp[i][1] -> maximum sum if the current element is not considered
    vector<vector<long long>> dp(n, vector<long long> (2, 0));
    dp[0][0] = v[0];
    for(int i = 1; i < n; i++) {
        // dp[i][i] = dp[i - 1][0], if there are no negative elements in the array
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][0] = dp[i - 1][1] + v[i];
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]);
}