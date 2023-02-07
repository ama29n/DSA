#include <bits/stdc++.h>
using namespace std;

void printOptimal(vector<vector<int>>& parent, int i, int j) {
    if(i == j) {
        cout << " A" << i << " ";
    } else {
        cout << "(";
        printOptimal(parent, i, parent[i][j]);
        printOptimal(parent, parent[i][j] + 1, j);
        cout << ")";
    }
}

void matrixMultiplication(int n, int arr[]) {
    int dp[n][n];
    vector<vector<int>> parent(n, vector<int> (n, 0));
    memset(dp, 0, sizeof(dp));
    for(int i = n - 1; i >= 1; i--) {
        for(int j = i + 1; j < n; j++) {
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++) {
                int steps = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if(steps < dp[i][j]) {
                    dp[i][j] = steps;
                    parent[i][j] = k;
                }
            }
        }
    }
    printOptimal(parent, 1, 4);
}

int main () {
  int arr[5] = {40, 20, 30, 10, 30};
  int n = 5;
  matrixMultiplication(n, arr);
}

