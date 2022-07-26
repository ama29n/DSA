#include <bits/stdc++.h>
using namespace std;

// Think of a case when arr = {11, 30, 19} and k = 5 (i.e., minimum element in arr > k). 
// Here, after doing the above steps, we will get the array as {10, 30, 20} but are we successful? 
// No, GCD has changed to 10 instead of 5.

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int k;
    cin >> k;

    sort(v.begin(), v.end());

    int ans = 0;
    ans += abs(v[0] - k);

    for(int i = 1; i < n; i++) {
        if(v[i] % k != 0) {
            int q = (v[i] / k);
            int a = q * k;
            int b = (q + 1) * k;
            ans += min(v[i] - a, b - v[i]);
        }
    }
    cout << ans;
}

// Output
// 5
// 9 5 18 21 7
// 7

// Input
// 7 

// Array after sorting 
// 5 7 9 18 21
// Array after conversion
// 7 7 7 21 21 
