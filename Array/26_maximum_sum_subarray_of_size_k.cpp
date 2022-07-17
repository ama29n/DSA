#include<bits/stdc++.h>
using namespace std;


// Computation 
// Prefix Sum
long maximumSumSubarray(int k, vector<int> &nums, int n) {
    vector<long> pre(n + 1, 0);
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + nums[i - 1];
    long ans = 0; 
    for(int i = k; i <= n; i++)
        ans = max(ans, pre[i] - pre[i - k]);
    return ans;
}