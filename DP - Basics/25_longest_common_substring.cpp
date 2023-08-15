#include<bits/stdc++.h>
using namespace std;

int lcs(string &s, string &t) {
    int n = s.size(), m = t.size();
	vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
        }
    }
    int maxx = INT_MIN;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            maxx = max(dp[i][j], maxx);
    return maxx;
}
