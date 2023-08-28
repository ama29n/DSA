#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/palindromic-substrings/ 

// Recursive 
int helper(int i, int j, string s) {
    if(i >= j)
        return 1;
    return s[i] == s[j] ? helper(i + 1, j - 1, s) : 0;
}
int countSubstrings(string s) {
    int n = s.size(), ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(helper(i, j, s))
                ans++;
        }
    }
    return ans;
}
// Time - O(n * n * n)
// Space - 

// Memoization
int helper(int i, int j, string s, vector<vector<int>>& dp) {
    if(i >= j) 
        return 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = s[i] == s[j] ? helper(i + 1, j - 1, s, dp) : 0;
}
int countSubstrings(string s) {
    int n = s.size(), ans = 0;
    vector<vector<int>> dp(n, vector<int> (n, -1));
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(helper(i, j, s, dp))
                ans++;
        }
    }
    return ans;
}

// Another Approach 
void countPalindrome(string s, int left, int right, int& ans) {
    while(left >= 0 && right < s.size() && s[left] == s[right]) {
        ans++;
        left--;
        right++;
    }
}
int countSubstrings(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        countPalindrome(s, i, i, ans);
        countPalindrome(s, i, i + 1, ans);
    }
    return ans;
}
