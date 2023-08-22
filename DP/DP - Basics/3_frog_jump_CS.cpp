#include<bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012 

// Memoization 
class Solution {
public:
    int cal(int idx, vector<int> &height, vector<int> &dp) {
        if(idx == 0) {
            return 0;
        }
        if(idx == 1) {
            return abs(height[1] - height[0]);
        }
        if(dp[idx] != -1) {
            return dp[idx];
        }
        dp[idx - 1] = cal(idx - 1, height, dp);
        dp[idx - 2] = cal(idx - 2, height, dp);
        return min(dp[idx - 1] + abs(height[idx] - height[idx - 1]), dp[idx - 2] + abs(height[idx] - height[idx - 2]));
    }
    int frogJump(int n, vector<int> &heights) {
        vector<int> dp(n, -1);
        return cal(n - 1, heights, dp);
    }
};

// Tabulation
class Solution {
public:
    int frogJump(int n, vector<int> &height) {
        vector<int> dp(n, -1);
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);
        
        for(int i = 2; i < n; i++) {
            int one = dp[i - 1] + abs(height[i] - height[i - 1]);
            int two = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(one, two);
        }
        return dp[n - 1];
    }
};

// Super optimised
class Solution {
public:
    int frogJump(int n, vector<int> &height) {
        int twoPrev = 0, onePrev = abs(height[1] - height[0]), cur;
        for(int i = 2; i < n; i++) {
            int one = onePrev + abs(height[i] - height[i - 1]);
            int two = twoPrev + abs(height[i] - height[i - 2]);
            cur = min(one, two);
            twoPrev = onePrev;
            onePrev = cur;
        }
        return cur;
    }
};
