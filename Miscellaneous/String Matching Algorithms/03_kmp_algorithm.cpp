#include <bits/stdc++.h>
using namespace std;

vector<int> find_lps(string pattern) {
    int n = pattern.size();
    vector<int> lps(n);
    lps[0] = -1;
    int q = -1;
    for(int i = 1; i < n; i++) {
        while(q > -1 && pattern[q + 1] != pattern[i]) {
            q = lps[q];
        }
        if(pattern[q + 1] == pattern[i]) {
            q += 1;
        }
        lps[i] = q;
    }
    return lps;
}

void kmp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = find_lps(pattern);              // {-1, 0, 1, 2}
    int q = -1;                                       // For storing count of characters matched
    for(int i = 0; i < n; i++) {
        while(q > -1 && pattern[q + 1] != text[i]) {  // If next character didnot match
            q = lps[q];
        }
        if(pattern[q + 1] == text[i]) {               // If the next character matches 
            q += 1;
        }
        if(q == m - 1) {                              // Pattern found
            cout << "Pattern occurs at index: " << i - m + 1 << endl;
            q = lps[q];
        }
    }
}

int main() {
    string text = "AAAAABAAABA";
    string pattern = "AAAA";
    kmp(text, pattern); 
}