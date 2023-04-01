#include <bits/stdc++.h>
using namespace std;

// You are given employe id and salaries of 'n' different employees.
// Ids vary in the range [1, n].
// You are also given 'm' queries where each query is denoted by parameters 1, r, x.
// Each employee with a salary strictly greater than x needs to pay tax. 
// You are asked to filter out the rows in the range l to r where employees will pay the tax. 

// To store number of employees
int maxN;

// Segment tree contains an array at each node to store sals in node's range
vector<vector<int>> seg;

// Function to merge arrays at each node of segment tree
vector<int> merge(vector<int> &v1, vector<int> &v2) {
    vector<int> v3;
    int n = v1.size(), m = v2.size();
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(v1[i] < v2[j]) {
            v3.push_back(v1[i++]);
        } else {
            v3.push_back(v2[j++]);
        }
    }
    while(i < n) {
        v3.push_back(v1[i++]);
    }
    while(j < m) {
        v3.push_back(v2[j++]);
    }
    return v3;
}

// Function to build segment tree
void build(int i, int low, int high, vector<int> &sals) {
    if(low == high) {
        seg[i].push_back(sals[low]);
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * i + 1, low, mid, sals);
    build(2 * i + 2, mid + 1, high, sals);
    seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
}

// Function to perform query on segment tree
// Calculate the number of nodes in range [l, r] having sals > t 
int query(int i, int low, int high, int l, int r, int t) {
    if(low > r || high < l) {
        return 0;
    }
    if(low >= l && high <= r) {
        auto &v = seg[i];
        int x = v.size() - (upper_bound(v.begin(), v.end(), t) - v.begin());
        return x;
    }
    int mid = low + (high - low) / 2;
    int ll = query(2 * i + 1, low, mid, l, r, t);
    int rr = query(2 * i + 2, mid + 1, high, l, r, t);
    return ll + rr;
}

// Driver Function
void solution(vector<int> &sals, vector<vector<int>> &queries) {
    seg.resize(maxN * 4 + 10);
    build(0, 0, maxN - 1, sals);
    for(auto it : queries) {
        int x = query(0, 0, maxN - 1, it[0] - 1, it[1] - 1, it[2]);
        cout << x << " ";
    }
}

// Main Function 
int main() {
    int n; cin >> n; maxN = n;
    vector<vector<int>> data(n, vector<int> (2));
    for(int i = 0; i < n; i++) {
        cin >> data[i][0] >> data[i][1];
    }
    int m; cin >> m;
    vector<vector<int>> queries(m);
    for(int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        queries[i] = {l, r, x};
    }
    sort(data.begin(), data.end());
    vector<int> sals;
    for(auto it : data) {
        sals.push_back(it[1]);
    }
    solution(sals, queries);
}

// Time -> (n log(n)) + (m log(n) log(n)) -> Build time + Query Time (Query Search * lower_bound())

// Input 

// 5
// 1 1 
// 2 2 
// 3 2 
// 4 3 
// 5 5 
// 2
// 1 5 2 
// 2 4 1 

// Output 

// 2 3
