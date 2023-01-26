// You are given a number n, representing the number of stairs in a staircase.
// You are on the 0th step and are required to climb to the top.
// In one move, you are allowed to climb 1, 2 or 3 stairs.
// You are required to print the number of different paths via which you can climb to the top.

// Basic Recursion

#include <bits/stdc++.h>
using namespace std;

// int cs(int n) {
//     if(n == 0) return 1;
//     if(n < 0) return 0;
//     else {
//         int step1 = cs(n - 1);
//         int step2 = cs(n - 2);
//         int step3 = cs(n - 3);
//         int ways = step1 + step2 + step3;
//         return ways;
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     cout << cs(n) << endl;
// }


// Memoisation

// int cs(int n, vector<int> &dp) {
//     if(n == 0) return 1;
//     else if(n < 0) return 0;
//     else if(dp[n] != 0) return dp[n];
//     else {
//         int step1 = cs(n - 1, dp);
//         int step2 = cs(n - 2, dp);
//         int step3 = cs(n - 3, dp);
//         int ways = step1 + step2 + step3;
//         dp[n] = ways;
//         return ways;
//     }
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> dp(n + 1, 0);
//     cout << cs(n, dp) << endl;
// }


// Tabulation

