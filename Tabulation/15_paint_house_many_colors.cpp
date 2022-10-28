#include <bits/stdc++.h>
using namespace std ;

// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/paint-house-many-colors-official/ojquestion

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> grid(n, vector<int> (k, 0));
  vector<vector<int>> dp(n, vector<int> (k, 0));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < k; j++) {
      cin >> grid[i][j];
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < k; j++) {
      if(i == 0) {
        dp[i][j] = grid[i][j];
      } else {
        int mini = INT_MAX;
        for(int idx = 0; idx < k; idx++) {
          if(idx != j)
            mini = min(mini, dp[i - 1][idx]);
        }
        dp[i][j] = mini + grid[i][j];
      }
    }
  }
  int ans = INT_MAX;
  for(int i = 0; i < k; i++)
    ans = min(ans, dp[n - 1][i]);
  cout << ans << endl;
}