#include <bits/stdc++.h>
using namespace std;

#define size 1e7 + 9

int main() {
    vector<bool> isPrime(size, true);
    vector<int> hp(size, 0), lp(size, 0);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < size; i++) {
        if(isPrime[i]) {
            // If a number is prime itself, it's hp and lp is the number itself
            lp[i] = hp[i] = i;
            for(int j = 2 * i; j < size; j += i) {
                isPrime[j] = false;
                hp[j] = i;
                if(lp[j] == 0) {
                    lp[j] = i;
                }
            }
        }
    }

    for(int i = 2; i < 20; i++)
        cout << i << ", lp: " << lp[i] << ", hp: " << hp[i] << endl;
}

// 2, lp: 2, hp: 2
// 3, lp: 3, hp: 3
// 4, lp: 2, hp: 2
// 5, lp: 5, hp: 5
// 6, lp: 2, hp: 3
// 7, lp: 7, hp: 7
// 8, lp: 2, hp: 2
// 9, lp: 3, hp: 3
// 10, lp: 2, hp: 5
// 11, lp: 11, hp: 11
// 12, lp: 2, hp: 3
// 13, lp: 13, hp: 13
// 14, lp: 2, hp: 7
// 15, lp: 3, hp: 5
// 16, lp: 2, hp: 2
// 17, lp: 17, hp: 17
// 18, lp: 2, hp: 3
// 19, lp: 19, hp: 19
