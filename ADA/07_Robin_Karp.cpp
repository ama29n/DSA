#include <bits/stdc++.h>
using namespace std;

// d is radix and q is modulus
void robin_karp(string text, string pattern, int d, int q) {
    int n = text.size(), m = pattern.size();
    int t = 0, p = 0; // hash value of text and pattern
    int h = 1; // h = pow(d, m - 1) % q;
    for(int i = 1; i <= m - 1; i++) {
        h = (h * d) % q;
    }
    // Hash value for pattern and 1st window of text
    for(int i = 0; i < m; i++) {
        t = (t * d + text[i]) % q;
        p = (p * d + pattern[i]) % q;
    }
    // Rolling over text
    for(int i = 0; i < n - m + 1; i++) {
        // If hash values match
        if(t == p) {
            int j;
            for(j = 0; j < m; j++) {
                if(text[i + j] != pattern[j]) {
                    break;
                }
            }
            if(j == m) {
                cout << "Pattern found at index: " << i << endl;
            }
        }
        // Rehash for next window
        t = (d * (t - (h * text[i])) + text[i + m]) % q;
        if(t < 0) {
            t += q;
        }
    }
}

int main() {
    string text = "This is a test string";
    string pattern = "test";
    robin_karp(text, pattern, 256, INT_MAX); 
}

