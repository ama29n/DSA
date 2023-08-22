#include <bits/stdc++.h>
using namespace std;

void naive_string_matching(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    for(int i = 0; i < n - m + 1; i++) {
        if(text[i] == pattern[0]) {
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
    }
}

int main() {
    string text = "This is a test string";
    string pattern = "test";
    naive_string_matching(text, pattern); 
}