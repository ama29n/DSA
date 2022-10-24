#include<bits/stdc++.h>
using namespace std;

// For explanation
// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count_a_+_b_+_c_subsequences/topic

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int a = 0, ab = 0, abc = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            a = 2 * a + 1;
        } else if(s[i] == 'b') {
            ab = 2 * ab + a;
        } else if(s[i] == 'c') {
            abc = 2 * abc + ab;
        }
    }
    cout << abc;
}