#include <bits/stdc++.h>
using namespace std;

const int mod = 1E9 + 7; const string yes = "YES", no = "NO"; typedef long long ll;

vector<int> Factors (int n) { 
    vector<int> ans; 
    for(int i = 1; i * i <= n; i++) { 
        if(n % i == 0) { 
            ans.push_back(i); 
            if((n / i) != i) 
                ans.push_back(n / i); 
        } 
    }
    return ans;
}
bool is_prime (int n) { 
    if(n <= 1) return false; 
    for(int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false; 
    return true; 
}
bool diff_parity (ll num1, ll num2) { 
    return (num1 & 1) != (num2 & 1); 
}
ll gcd (ll x, ll y) { 
    if(!x || !y) return x + y; 
    return x % y == 0 ? y : gcd(y, x % y); 
}
ll lcm (ll x, ll y) { 
    return x * (y / gcd(x, y)); 
}

#define forn(i, s, n)    for(int i = s; i < n; i++)
#define mem(a, i)        memset(a, i, sizeof(a))
#define pb               push_back
#define all(v)           v.begin(), v.end()
#define rall(v)          v.rbegin(), v.rend()
#define ff               first
#define ss               second
#define AND(a, b)        ((a) & (b))
#define OR(a, b)         ((a) | (b))
#define XOR(a, b)        ((a) ^ (b))
#define sp               << ' ' <<
#define nl               << '\n'
#define endl             '\n'

// Policy Based Data Structure
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


// Custom Hash
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


// DSU
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


// Tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Segment Tree
class SegmentTree {
public:
    int maxN;
    vector<int> seg;
    SegmentTree(int n) : maxN(n) {
        seg = vector<int> (maxN * 4, 0);
    }
    void build(vector<int>& arr) {
        build_util(0, 0, maxN - 1, arr);
    }
    void build_util(int i, int low, int high, vector<int>& arr) {
        if(low == high) {
            seg[i] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build_util(i * 2 + 1, low, mid, arr);
        build_util(i * 2 + 2, mid + 1, high, arr);
        seg[i] = max(seg[i * 2 + 1], seg[i * 2 + 2]);
    }
    int query(int l, int r) {
        return query_util(0, 0, maxN - 1, l, r);   
    }
    int query_util(int i, int low, int high, int l, int r) {
        if(low >= l && high <= r)
            return seg[i];
        if(low > r || high < l)
            return INT_MIN;
        int mid = (low + high) / 2;
        int left = query_util(2 * i + 1, low, mid, l, r);
        int right = query_util(2 * i + 2, mid + 1, high, l, r);
        return max(left, right);
    }
    void update(int len, int ele) {
        update_util(0, 0, maxN - 1, ele, len);
    }
    void update_util(int i, int low, int high, int ele, int len) {
        if(high == low) {
            seg[i] = len;
            return;
        }
        int mid = (low + high) / 2;
        if(ele <= mid) {
            update_util(2 * i + 1, low, mid, ele, len);
        } else {
            update_util(2 * i + 2, mid + 1, high, ele, len);
        }
        seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
    }
};


/*.....................................................................*/

void solve() {
    int n; 
    cin >> n;
    vector<int> v(n);
    forn(i, 0, n) {
        cin >> v[i];
    }
}

/*.....................................................................*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    int size = 1e5 + 1;
    vector<bool> isPrime(size, true);
    vector<int> hp(size, 0), lp(size, 0);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < size; i++) {
        if(isPrime[i]) {
            lp[i] = hp[i] = i;
            for(int j = 2 * i; j < size; j += i) {
                isPrime[j] = false;
                hp[j] = i;
                if(lp[j] == 0) {
                    lp[j] = i; 
    }   }   }   }
    while(t--) {
        solve();
    }
}