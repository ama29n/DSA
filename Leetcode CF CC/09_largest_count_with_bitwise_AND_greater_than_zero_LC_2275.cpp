#include <bits/stdc++.h>
using namespace std;

// You are given an array of positive integers candidates. 
// Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used 
// once in each combination.

// Return the size of the largest combination of candidates with a bitwise AND greater than 0.

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int max_ele = *max_element(candidates.begin(), candidates.end());
        int ans = 0;
        for(int b = 1; b <= max_ele; b <<= 1) {
            int count = 0;
            for(auto &it : candidates)
                if((b & it) > 0)
                    count++;
            ans = max(ans, count);
        }
        return ans;
    }
};

// If and has to be greater than zero, one bit at common position in all numbers should be 1 
// Thus, we count number of elements for every bit


