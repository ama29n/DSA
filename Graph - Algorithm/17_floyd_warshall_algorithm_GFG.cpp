#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1 

class Solution {
  public:
	void shortest_distance(vector<vector<int>> &matrix) {
	    int n = matrix.size();
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
	}
};

// Time Complexity - O(n ^ 3) 