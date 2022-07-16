#include <bits/stdc++.h>
using namespace std;

// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
// Given an integer n, return true if n is an ugly number.

// Approach 1 using sieve
bool isUgly(int n) {
    if(n < 1)
        return false;
    if(n == 1)
        return true;
    vector<int> hp(n + 1, 0);
    for(int i = 2; i <= n; i++) {
        if(!hp[i]) {
            hp[i] = i;
            for(int j = 2 * i; j <= n; j += i) {
                hp[j] = i;
            }
        }
    }
    vector<int> v;
    int m = n;
    while(m > 1) {
        int prime_factor = hp[m];
        v.push_back(prime_factor);
        m /= prime_factor;
    }
    for(auto it : v)
        if(it != 2 && it != 3 && it != 5)
            return false;
    return true;
}

// Approach 2 
bool isUgly(int n) {
    if(n < 1)
        return false;
    while(n % 3 == 0)
        n = n / 3;
    while(n % 2 == 0)
        n = n / 2;
    while(n % 5 == 0)
        n = n / 5;
    if(n == 1)
        return true;
    return false;
}