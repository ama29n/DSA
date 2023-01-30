#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_len = 0;
        string max_str = ""; max_str += s[0];
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int l = i, r = j;
                bool isPalindrome = true;
                while(l <= r) {
                    if(s[l++] != s[r--]) {
                        isPalindrome = false;
                        break;
                    }
                }
                if(isPalindrome && j - i >= max_len) {
                    max_len = j - i;
                    max_str = s.substr(i, j - i + 1);
                }
            }
        }
        return max_str;
    }
};

// Time Complexity - O(n ^ 3)