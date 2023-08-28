#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string &s, string &t) {
        if(s == t) return s;        // If strings are same
        int m = s.size();
        int n = t.size();      
        if(m < n) return "";        // If t.size > s.size
        // map
        unordered_map<int, int> map;
        for(auto it : t) map[it]++;
        // variables
        int i = 0, j = 0, min_len = 1E5, counter = 0;
        string res = "";
        while(j < m) {
            if(map[s[j++]]-- > 0) counter++;
            while(counter == n) {
                int cur_len = j - i;
                if(cur_len < min_len) {
                    min_len = cur_len;
                    res = s.substr(i, cur_len);
                }
                if(map[s[i++]]++ > -1) counter--;
            }
        }
        return res;
    }
};