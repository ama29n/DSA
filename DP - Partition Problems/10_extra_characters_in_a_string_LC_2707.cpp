#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/extra-characters-in-a-string/description/ 

class Solution {
public:
    int minExtraChar(string s, vector<string> &dict) {
        unordered_set<string> set(dict.begin(), dict.end());
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++, j++) {
                if(i == j) { 
                    string z = s.substr(i, 1); 
                    dp[i][j] = set.find(z) == set.end() ? 1 : 0; 
                    continue; 
                }
                string k = s.substr(i, j - i + 1);
                if(set.find(k) != set.end()) {
                    continue;
                }
                int ans = n;
                for(int k = i; k < j; k++) {
                    ans = min(ans, dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n - 1];
    }
};