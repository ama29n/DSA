#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-increasing-subsequence/ 

// These methods don't work if subsequence can have duplicate elements

// Memoization
class Solution {
public:
    int n;
    int dfs(int i, int prev, vector<int> &nums, vector<vector<int>> &dp) {
        if(i == n) {
            return 0;
        }
        if(dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }
        int not_take = dfs(i + 1, prev, nums, dp);
        int take = 0;
        if(prev == -1 || nums[prev] < nums[i]) {
            take = 1 + dfs(i + 1, i, nums, dp);
        }
        return dp[i][prev + 1] = max(take, not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return dfs(0, -1, nums, dp);
    }
};

// Tabulation 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        int ns = 0;
        for(auto it : dp) {
            ns = max(ns, it);
        }
        return ns;
    }
};

// nlogn solution
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            } else {
                auto idx = lower_bound(temp.begin(), temp.end(), nums[i]);
                temp[idx - temp.begin()] = nums[i];
            }
        }
        return temp.size();
    }
};

// Segment Tree 
class Solution {
private:
    int n;
    int maxN = 2E4;
    vector<int> seg;
    const int offset = 1E4;
    int query(int i, int low, int high, int l, int r) {
        if(low > r || high < l) {
            return 0;
        }
        if(low >= l && high <= r) {
            return seg[i];
        }
        int mid = low + (high - low) / 2;
        int ll = query(2 * i + 1, low, mid, l, r);
        int rr = query(2 * i + 2, mid + 1, high, l, r);
        return max(ll, rr);
    }
    void update(int i, int low, int high, int node, int val) {
        if(low == high) {
            seg[i] = max(seg[i], val);
            return;
        }
        int mid = low + (high - low) / 2;
        if(node <= mid) {
            update(2 * i + 1, low, mid, node, val);
        } else {
            update(2 * i + 2, mid + 1, high, node, val);
        }
        seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        for(auto &it : nums) {
            it += offset;
        }
        seg.resize(maxN * 4 + 10, 0);
        for(auto it : nums) {
            int x = query(0, 0, maxN, 0, it - 1);
            update(0, 0, maxN, it, x + 1);
        }
        return query(0, 0, maxN, 0, maxN);
    }
};

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