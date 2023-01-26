#include <bits/stdc++.h>
using namespace std;

const int mod = 1E9 + 7; const string yes = "Yes", no = "No"; typedef long long ll;

#define pb            push_back
#define mem(a, i)     memset(a, i, sizeof(a))
#define ff            first
#define ss            second
#define all(v)        v.begin(), v.end()
#define rall(v)       v.rbegin(), v.rend()
#define forn(i, n)    for(int i = 0; i < n; i++)

// https://www.codechef.com/BPITL3PP04/problems/FROGV

// Make dsu of indiices

/*.....................................................................*/

class DSU {
    public:
    int n;
    vector<int> parent, rank;

    DSU(int size) : n(size) {
        rank = vector<int> (n, 0);
        parent = vector<int> (n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int n) {
        if(parent[n] == n)
            return n;
        return parent[n] = findParent(parent[n]);
    }
    
    void makeParent(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if(rank[a] > rank[b]) {
            parent[b] = a; return;
        }
        if(rank[b] > rank[a]) {
            parent[a] = b; return;
        }
        parent[b] = a;
        rank[a]++;
    }
};

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> v(n);
    vector<pair<int, int>> arr(n);
    forn(i, n) {
        cin >> v[i];
        arr[i] = {v[i], i + 1};
    }
    sort(all(arr));
    DSU dsu(n + 1);
    for(int i = 0; i < n - 1; i++) {
        if(arr[i + 1].ff - arr[i].ff <= k)
            dsu.makeParent(arr[i + 1].ss, arr[i].ss);
    }
    while(p--) {
        int a, b;
        cin >> a >> b;
        if(dsu.findParent(a) == dsu.findParent(b)) {
            cout << yes << endl;
        } else {
            cout << no << endl;
        }
    }
}
/*.....................................................................*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while(t--) {
        solve();
    }
}
