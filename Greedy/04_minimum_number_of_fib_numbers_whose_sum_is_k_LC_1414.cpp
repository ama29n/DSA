#include <bits/stdc++.h>
using namespace std;

int findMinFibonacciNumbers(int k) {
    vector<int> fib;
    int prev1 = 1, prev2 = 1, prev3;
    fib.push_back(prev1);
    while(true) {
        prev3 = prev1 + prev2;
        if(prev3 > k)
            break;
        fib.push_back(prev3);
        prev1 = prev2;
        prev2 = prev3;
    }
    int i = fib.size() - 1, ans = 0;
    while(k) {
        while(k >= fib[i]) {
            k -= fib[i];
            ans++;
        }
        i--;
    }
    return ans;
}