#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1 

// Single source shortest path algorithm.

// Bellman-Ford algorithm is also guaranteed to find the shortest path in a graph, similar to Dijkstra’s algorithm. 

// It is slower than Dijkstra’s algorithm, but it is capable of handling graphs with negative edge weights.

// The shortest path cannot be found if there exists a negative cycle in the graph. 

// If we continue to go around the negative cycle an infinite number of times, 
// then the cost of the path will continue to decrease (even though the length of the path is increasing).

// As a result, Bellman-Ford is also capable of detecting negative cycles, which is an important feature.

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>> edges){
	    vector<int> path(n, (int)1E9);
	    path[0] = 0;
	    for(int j = 0; j < n - 1; j++) {
	        for(auto it : edges) {
	            if(path[it[0]] + it[2] < path[it[1]]) {
	                path[it[1]] = path[it[0]] + it[2];
	            }
	        }
	    }
	    for(auto it : edges) {
            if(path[it[0]] + it[2] < path[it[1]]) {
                return 1;
            }
        }
	    return 0;
	}
};

// In the worst-case scenario, a shortest path between two vertices can have at most N-1 edges, 
// where N is the number of vertices. This is because a simple path in a graph with N vertices can have at most N-1 edges, 
// as it’s impossible to form a closed loop without revisiting a vertex.