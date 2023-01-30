#include <bits/stdc++.h>
using namespace std;

const int MOD = 1E9 + 7;

const string yes = "YES";
const string no = "NO";

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define pb          push_back
#define mem(a, i)   memset(a, i, sizeof(a))
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

vector<int> Factors(int n) { vector<int> ans; for (int i = 1; i * i <= n; i++) { if(n % i == 0) { ans.push_back(i); if((n / i) != i) ans.push_back(n / i); } } return ans; }

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

    int t;
    cin >> t;

    // vector<bool> isPrime(size, true);
    // vector<int> hp(size, 0), lp(size, 0);
    // isPrime[0] = isPrime[1] = false;
    // for(int i = 2; i < size; i++) {
    //     if(isPrime[i]) {
    //         lp[i] = hp[i] = i;
    //         for(int j = 2 * i; j < size; j += i) {
    //             isPrime[j] = false;
    //             hp[j] = i;
    //             if(lp[j] == 0) {
    //                 lp[j] = i;
    //             }
    //         }
    //     }
    // }

    while(t--) {
        solve();
    }
}
