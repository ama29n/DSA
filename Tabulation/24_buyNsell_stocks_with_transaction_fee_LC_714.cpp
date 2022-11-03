#include <iostream>
#include <vector>

using namespace std;

void transactions(vector<int> arr, int fee) {
    int n = arr.size();
    // dp[i][0] -> total profit if we have to buy the stock at arr[i] price
    // dp[i][1] -> total profit if we have to sell the stock at arr[i] price
    vector<vector<int>> dp(n, vector<int> (2, 0));
    dp[0][0] = 0 - arr[0];
    for(int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1] - arr[i], dp[i - 1][0]); 
        dp[i][1] = max(dp[i - 1][0] + arr[i] - fee, dp[i - 1][1]);
    }
    cout << dp[n - 1][1];
}
int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
  int fee;
  cin >> fee;

  transactions(arr, fee);

  return 0;
}