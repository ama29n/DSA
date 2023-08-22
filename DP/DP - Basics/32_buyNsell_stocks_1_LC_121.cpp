#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int min_cp = prices[0];
        for(int i = 1; i < n; i++) {
            int profit = prices[i] - min_cp;
            max_profit = max(profit, max_profit);
            min_cp = min(min_cp, prices[i]);
        }
        return max_profit;
    }
};

// Time = O(n), Space = O(n)
