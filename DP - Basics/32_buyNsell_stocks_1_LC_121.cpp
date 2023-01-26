#include<bits/stdc++.h>
using namespace std;


// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

int maxProfit(vector<int>& prices) {
    int maxProfit = 0, minBuyPrice = prices[0];
    
    for(int i = 1; i < prices.size(); i++) {
        int profit = prices[i] - minBuyPrice;
        maxProfit = max(profit, maxProfit);
        minBuyPrice = min(prices[i], minBuyPrice);
    }
    return maxProfit;
}


// Time = O(n), Space = O(n)