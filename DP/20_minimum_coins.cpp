#include<bits/stdc++.h>
using namespace std;

// Greedy Fails 
// arr = [9, 5, 6, 1] and target = 11


// Recursive Solution 

int minEls(int i, int target, vector<int>& nums) {
    if(target == 0)
        return 0;
    if(i == 0) {
        // In this case, we need to complete the target thats why we are using the below if condition
        if(target % nums[0] == 0)
            return target / nums[0];
        return 1e9;
    }
    
    int notTake = minEls(i - 1, target, nums);
    int take = INT_MAX;
    
//     if(nums[i] <= target) take = minEls(i - 1, target % nums[i], nums) + (target / nums[i]);
    if(nums[i] <= target) take = minEls(i, target - nums[i], nums) + 1;
    
    
    return min(take, notTake);
}

int minimumElements(vector<int> &nums, int target) {
    
    int ans = minEls(nums.size() - 1, target, nums);
    if(ans >= 1e9) return -1;
    return ans;
}