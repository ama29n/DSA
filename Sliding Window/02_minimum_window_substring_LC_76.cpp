#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if (s == t) {
            return s;
        }
        if (m < n) {
            return "";
        }
        vector<int> map(256, 0);
        for (char it : t) {
            map[it]++;
        }
        int i = 0, j = 0, len = 100001, counter = 0;
        string ans = "";
        while (j < m) {
            if (map[s[j++]]-- > 0) {
                counter++;
            }
            while (counter == n) {
                if (j - i < len) {
                    len = j - i;
                    ans = s.substr(i, j - i);
                }
                if (map[s[i++]]++ > -1) {
                    counter--;
                }
            }
        }
        return ans;
    }
};