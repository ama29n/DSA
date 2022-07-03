#include<bits/stdc++.h>
using namespace std;

// Recusrsive Solution

// int fn(int idx, vector<int> &nums) {
//     if(idx <= 0) {
//         if(idx == 0) return nums[0];
//         return 0;
//     } else {
//         int pick = nums[idx] + fn(idx - 2, nums);
//         int notPick = fn(idx - 1, nums);
//         return max(pick, notPick);
//     }
// }

// int main() {
//     vector<int> nums {104,209,137,52,158,67,213,86,141,110,151,127,238,147,169,138,240,185,246,225,147,203,83,83,131,227,54,78,165,180,214,151,111,161,233,147,124,143};
//     int ans = fn(nums.size() - 1, nums);
//     cout << ans;
//     // 3176
// }






// // Memoization

// int fn(int idx, vector<int> &nums, vector<int> &dp) {
//     if(idx <= 0) {
//         if(idx == 0) return nums[0];
//         return 0;
//     }
//     if(dp[idx] != -1)
//         return dp[idx];
        
//     int pick = nums[idx] + fn(idx - 2, nums, dp);
//     int notPick = fn(idx - 1, nums, dp);
//     return dp[idx] = max(pick, notPick);
// }
    
// int rob(vector<int>& nums) {
//     vector<int> dp(nums.size(), -1);
//     int ans = fn(nums.size() - 1, nums, dp);
//     return ans;
// }







// Tabulation

int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int neg = 0;
        for(int i = 1; i < nums.size(); i++) {
            int pick = nums[i];
            if(i - 2 >= 0)
                pick += dp[i - 2];
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[nums.size() - 1];
    }