#include<bits/stdc++.h>
using namespace std;


// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

int transaction(vector<int>& arr) {
    int n = arr.size();
    int max_profit = 0, cost_price = arr[0];
    for(int i = 1; i < n; i++) {
        int profit = arr[i] - cost_price;
        max_profit = max(max_profit, profit);
        cost_price = min(cost_price, arr[i]);
    }
    return max_profit;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << transaction(arr) << endl;
}


// Time = O(n), Space = O(1)