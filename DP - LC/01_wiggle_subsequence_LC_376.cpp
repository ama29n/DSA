#include <bits/stdc++.h>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if(n == 1)
        return 1;
    
    vector<int> arr;
    for(int i = 1; i < n; i++)
        if(nums[i] - nums[i - 1] != 0)
            arr.push_back(nums[i] - nums[i - 1]);
    
    vector<int> dp(arr.size(), 1); 
    for(int i = 1; i < arr.size(); i++) {
        int maxi = 1;
        for(int j = 0; j < i; j++) {
            if(arr[i] > 0) {
                if(arr[j] < 0)
                    maxi = max(maxi, dp[j] + 1);
            } else {
                if(arr[j] > 0)
                    maxi = max(maxi, dp[j] + 1);
            }
        }
        dp[i] = maxi;
    }
    int ans = 0;
    for(auto it : dp)
        ans = max(ans, it);
    return ans + 1;
}