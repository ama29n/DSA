#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-additions-to-make-valid-string/

// Circular array approach
class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int ans = 0, cur = 'a';
        for(int i = 0; i < n; i) {
            word[i] == cur ? i++ : ans++;
            cur = 'a' + (cur - 'a' + 1) % 3;
        }
        ans += cur == 'a' ? 0 : cur == 'b' ? 2 : 1; 
        return ans;
    }
};