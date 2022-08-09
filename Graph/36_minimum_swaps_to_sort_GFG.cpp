#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>& nums) {
	    int n = nums.size();
	    pair<int, int> arr[n];
	    for(int i = 0; i < n;  i++) {
	        arr[i].first = nums[i];
	        arr[i].second = i;
	    }
	    sort(arr, arr + n);
	    int ans = 0;
	    vector<int> vis(n, 0);
	    for(int i = 0; i < n; i++) {
	        if(vis[i] || arr[i].second == i)
	            continue;
	        int cycleLength = 0;
	        int j = i;
	        while(!vis[j]) {
	            cycleLength++;
	            vis[j] = 1;
	            j = arr[j].second;
	        }
	        ans += cycleLength - 1;
	    }
	    return ans;
	}
};