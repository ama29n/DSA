#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

class Solution {
public:
    char smallest(vector<int>& map) {
        for(int i = 0; i < 26; i++)
            if(map[i] != 0)
                return (i + 'a');
        return 'a';
    }
    string robotWithString(string s) {
        stack<int> t;
        string ans;
        vector<int> map(26, 0);
        for(auto ch : s)
            map[ch - 'a']++;
        for(auto ch : s) {
            t.push(ch);
            map[ch - 'a']--;
            // If there doesn't exists smaller element than ch than it is the smaller
            while(!t.empty() && t.top() <= smallest(map)) {
                ans += t.top();
                t.pop();
            }
        }
        while(!t.empty()) {
            ans += t.top();
            t.pop();
        }
        return ans;
    }
};