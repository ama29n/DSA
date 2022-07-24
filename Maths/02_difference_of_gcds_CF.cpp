#include <bits/stdc++.h>
using namespace std;

// You are given three integers n, l, and r. You need to construct an array a1,a2,…,an (l≤ai≤r) 
// such that gcd(i,ai) are all distinct or report there's no solution.

// Here gcd(x,y) denotes the greatest common divisor (GCD) of integers x and y.

vector<int> solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> ans;
    ans.push_back(l);

    for(int i = 2; i <= n; i++) {
        if(l % i == 0) {
            ans.push_back(l);
        } else {
            int j = l / i;
            j = (j + 1) * i;
            if(j <= r) {
                ans.push_back(j);
            } else {
                cout << "NO" << endl;
                return {};
            }
        }
    }
    cout << "YES" << endl;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        vector<int> a = solve();
        if(a.size()) {
            for(auto it : a)
                cout << it << " ";
            cout << endl;
        }
    }
}