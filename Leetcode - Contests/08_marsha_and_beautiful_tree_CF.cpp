#include <bits/stdc++.h>
using namespace std;

const int MOD = 1E9 + 7; const string yes = "YES", no = "NO";

#define all(v)      v.begin(), v.end()

// https://codeforces.com/problemset/problem/1741/D

int ans;

void merge(vector<int>& arr, int l, int mid, int r) {
    if(arr[l] <= arr[mid + 1])
        return;
    ans++;
    for(int i = l, j = mid + 1; i <= mid; i++, j++) 
        swap(arr[i], arr[j]);
}

void mergeSort(vector<int>& arr, int l, int r) {
    if(l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

void solve() {
    int n; 
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ans = 0;
    mergeSort(v, 0, n - 1);
    for(int i = 1; i < n; i++) {
        if(v[i] < v[i - 1]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
