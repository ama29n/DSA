#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/

// Given a string consisting of 'a', 'b' & 'c'
// In one minute we can take either the character from end or start
// Given a integer k
// We need to find minimum minutes to get all alphabets k times 

// Sliding window solution
// Find the maximum length of window that has the elements which are not the part of final ans

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> map(3, 0);
        for(auto it : s) 
            map[it - 'a']++;
        // If number of a or b or c is less than k
        if(map[0] < k || map[1] < k || map[2] < k)
            return -1;
        // Remaining a, b and c 
        int x = map[0] - k, y = map[1] - k, z = map[2] - k;
        map[0] = map[1] = map[2] = 0;
        int i = 0, j = 0, maxLen = 0;
        while(j < n) {
            map[s[j++] -'a']++;
            while(map[0] > x || map[1] > y || map[2] > z) {
                map[s[i++] - 'a']--;
            }
            maxLen = max(maxLen, j - i);
        }
        return n - maxLen;
    }
};