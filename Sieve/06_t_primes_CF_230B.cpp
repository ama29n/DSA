#include <bits/stdc++.h>
using namespace std;

// It can be shown that only squares of prime numbers are T-primes, and that there are not too many of them — 
// as many as there are prime numbers not greater than . Precompute these numbers (using, for example, 
// the sieve of Eratosthenes) and store them in an array or an std::set, then we can answer each query by simply 
// checking whether the number in question is amongst the precomputed numbers.

#define ll long long
const int size = 1e6 + 3;
vector<bool> isPrime(size, true);
unordered_set<ll> s;

void solve() {
    ll n;
    cin >> n;
    if(n == 1) {
        cout << "NO" << endl;
        return;
    }
    if(s.find(n) != s.end()) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;

    for(int i = 2; i < size; i++) {
        if(isPrime[i]) {
            s.insert((ll)i * (ll)i);
            for(int j = 2 * i; j < size; j += i)
                isPrime[j] = false;
        }
    }

    while(t--) {
        solve();
    }
}