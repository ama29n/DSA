#include<bits/stdc++.h>
using namespace std;

bool cal(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>>& dp) {
	if(i == s1.size())
		return s2.substr(j) == s3.substr(k);
	if(j == s2.size())
		return s1.substr(i) == s3.substr(k);

	if(dp[i][j] != -1)
		return dp[i][j];

	if(s1[i] != s3[k] && s2[j] != s3[k])
		return dp[i][j] = 0;

	bool a = false, b = false;
	if(s3[k] == s1[i])
		a = cal(i + 1, j, k + 1, s1, s2, s3, dp);
	if(s3[k] == s2[j])
		b = cal(i, j + 1, k + 1, s1, s2, s3, dp);

	return dp[i][j] = a || b;
}
bool isInterleave(string s1, string s2, string s3) {
	int i = s1.size(), j = s2.size(), k = s3.size();
	if(i + j != k)
		return false;
	vector<vector<int>> dp(i, vector<int> (j, -1));
	return cal(0, 0, 0, s1, s2, s3, dp);
}