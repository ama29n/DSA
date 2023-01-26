#include <bits/stdc++.h>
using namespace std;

// Memoization

// int fib(int n, vector<int> &dp) {
//     if (n == 0 || n == 1) return n;

//     if (dp[n] != 0) return dp[n];

//     return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> dp(n + 1, 0);
//     cout << fib(n, dp) << endl;
//     return 0;
// }

// Here every fib(n) will be called only once, because next time the value will be retrieved from the dp. 
// Thus, it will take O(1) per call, hence n*O(1) = O(n)

// Here we are using an additional dp[] array to store the results, which will add to the runtime stack space complexity. 
// Thus overall space complexity is O(n+n) which is the same as O(n)


// Tabulation

// int main() {
//     int n;
//     cin >> n;
//     vector<int> dp(n + 1);
//     dp[0] = 0, dp[1] = 1;
//     for(int i = 2; i <= n; i++)
//         dp[i] = dp[i - 1] + dp[i - 2];
//     cout << dp[n] << endl;
//     return 0;
// }

// Time = O(n)
// Space = O(n)


// 3rd Approach

// using variables

// Time = O(n)
// Space = O(1)