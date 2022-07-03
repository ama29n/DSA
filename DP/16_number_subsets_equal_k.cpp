#include<bits/stdc++.h>
using namespace std;


// Memoization

// Now, this solution is only valid if  nums[i] != 0
// run for example [0, 0, 1]

int calculate(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
    if(sum == 0)
        return 1;
    if(i == 0) 
        return nums[0] == sum;
    if(dp[i][sum] != -1)
        return dp[i][sum];
    
    int notPick = calculate(i - 1, sum, nums, dp);
    int pick = 0;
    if(nums[i] <= sum)
        pick = calculate(i - 1, sum - nums[i], nums, dp);
    
    return dp[i][sum] = pick + notPick;
}

int findWays(vector<int> &nums, int sum) {
    vector<vector<int>> dp(nums.size(), vector<int> (sum + 1, -1));
    return calculate(nums.size() - 1, sum, nums, dp);
}


// Following solution is for the above problems

int calculate(int i, int sum, vector<int>& nums, vector<vector<int>>& dp) {
    
    if(i == 0) {
        if(sum == 0 && nums[0] == 0) return 2;
        if(sum == 0 || sum == nums[0]) return 1;
        return 0;
    }
        
    if(dp[i][sum] != -1)
        return dp[i][sum];
    
    int notPick = calculate(i - 1, sum, nums, dp);
    int pick = 0;
    if(nums[i] <= sum)
        pick = calculate(i - 1, sum - nums[i], nums, dp);
    
    return dp[i][sum] = pick + notPick;
}

int findWays(vector<int> &nums, int sum) {
    vector<vector<int>> dp(nums.size(), vector<int> (sum + 1, -1));
    return calculate(nums.size() - 1, sum, nums, dp);
}






// Memoization 

int findWays(vector<int> &nums, int sum) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (sum + 1, 0));
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    if(nums[0] <= sum) dp[0][nums[0]] = 1;
    
    for(int i = 1; i < n; i ++){
        for(int target = 1; target <= sum; target++) {
            int notPick = dp[i - 1][target];
            int pick = 0;
            if(nums[i] <= target) pick = dp[i - 1][target - nums[i]];
            
            dp[i][target] = pick + notPick;
        }
    }
    return dp[n - 1][sum];
}