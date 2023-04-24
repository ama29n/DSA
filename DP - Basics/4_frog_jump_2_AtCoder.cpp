#include<bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/dp/tasks/dp_b 

// Memoisation
class Solution {
public:
    int frogJump(int idx, int k, vector<int> &height, vector<int> &dp) {
        if(idx == 0) {
            return 0;
        }
        if(dp[idx] != -1) {
            return dp[idx];
        }
        int ans = INT_MAX;
        for(int i = 1; i <= k && idx - i >= 0; i++) {
            dp[idx - i] = frogJump(idx - i, k, height, dp);
            ans = min(ans, (dp[idx - i] + abs(height[idx] - height[idx - i])));
        }
        return ans;
    }
    int main() {
        int n = 5, k = 3;
        vector<int> height{10, 30, 40, 50, 20}, dp(n, -1);
        int ans = frogJump(n - 1, k, height, dp);
        cout << ans;
    }
};