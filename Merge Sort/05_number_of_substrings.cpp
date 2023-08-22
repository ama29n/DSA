#include <bits/stdc++.h>
using namespace std;

const int mod = 1E9 + 7; const string yes = "YES", no = "NO"; typedef long long ll;

#define forn(i, s, n)    for(int i = s; i < n; i++)
#define all(v)           v.begin(), v.end()
#define sp               << ' ' <<
#define nl               << '\n'

// https://www.codingninjas.com/studio/library/count-of-all-substrings-in-a-binary-string-in-which-count-of-1-s-is-strictly-more-than-the-count-of-0-s 

void merge(int l, int m, int r, vector<int> &arr) {
    int n = r - l + 1;
    vector<int> v(n);
    int i = l, j = m + 1, k = 0;
    while(k < n) {
        int x = i <= m ? arr[i] : INT_MAX;
        int y = j <= r ? arr[j] : INT_MAX;
        v[k++] = x <= y ? arr[i++] : arr[j++]; 
    }
    for(int idx = 0; idx < n; idx++) {
        arr[l + idx] = v[idx];
    }
}

ll mergeSort(int l, int r, vector<int> &v) {
    if(l >= r) return 0;
    int m = (l + r) / 2;
    ll ans = mergeSort(l, m, v) + mergeSort(m + 1, r, v);
    int i = l, j = m + 1;
    while(i <= m && j <= r) {
        if(v[i] > v[j]) {
            ans += m - i + 1;
            j++;
        } else { i++; }
    }
    merge(l, m, r, v);
    return ans;
}

void solve() {
    string x; cin >> x;
    int n = x.size();
    ll ans = 0;
    vector<int> v(n, 1);
    for(int i = 0; i < n; i++) {
        if(x[i] == '0') v[i] = -1;
    }
    vector<int> pre(n); pre[0] = v[0];
    for(int i = 1; i < n; i++) pre[i] = pre[i - 1] + v[i];
    int cnt = 0;
    // Substrings which are valid starting from 0
    for (int i = 0; i < n; i++) {
        if (pre[i] > 0)
            cnt++;
    }
    // Reverse is done so as to calculate inverse pairs
    reverse(pre.begin(), pre.end());
    cout << cnt + mergeSort(0, n - 1, pre) nl;
}

int main() {
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
}

// 7
// 1010
// 1110
// 0110011000
// 0000110000
// 1001011100
// 0010000000
// 1011011111

// Segment Tree 

vector<int> tree;
 
void update(int low, int high, int i, int node) {
   if (low == high) {
       tree[i] += 1;
       return;
   }
   int mid = low + (high - low) / 2;
   if (node <= mid) {
        update(low, mid, 2 * i + 1, node);
   }
   else {
        update(mid + 1, high, 2 * i + 2, node);
   }
   tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
 
int query(int low, int high, int i, int l, int r) {
   if (high < l || low > r) {
       return 0;
   }
   if (low >= l && high <= r) {
       return tree[i];
   }
   int mid = low + (high - low) / 2;
   int L = query(low, mid, 2 * i + 1, l, r);
   int R = query(mid + 1, high, 2 * i + 2, l, r);
   return L + R;
}

void solve() {
    string x; cin >> x;
    int n = x.size();
    tree = vector<int> ((4 * 2 * n) + 1, 0);
    ll currSum = 0, cnt = 0;
    // prefix[j] - prefix[i] >= 1
    // prefix[i] <= prefix[j] - 1
    for (int i = 0; i < n; i++) {
       currSum += (x[i] == '1' ? 1 : -1);
       if(currSum > 0) {
          cnt++;
       }
       int lessThan = (currSum + n) - 1;
       int q = query(0, 2 * n, 0, 0, lessThan); 
       cnt += q;
       update(0, 2 * n, 0, currSum + n);
    }
    cout << cnt nl;
}