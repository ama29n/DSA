#include <bits/stdc++.h>
using namespace std;

// Q -> Find minimum number of cuts such that each substring formed is a palindrome

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
    bool isPalindrome(int l, int r, string& s) {
        int i = l, j = r;
        while(i <= j) {
            if(s[i++] != s[j--]) { return false; }
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        int dp[n][n];
        fill_n(&dp[0][0], n * n, 0);
        for(int j = 0; j < n; j++) {
            for(int i = j; i >= 0; i--) {
                if(isPalindrome(i, j, s)) {
                    continue;
                } 
                int min_cuts = INT_MAX;
                for(int k = i; k < j; k++) {
                    min_cuts = min(min_cuts, 1 + dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] = min_cuts;
            }
        }
        return dp[0][n - 1];
    }
};

// OR

class Solution {
public:
    bool isPalindrome(int l, int r, string& s) {
        int i = l, j = r;
        while(i <= j) {
            if(s[i++] != s[j--]) { return false; }
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        int dp[n][n];
        fill_n(&dp[0][0], n * n, 0);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(isPalindrome(i, j, s)) {
                    continue;
                } 
                int min_cuts = INT_MAX;
                for(int k = i; k < j; k++) {
                    min_cuts = min(min_cuts, 1 + dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] = min_cuts;
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