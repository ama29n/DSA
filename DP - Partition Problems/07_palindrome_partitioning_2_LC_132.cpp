#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/palindrome-partitioning-ii/

// Recursive Solution
// Time Complexity -> Exponential

// MCM Pattern
// Time Complexity -> O(n ^ 3)
// Space Complexity -> O(n ^ 2) ignoring recursion stack
class Solution {
public:
    int dp[2002][2002];
    bool isPalindrome(int i, int j, string &s) {
        while(i <= j) {
            if(s[i] != s[j]) { return false; }
            i++; j--;
        }
        return true;
    }
    int dfs(int i, int j, string &s) {
        if(i >= j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(isPalindrome(i, j, s)) {
            return 0;
        }
        int min_cuts = 2000;
        for(int k = i; k < j; k++) {
            int cuts = 1 + dfs(i, k, s) + dfs(k + 1, j, s);
            min_cuts = min(min_cuts, cuts);
        }
        return dp[i][j] = min_cuts;
    }
    int minCut(string &s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        int x = dfs(0, s.size() - 1, s);
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(dp[i][j] < 0) {
        //             cout << dp[i][j] << " ";
        //         } else {
        //             cout << "+" + to_string(dp[i][j]) << " ";
        //         }
        //     }
        //     cout << endl;
        // }
        return x;
    }
};
// Input -> leetcode 
//     l  e  e  t  c  o  d  e
// l  -1 +1 +1 +2 +3 +4 +5 +6 
// e  +0 -1 -1 +1 +2 +3 +4 +5 
// e  +0 +0 -1 +1 +2 +3 +4 +5 
// t  +0 +0 +0 -1 +1 +2 +3 +4 
// c  +0 +0 +0 +0 -1 +1 +2 +3 
// o  +0 +0 +0 +0 +0 -1 +1 +2 
// d  +0 +0 +0 +0 +0 +0 -1 +1 
// e  +0 +0 +0 +0 +0 +0 +0 -1 

// Tabulation
// Time Complexity -> O(n ^ 3)
class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    int minCut(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++, j++) {
                if(i == j) {
                    continue;
                }
                if(isPalindrome(i, j, s)) continue;
                int cuts = n;
                for(int k = i; k < j; k++) {
                    cuts = min(cuts, 1 + dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] = cuts;
            }
        }
        return dp[0][n - 1];
    }
};

// MCM Optimised
// If the left substring is palindrome then only check for right substring
// Since the solution is being recurred for right side only, this means the susbstring s[i, k] is already partitioned at each step
class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(int l, int r, string& s) {
        int i = l, j = r;
        while(i <= j) {
            if(s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
    int dfs(int i, int j, string& s) {
        if(i >= j) { return  0; }
        if(isPalindrome(i, j, s)) { return 0; }
        if(dp[i][j] != -1) { return dp[i][j]; }
        int min_cuts = INT_MAX;
        for(int k = i; k < j; k++) {
            if(isPalindrome(i, k, s)) {
                int cuts = 1 + dfs(k + 1, j, s);
                min_cuts = min(min_cuts, cuts);
            }
        }
        return dp[i][j] = min_cuts;
    }
    int minCut(string& s) {
        int n = s.size();
        dp.resize(n, vector<int> (n, -1));
        return dfs(0, n - 1, s);
    }
};

// O(n ^ 2) - Giving TLE
class Solution {
public:
    int minCut(string &s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool> (n, true));
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++, j++) {
                if(i == j) continue;
                if(g == 1) isPalindrome[i][j] = s[i] == s[j];
                if(!isPalindrome[i + 1][j - 1]) {
                    isPalindrome[i][j] = false;
                    continue;
                }
                if(s[i] != s[j]) isPalindrome[i][j] = false;
            }
        }
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++, j++) {
                if(i == j) {
                    continue;
                }
                if(isPalindrome[i][j]) continue;
                int cuts = n;
                for(int k = i; k < j; k++) {
                    if(isPalindrome[i][k]) {
                        cuts = min(cuts, 1 + dp[k + 1][j]);
                    }
                }
                dp[i][j] = cuts;
            }
        }
        return dp[0][n - 1];
    }
};

// O(n ^ 2) solution
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        int isPalin[n][n];
        fill_n(&isPalin[0][0], n * n, false);
        int cuts[n + 1];
        for(int i = 0; i <= n; i++) {
            cuts[i] = i - 1;
        }
        for(int j = 0; j < n; j++) {
            for(int i = j; i >= 0; i--) {
                if(s[i] == s[j] && ((j - i) < 2 || isPalin[i + 1][j - 1])) {
                    isPalin[i][j] = true;
                    cuts[j + 1] = min(cuts[j + 1], 1 + cuts[i]);
                }
            }
        }
        return cuts[n];
    }
};

// TC 
// Input -> fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi
// Output -> 75