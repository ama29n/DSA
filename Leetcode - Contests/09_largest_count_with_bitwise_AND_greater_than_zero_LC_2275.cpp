#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

// You are given an array of positive integers candidates. 
// Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used 
// once in each combination.

// Return the size of the largest combination of candidates with a bitwise AND greater than 0.

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int x = 1 << i;
            int count = 0;
            for(auto it : candidates) {
                if(it & x) {
                    count++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};

// If and has to be greater than zero, one bit at common position in all numbers should be 1 
// Thus, we count number of elements for every bit


