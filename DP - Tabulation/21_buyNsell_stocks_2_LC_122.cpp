#include<bits/stdc++.h>
using namespace std;

// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/buy-and-sell-stocks-ita-official/ojquestion

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

void transaction(vector<int>& arr) {
    int n = arr.size();
    // dp[i][0] -> total profit if we have to buy the ith stock
    // dp[i][1] -> total profit if we have to sell the ith stock
    vector<vector<int>> dp(n, vector<int> (2, 0));
    dp[0][0] = 0 - arr[0];
    for(int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1] - arr[i], dp[i - 1][0]); 
        dp[i][1] = max(dp[i - 1][0] + arr[i], dp[i - 1][1]);
    }
    cout << dp[n - 1][1];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    transaction(arr);
}