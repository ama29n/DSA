#include <bits/stdc++.h>
using namespace std;

// Recursive 
// exponential time complexity - 2 raised to power m * 2 raised to power n


// Memoization
int find(int i, int j, string s, string t, vector<vector<int>>& dp) {
    // We cannot use this base case as this doesn't allows us to go beyond the point if any one of the indiices become 0, 
    // i = 0 and j = 3 what if they don't match but at j = 2 they match... we won't go furthur with this base case
    if(i < 0 || j < 0)
        return 0;
    if(s[i] == t[j])
        return 1 + find(i - 1, j - 1, s, t, dp);
    if(dp[i][j] != -1)
        return dp[i][j];

    int a = find(i - 1, j, s, t, dp);
    int b = find(i, j - 1, s, t, dp);

    return dp[i][j] = max(a, b);
}
int longestCommonSubsequence(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
    return find(n - 1, m - 1, s, t, dp);
}

// time - O(m * n)
// space - O(m * n) (dp array) + O(m + n) stack




// tabulation

int longestCommonSubsequence(string s, string t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i - 1] == t[j - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

