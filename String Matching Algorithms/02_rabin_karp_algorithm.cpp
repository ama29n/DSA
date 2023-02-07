#include <bits/stdc++.h>
using namespace std;

// 'd' is radix & 'q' is modulus
void rabin_karp(string text, string pattern, int d, int q) {
    int n = text.size();
    int m = pattern.size();
    int p = 0;                                        // hash value of pattern
    int t = 0;                                        // hash value of text

    int h = 1;                                        // value of h would be -> pow(d, m - 1) % q
    for(int i = 1; i <= m - 1; i++) {
        h = (h * d) % q;
    }

    for(int i = 0; i < m; i++) {                      // calculate hash value of pattern and fist window of text
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for(int i = 0; i < n - m + 1; i++) {               // slide the pattern over text 1 by 1 
        if(p == t) {                                   // if hash values match then only match the string
            int j;
            for(j = 0; j < m; j++) {
                if(pattern[j] != text[i + j]) {
                    break;
                }
            }
            if(j == m) {
                cout << "Pattern found at " << i << "th index" << endl;
            }
        }
        
        t = (d * (t - text[i] * h) + text[i + m]) % q;  // calculte hash value of next window

        if(t < 0) {
            t += q;
        }
    }
}

int main() {
    string text = "This is a test string";
    string pattern = "test";
    rabin_karp(text, pattern, 256, INT_MAX); 
}