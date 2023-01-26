#include<bits/stdc++.h>
using namespace std;

// fixed starting point but variable end point

int path(int rows, int ele, vector<vector<int>>& triangle) {
    if(rows == triangle.size() - 1)
        return triangle[rows][ele];
    
    int down = path(rows + 1, ele, triangle);
    int diaDown = path(rows + 1, ele + 1, triangle);
    
    return triangle[rows][ele] + min(down, diaDown);
}

int minimumTotal(vector<vector<int>>& triangle) {
    if(triangle.size() == 1) return triangle[0][0];
    
    int rows = triangle.size();
    return path(0, 0, triangle);
}



// Memoization

int find(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
	if(j >= triangle[i].size())
		return 10001;
	if(i == triangle.size() - 1)
		return triangle[i][j];
	if(dp[i][j] != -1)
		return dp[i][j];

	int bottom = find(i + 1, j, triangle, dp);
	int bottomRight = find(i + 1, j + 1, triangle, dp);

	return dp[i][j] = min(bottom, bottomRight) + triangle[i][j];
}
int minimumTotal(vector<vector<int>>& triangle) {
	int m = triangle.size(), n = triangle[m - 1].size();
	vector<vector<int>> dp(m, vector<int> (n, -1));
	return find(0, 0, triangle, dp);
}




// Tabulation

class Solution {
public:
    // 2
    // 3 4
    // 6 5 7
    // 4 1 8 3
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m - 1].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int i = m - 1; i >= 0; i--) {
            int k = triangle[i].size() - 1;
            for(int j = k; j >= 0; j--) {
                if(i == m - 1) {
                    dp[i][j] = triangle[i][j];
                } else {
                    int d = dp[i + 1][j], r = dp[i + 1][j + 1];
                    dp[i][j] = min(d, r) + triangle[i][j];
                }
            }
        }
        return dp[0][0];
    }
};