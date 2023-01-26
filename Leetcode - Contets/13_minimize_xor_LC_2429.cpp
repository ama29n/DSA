#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimize-xor/

// Given 2 numbers num1 and num2, find integer x such that 
// 1. x has same number of bits as num2 
// 2. x xor num1 is minimal

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int set1 = __builtin_popcount(num1);
        int set2 = __builtin_popcount(num2);
        // If both the number have same number of bits, i.e., x has same bits as num1, then num1 ^ num1 = 0
        if(set1 == set2) 
            return num1;
        // If num1 has more bits, remove the extra bits from back for x as the rest bits would be at same position
        // with num1 resulting into 0 for any particular set bit
        if(set1 > set2) {
            int set = set2;
            for(int i = 31; i >= 0; i--) {
                int mask = 1 << i;
                if((num1 & mask) && set)
                    set--;
                else if((num1 & mask) && !set)
                    mask = ~mask, num1 &= mask;
            }
        // Else, set the unset bits from starting as we have to minimize the xor
        } else {
            int unset = set2 - set1;
            for(int i = 0; i < 32 && unset > 0; i++) {
                int mask = 1 << i;
                if(!(num1 & mask)) {
                    num1 |= mask;
                    unset--;
                }
            }
        }
        return num1;
    }
};