#include <bits/stdc++.h>
using namespace std;

#define size 1e7 + 9

// Time - O(n * log(log(n)))
int main() {
    vector<bool> isPrime(size, true);
    vector<int> hp(size, 0);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < size; i++) {
        if(isPrime[i]) {
            hp[i] = i;
            for(int j = 2 * i; j < size; j += i) {
                isPrime[j] = false;
                hp[j] = i;
            }
        }
    }

    // Prime factors of a number
    int num;
    cin >> num;

    vector<int> v;
    while(num > 1) {
        int prime_factor = hp[num];
        while(num % prime_factor == 0) {
            num /= prime_factor;
            v.push_back(prime_factor);
        }
    }
    for(auto it : v) {
        cout << it << " ";
    }
}

// The above code works well for n upto the order of 10^7. Beyond this we will face memory issues.
// Time - O(1)
// Once the seive is created we don't need to calculate it again



// Another Approach
void primeFactors(int n) {
    int c = 2;
    while(n > 1) {
        if(n % c == 0) {
            cout << c << " ";
            n /= c;
        }
        else
            c++;
    }
}

// This Approach is best for all composite numbers and achieves O(log n) but is O(n) otherwise.



// if x = a ^ n1 * b ^ n2 * c ^ n3 

// then total number of divisors = (n1 + 1) * (n2 + 1) * (n3 + 1)

// total sum of divisors = (a ^ (n1 + 1) - 1 / a - 1) * (b ^ (n2 + 1) - 1 / b - 1) * (c ^ (n3 + 1) - 1 / c - 1)