#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/majority-element/

// Boyer Moore Voting algorithm  

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int fre = 0, ele;
        for(auto it : nums) {
            if(fre == 0) {
                ele = it;
            }
            it == ele ? fre++ : fre--;
        }
        return ele;
    }
};