#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1? 

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>> &edges, int T) {
        vector<vector<int>> matrix(n, vector<int> (n, -1));
        for(auto it : edges) {
            matrix[it[0]][it[1]] = it[2];
            matrix[it[1]][it[0]] = it[2];
        }
        for(int k = 0; k < n; k++) {
	        for(int i = 0; i < n; i++) {
	            for(int j = 0; j < n; j++) {
	                if(matrix[i][k] != -1 && matrix[k][j] != -1) {
	                    int x = matrix[i][k] + matrix[k][j];
	                    if(matrix[i][j] == -1 || x < matrix[i][j]) {
	                        matrix[i][j] = x;
	                    }
	                }
	            }
	        }
	    }
	    int ans, count = INT_MAX;
	    for(int i = 0; i < n; i++) {
	        int x = 0;
	        for(int j = 0; j < n; j++) {
	            if(i == j) continue;
	            if(matrix[i][j] <= T && matrix[i][j] != -1) x++;
	        }
	        if(x < count) { count = x; ans = i; }
	        else if(x == count) ans = i;
	    }
	    return ans;
    }
};