#include <bits/stdc++.h>
using namespace std;

// GCD - Greatest Common Divisor
// LCM = Least common Multiple 

// for 2 numbers a and b,
// a * b / gcd = lcm

// gcd using euclid's algorithm

// Time complexity log n

int gcd(int divisor, int dividend) {
    if(divisor == 0)
        return dividend;
    return gcd(dividend % divisor, divisor);
}

int main() {
    cout << gcd(12, 18) << endl;
    cout << gcd(18, 12) << endl;
    cout << gcd(4, 2) << endl;
    cout << gcd(1, 18) << endl;
}

// Application

// 1. Smallest Fraction
// a / b = a / gcd(a, b)    /    b / gcd(a, b);