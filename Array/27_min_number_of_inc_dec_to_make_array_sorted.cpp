#include <bits/stdc++.h>
using namespace std;

#define MOD 1E9 + 7
#define ll long long int

int solve(int i, int prev, vector<int>& v) {
    if(i == v.size())
        return 0;
    if(prev == -1 || v[i] >= prev)
        return solve(i + 1, v[i], v);
    int dif = abs(v[i] - prev);
    return dif + solve(i + 1, v[i] + dif, v);
}

int main() {
    int n = 5;
    vector<int> v(n);

    // 1 2 1 4 3
    for(int i = 0; i < n; i++)
        cin >> v[i];

    // 2
    cout << solve(0, -1, v);
}

// Complexity is exponential