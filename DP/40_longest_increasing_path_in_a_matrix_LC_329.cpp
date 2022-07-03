#include <bits/stdc++.h>
using namespace std;

int find(int i, int j, int prev, vector<vector<int>>& matrix, int m, int n, vector<vector<int>>& dp) {
    if(i < 0 || j < 0 || i >= m || j >= n)
        return 0;
    if(matrix[i][j] <= prev)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int up = find(i - 1, j, matrix[i][j], matrix, m, n, dp);
    int down = find(i + 1, j, matrix[i][j], matrix, m, n, dp);
    int left = find(i, j - 1, matrix[i][j], matrix, m, n, dp);
    int right = find(i, j + 1, matrix[i][j], matrix, m, n, dp);
    return dp[i][j] = max({up, down, left, right}) + 1;
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
    int ans = INT_MIN;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, find(i, j, -1, matrix, m, n, dp));
        }
    }
    return ans;
}