#include <bits/stdc++.h>
using namespace std;

#define size 1e7 + 9

int main() {
    vector<bool> isPrime(size, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < size; i++) {
        if(isPrime[i]) {
            for(int j = 2 * i; j < size; j += i)
                isPrime[j] = false;
        }
    }
    for(int i = 2; i < 30; i++) 
        cout << i << " " << isPrime[i] << endl;
}

// Time - O(n * log(log(n)))

// n for outer loop

// now inner loops 
// runs - n / 2 + n / 3 + n / 4 ... = n (1 + 1 / 2 + 1/ 3 ...)
// Now, this is log n 
// but due to if condition it doesn't runs for all values 
// hence the value becomes log(log(n))