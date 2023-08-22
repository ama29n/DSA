#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/tallest-billboard/ 

class Solution {
private:
    int n;

    int dp[21][5001][5001];                            // 5 * 1E8 -> TLE

    int dfs(int i, int s1, int s2, vector<int> &nums) {
        if(i == n) {
            return s1 == s2 ? s1 : 0;
        }
        if(dp[i][s1][s2] != -1) {
            return dp[i][s1][s2];
        }
        int a = dfs(i + 1, s1, s2, nums);               // Don't take this rod
        int b = dfs(i + 1, s1 + nums[i], s2, nums);     // Take this rod for stand 1
        int c = dfs(i + 1, s1, s2 + nums[i], nums);     // Take this rod for stand 2
        return dp[i][s1][s2] = max({ a, b, c });
    }
public:
    int tallestBillboard(vector<int> &rods) {
        n = rods.size();
        memset(dp, -1, sizeof dp);
        return dfs(0, 0, 0, rods);
    }
};

// Efficient Approach
class Solution {
private:
    // (s1 = s2) -> (s1 - s2 = 0)
    // (diff = s1 - s2) -> (diff = 0)
    // (-5000 <= diff <= 5000)
    int shift = 5000;
    int dp[21][10000 + 10];

    int n;
    int dfs(int i, int diff, vector<int> &nums) {
        if(i == n) {
            return diff == 0 ? 0 : -1E4;
        }
        if(dp[i][diff + shift] != -1) {
            return dp[i][diff + shift];
        }

        int a = dfs(i + 1, diff, nums);                        // Don't take this rod
        int b = dfs(i + 1, diff + nums[i], nums) + nums[i];    // Take this rod for stand 1
        int c = dfs(i + 1, diff - nums[i], nums);              // Take this rod for stand 2

        return dp[i][diff + shift] = max({ a, b, c });
    }
public:
    int tallestBillboard(vector<int> &rods) {
        n = rods.size();
        memset(dp, -1, sizeof dp);
        int ans = dfs(0, 0, rods);
        return ans < 0 ? 0 : ans;
    }
};

// adding nums[i] to "b" means adding height to billboard height

// the "c" case is meant to explore the scenario where the current rod is 
// used to reduce the height difference between the two supports, without 
// actually adding to the height of the billboard itself.