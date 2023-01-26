#include<bits/stdc++.h>
using namespace std;

int find(int i, int w, vector<int>& weight, vector<int>& value, vector<vector<int>>& dp) {
	if(w == 0)
		return 0;
	if(i == 0) {
		if(weight[0] <= w) return value[0];
		return 0;
	}
	if(dp[i][w] != -1)
		return dp[i][w];
	int notTake = find(i - 1, w, weight, value, dp);
	int take = 0;
	if(weight[i] <= w) 
		take = value[i] + find(i - 1, w - weight[i], weight, value, dp);
	return dp[i][w] = max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp(n, vector<int> (maxWeight + 1, -1));
	return find(n - 1, maxWeight, weight, value, dp);
}






// Tabulation 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp(n, vector<int> (maxWeight + 1, 0));
	for(int i = 0; i < n; i++) 
		dp[i][0] = 0;
	for(int w = weight[0]; w <= maxWeight; w++)
		dp[0][w] = value[0];
	for(int i = 1; i < n; i++) {
		for(int w = 1; w <= maxWeight; w++) {
			int notTake = dp[i - 1][w];
			int take = 0;
			if(weight[i] <= w)
				take = value[i] + dp[i - 1][w - weight[i]];
			dp[i][w] = max(take, notTake);
		}
	}
	return dp[n - 1][maxWeight];
}