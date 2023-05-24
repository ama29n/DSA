#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimum-swaps/1 

class Solution {
    public:
	int minSwaps(vector<int> &nums) {
	    int n = nums.size();
	    vector<pair<int, int>> arr(n);
	    for(int i = 0; i < n; i++) {
	        arr[i] = {nums[i], i};
	    }
	    sort(arr.begin(), arr.end());
	    int swaps = 0;
	    vector<int> vis(n, 0);
	    for(int i = 0; i < n; i++) {
	        if(vis[i] || arr[i].second == i) continue;
	        int cycle = 0;
	        int j = i;
	        while(!vis[j]) {
	            vis[j] = 1;
	            j = arr[j].second;
	            cycle++;
	        }
	        swaps += (cycle - 1);
	    }
	    return swaps;
	}   
};