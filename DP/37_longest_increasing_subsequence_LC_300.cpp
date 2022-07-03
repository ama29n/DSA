#include<bits/stdc++.h>
using namespace std;


// Recursion

int find(int i, int prevIdx, vector<int>& nums, int n) {
    if(i == n)
        return 0;
    int notTake = find(i + 1, prevIdx, nums, n);
    int take = 0;
    if(prevIdx == -1 || nums[i] > nums[prevIdx])
        take = 1 + find(i + 1, i, nums, n);
    return max(take, notTake);
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    return find(0, -1, nums, n);
}


// Memoization

int find(int i, int prevIdx, vector<int>& nums, int n, vector<vector<int>>& dp) {
    if(i == n)
        return 0;
    if(dp[i][prevIdx + 1] != -1)
        return dp[i][prevIdx + 1];
    int notTake = find(i + 1, prevIdx, nums, n, dp);
    int take = 0;
    if(prevIdx == -1 || nums[i] > nums[prevIdx])
        take = 1 + find(i + 1, i, nums, n, dp);
    return dp[i][prevIdx + 1] = max(take, notTake);
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (n, -1));
    return find(0, -1, nums, n, dp);
}


// Tabulation 

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    for(int i = n - 1; i >= 0; i--) {
        for(int prevIdx = i - 1; prevIdx >= -1; prevIdx--) {
            int notTake = dp[i + 1][prevIdx + 1];
            int take = 0;
            if(prevIdx == -1 || nums[i] > nums[prevIdx])
                take = 1 + dp[i + 1][i + 1];
            dp[i][prevIdx + 1] = max(take, notTake);
        }
    }
    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0; j <= n; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    return dp[0][-1 + 1];
}


// nlogn solution

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp;
    temp.push_back(nums[0]);
    for(int i = 1; i < n; i++) {
        if(nums[i] > temp.back()) {
            temp.push_back(nums[i]);
        } else {
            vector<int>::iterator idx = lower_bound(temp.begin(), temp.end(), nums[i]);
            temp[idx - temp.begin()] = nums[i];
        }
    }
    return temp.size();
}

// Best solution

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    // Here dp[i] will store the max length of increasing subsequence till ith pos 
    for(int i = 1; i < n; i++) {
        int maxi = 1;
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j])
                maxi = max(maxi, dp[i] + dp[j]);
        }
        dp[i] = maxi;
    }
    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]), cout << dp[i] << " ";
    return ans;
}

// for displaying the longest sequence

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), prev(n, -1), v;
    // Here dp[i] will store the max length of increasing subsequence till ith pos 
    for(int i = 1; i < n; i++) {
        int maxi = 1;
        for(int j = 0; j < i; j++) {
            if(nums[i] > nums[j])
                if(dp[i] + dp[j] > maxi)
                maxi = dp[i] + dp[j], prev[i] = j;
        }
        dp[i] = maxi;
    }
    int ans = INT_MIN, idx;
    for(int i = 0; i < n; i++)
        if(dp[i] > ans)
            ans = dp[i], idx = i;
    while(idx != -1)
        v.push_back(nums[idx]), idx = prev[idx];
    for(auto it : v)
        cout << it << " ";
    return ans;
}



