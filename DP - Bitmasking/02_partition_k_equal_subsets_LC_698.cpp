#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/ 

// Itna sexy algo hai ke maza hi agya BC
// Sare Permutations 1 1 krke jayenge
// But the point that was confusing me was ki, order kese preserve rhega ki konsa next uthana hai mask as for loop hai
// Then I realised ki bc hr mask me the algo is initialising a new mask jo usse bda hoga (as new bit set kr rhe hai)
// and ese krte krte end tk ajayenge
// and one more important chiz
// after 1 susbset of sum k is found tab ham start krte hai 0 se toh end me ajana chahiye somehow 0

class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int n = nums.size();
        int sum = 0; for(auto it : nums) sum += it;
        if(sum % k) return false;
        sum /= k;
        vector<int> dp((1 << n) + 2, -1);
        dp[0] = 0;
        for(int mask = 0; mask < (1 << n); mask++) {
            if(dp[mask] == -1) continue;
            for(int i = 0; i < n; i++) {
                if(!(mask & (1 << i)) && dp[mask] + nums[i] <= sum) {
                    dp[mask | (1 << i)] = (dp[mask] + nums[i]) % sum;
                }
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};