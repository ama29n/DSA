#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/

class Solution {
private:
    #define A      '{' 
    #define a      '}'
    #define B      '('
    #define b      ')'
    #define C      '['
    #define c      ']'
public:
    bool isValid(string &s) {
        int i = -1;
        for(auto &ch : s) {
            if(ch == A || ch == B || ch == C) {
                s[++i] = ch;
            }
            else
            if(i >= 0 && ((ch == a && s[i] == A) || (ch == b && s[i] == B) || (ch == c && s[i] == C))) {
                i--;
            }
            else return false;
        }
        return i == -1;
    }
};