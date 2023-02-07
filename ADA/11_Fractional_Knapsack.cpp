#include <bits/stdc++.h>
using namespace std;

void knapsack(int weight[], int profit[], int n, int W) {
    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++) {
        v[i] = {profit[i] / weight[i], weight[i]};
    }
    // reverse sort 
    sort(v.rbegin(), v.rend());
    int total_profit = 0, i = 0;
    while(W > 0) {
        int w = v[i][1], p = v[i][1] * v[i][0];
        if(W >= w) {
            W -= w;
            total_profit += p;
            i++;
        } else {
            total_profit += (W * v[i][0]);
            W = 0;
        }
    }
    cout << total_profit;
}

int main () {
  int n = 3;
  int W = 50;
  int weight[n] = {10, 20, 30};
  int profit[n] = {60, 100, 120};
  knapsack(weight, profit, n, W);
}

