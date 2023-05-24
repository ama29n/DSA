#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1 

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>> edges){
	    vector<int> path(n, (int)1E9);
	    path[0] = 0;
	    for(int j = 0; j < n; j++) {
	        for(auto it : edges) {
	            if(path[it[0]] + it[2] < path[it[1]]) {
	                path[it[1]] = path[it[0]] + it[2];
	            }
	        }
	    }
	    for(int i = 0; i < n; i++) {
	        for(auto it : edges) {
	            if(path[it[0]] + it[2] < path[it[1]]) {
	                return 1;
	            }
	        }
	    }
	    return 0;
	}
};