#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int n = nums.size();
        int count1 = 0, count2 = 0, candidate1 = INT_MIN, candidate2 = INT_MIN;
        for(auto it : nums) {
            if(it == candidate1) {
                count1++;
            } else if(it == candidate2) {
                count2++;
            } else if(count1 == 0) {
                candidate1 = it; count1++;
            } else if(count2 == 0) {
                candidate2 = it; count2++;
            } else {
                count1--; count2--;
            }
        }
        count1 = count2 = 0;
        for(auto it : nums) {
                if(it == candidate1) {
                count1++;
            } 
            else if(it == candidate2) {
                count2++;
            }
        }
        vector<int> ans;
        int mins = n / 3 + 1;
        if(count1 >= mins) {
            ans.push_back(candidate1);
        }
        if(count2 >= mins) {
            ans.push_back(candidate2);
        }
        return ans;
    }
};